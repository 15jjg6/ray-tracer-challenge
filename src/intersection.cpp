#include <vector>
#include "intersection.h"


Intersection::Intersection(float t, Sphere obj) {
    this->t = t;
    this->object = obj;
};

Intersections::Intersections(std::vector<Intersection> data) {
    this->data = data;
};
