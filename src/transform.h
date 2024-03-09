#pragma once

#include "tuple.h"
#include "matrix.h"
#include <vector>
#include <string>


// Chapter 4: Matrix Transformations
// Transformations
Matrix translation_matrix(float x, float y, float z);
Matrix scaling_matrix(float x, float y, float z);
Matrix rotation_x_matrix(float radians);
Matrix rotation_y_matrix(float radians);
Matrix rotation_z_matrix(float radians);
Matrix shearing_matrix(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);
