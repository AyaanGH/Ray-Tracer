#ifndef RAY_TRACER_ENTITY_H
#define RAY_TRACER_ENTITY_H

#include "Ray.h"


struct hit_record {
    Point3 point;
    Vec3 normal;
    double t;
};

class Entity {
public:
    virtual bool intersect(const Ray &r, double t_min, double t_max, hit_record &record) const = 0;
};


#endif //RAY_TRACER_ENTITY_H
