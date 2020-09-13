#include "Ray.h"

Ray::Ray(const Point3 &origin, const Vec3 &direction) : origin(origin), direction(direction) {}

Point3 Ray::point_on_ray(double distance) const {

    //Equation of a ray
    return  direction * distance + origin;
}
