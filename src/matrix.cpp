#include "tuple.h"
#include "matrix.h"
#include <vector>
#include <numeric>

#include <stdexcept>


// Chapter 3: Matrix Math
Matrix::Matrix(unsigned int rows, unsigned int columns, std::vector<float> data) {
    if (rows * columns != data.size()) {
        throw std::invalid_argument("rows * columns must equal the size of input data.");
    };
    rows_ = rows;
    columns_ = columns;
    data_ = data;
}

// Matrix(unsigned int rows, unsigned int columns, float data[]);
float Matrix::get_point(unsigned int row, unsigned int col) {
    return data_[row * columns_ + col];
};


std::vector<float> Matrix::get_row(unsigned int row) {
    int start_index = row * columns_;
    int end_index = start_index + columns_;
    return std::vector<float>(data_.begin() + start_index, data_.begin() + end_index);
};

std::vector<float> Matrix::get_column(unsigned int col) {
    std::vector<float> col_vector;
    for (int i=0;i<data_.size();i++) {
        if ((i % columns_) == col) {
            col_vector.push_back(data_[i]);
        };
    };
    return col_vector;
};


unsigned int Matrix::get_row_count() {
    return rows_;
};

unsigned int Matrix::get_column_count() {
    return columns_;
};

std::vector<float> Matrix::get_matrix_data() {
    std::vector<float> copy = data_;
    return copy;
};

// Arithmetic operator overloads
bool operator==(Matrix lhs, Matrix rhs) {
    if (lhs.get_row_count() != rhs.get_row_count() || lhs.get_column_count() != rhs.get_column_count()) {
        return false;
    };
    return lhs.get_matrix_data() == rhs.get_matrix_data();
};

bool operator!=(Matrix lhs, Matrix rhs) {
    return !operator==(lhs, rhs);
};

Matrix operator*(Matrix lhs, Matrix rhs) {
    unsigned int new_rows = lhs.get_row_count();
    unsigned int new_cols = rhs.get_column_count();
    std::vector<float> new_data;
    for (int i=0; i<new_rows; i++) {
        for (int j=0; j<new_cols; j++) {
            new_data.push_back(
                // TODO: Find if there's a better way to use this other than a static method.
                dot_product(lhs.get_row(i), rhs.get_column(j))
            );
        };
    };

    return Matrix(new_rows, new_cols, new_data);
};

float dot_product(std::vector<float> v1, std::vector<float> v2) {
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("Length of vector 1 does not match length of vector 2");
    };
    return std::inner_product(
        v1.begin(),
        v1.end(),
        v2.begin(),
        0
    );
};