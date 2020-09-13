#ifndef RAY_TRACER_ENTITY_H
#define RAY_TRACER_ENTITY_H

#include "../utility/Ray.h"


struct hit_record {
    Point3 point;
    Vec3 normal;
    double t;

    bool front_face;

    void set_face_normal(const Ray &r, const Vec3 &outward_normal) {
        front_face = Vec3::dot(r.direction, outward_normal) < 0;
        normal = front_face ? outward_normal : outward_normal * -1;  // Possible place of bug
    }

};

class Entity {
public:
    virtual bool intersect(const Ray &r, double t_min, double t_max, hit_record &record) const = 0;
};


#endif //RAY_TRACER_ENTITY_H
