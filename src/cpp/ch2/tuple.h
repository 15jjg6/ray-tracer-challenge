#pragma once

// Chapter 1: Tuples, Vectors and Points
// Equality test
bool equalByEpsilon(float a, float b, float epsilon = 0.00001);

class Tuple {
    public:
        // Attributes
        float x;
        float y;
        float z;
        float w;
        // Methods
        // TODO: Learn why virtual_cannon.cpp fails to compile when your tuple
        // constructor doesn't have default values
        // Tuple(float x, float y, float z, float w);
        Tuple(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
        bool isPoint();
        bool isVector();
        float magnitude();
        Tuple normalize();
        float dot(Tuple b);
        Tuple cross(Tuple b);
};

// Functions to create tuples
Tuple point(float x, float y, float z);
// TODO: Fix error due to conflict in vector naming:
//  error: reference to ‘vector’ is ambiguous
Tuple vector_(float x, float y, float z);

// Arithmetic operators
bool operator==(Tuple lhs, Tuple rhs);
Tuple operator+(Tuple lhs, Tuple rhs);
Tuple operator-(Tuple tup);
Tuple operator-(Tuple lhs, Tuple rhs);
Tuple operator*(Tuple tup, float a);
Tuple operator*(float a, Tuple tup);
Tuple operator/(Tuple tup, float a);

// Chapter 2: Colors
class Color {
    public:
        // Attributes
        float red, green, blue;
        // Methods
        Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f);
};

// Arithmetic operators
bool operator==(Color lhs, Color rhs);
Color operator+(Color lhs, Color rhs);
Color operator-(Color lhs, Color rhs);
Color operator*(Color color, float a);
Color operator*(float a, Color color);
Color operator*(Color lhs, Color rhs);
