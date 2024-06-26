#pragma once

#include "tuple.h"
#include "matrix.h"
#include "ray.h"
#include "material.h"

#include <vector>
#include <random> 
#include <string>


// Chapter 9: Shapes and Planes
class Shape {
    protected:
        Matrix transformation;
        Material material;
    public:
        // Methods
        Shape(Matrix t = identity_matrix(4), Material m = Material());
        Shape(Matrix t) : Shape(t, Material()) {};
        Shape(Material m) : Shape(identity_matrix(4), m) {};
        Shape copy();
        Matrix get_transform();
        void set_transform(Matrix m);
        Material get_material();
        void set_material(Material m);
        Intersections intersect(Ray r);
        Intersections local_intersect(Ray r);
        Tuple normal_at(float x, float y, float z);
        Tuple normal_at(Tuple p);
        std::string to_string();
};
