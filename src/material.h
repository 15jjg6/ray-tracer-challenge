#pragma once

#include "tuple.h"
#include "lights.h"


class Material {
    public:
        Material(
            Color color = Color(1, 1, 1), 
            float ambient = 0.1,
            float diffuse = 0.9,
            float specular = 0.9,
            float shininess = 200.0
        );
        Color color;
        float ambient;
        float diffuse;
        float specular;
        float shininess;
        std::string to_string();
        Color lighting(
            PointLight light,
            Tuple position,
            Tuple eyev,
            Tuple normalv,
            bool in_shadow
        );
};

bool operator==(Material lhs, Material rhs);