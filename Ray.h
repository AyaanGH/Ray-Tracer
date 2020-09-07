#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H


#include "Vec3.h"

class Ray {


public:
    Vec3 direction;
    Point3 origin;

    Ray(const Point3 &origin, const Vec3 &direction);

    //Get point along vector given t

    Point3 point_on_ray(float distance);

};


#endif //RAY_TRACER_RAY_H
