#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H


#include "Entity.h"
#include "Vec3.h"

class Sphere: public Entity {

public:

    Point3 sphere_centre;
    double radius;

    Sphere(const Point3 &sphere_centre, double radius);

    bool intersect(const Ray &r, double t_min, double t_max, hit_record &record) const override;


};


#endif //RAY_TRACER_SPHERE_H
