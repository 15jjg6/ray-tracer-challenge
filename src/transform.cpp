#include "tuple.h"
#include "matrix.h"
#include "transform.h"
#include <vector>
#include <string>
#include <cmath>


// Chapter 4: Matrix Transformations
// Transformations
Matrix translation(float x, float y, float z) {
    std::vector<float> translation_data = {1, 0, 0, x,
                                           0, 1, 0, y,
                                           0, 0, 1, z,
                                           0, 0, 0, 1};
    return Matrix(4, 4, translation_data);
};

Matrix scaling(float x, float y, float z) {
    std::vector<float> scaling_data = {x, 0, 0, 0,
                                           0, y, 0, 0,
                                           0, 0, z, 0,
                                           0, 0, 0, 1};
    return Matrix(4, 4, scaling_data);
};

Matrix rotation_x(float radians) {
    std::vector<float> rotate_data = {1, 0, 0, 0,
                                      0, std::cos(radians), -std::sin(radians), 0,
                                      0, std::sin(radians), std::cos(radians), 0,
                                      0, 0, 0, 1};
    return Matrix(4, 4, rotate_data);
};
Matrix rotation_y(float radians) {
    std::vector<float> rotate_data = {std::cos(radians), 0, std::sin(radians), 0,
                                      0, 1, 0, 0,
                                      -std::sin(radians), 0, std::cos(radians), 0,
                                      0, 0, 0, 1};
    return Matrix(4, 4, rotate_data);
};
Matrix rotation_z(float radians) {
    std::vector<float> rotate_data = {std::cos(radians), -std::sin(radians), 0, 0,
                                      std::sin(radians), std::cos(radians), 0, 0,
                                      0,  0, 0, 0,
                                      0, 0, 0, 1};
    return Matrix(4, 4, rotate_data);
};
Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);
