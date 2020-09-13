#include "Sphere.h"

Sphere::Sphere(const Point3 &sphereCentre, double radius) : sphere_centre(sphereCentre), radius(radius) {}


bool Sphere::intersect(const Ray &r, double t_min, double t_max, hit_record &record) const {

    const Vec3 oc = r.origin - sphere_centre;

    double a = Vec3::dot(r.direction, r.direction);
    double b = 2.0 * Vec3::dot(r.direction, oc);
    double c = Vec3::dot(oc, oc) - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    } else {


        double small_root =  (-b - std::sqrt(discriminant)) / (2.0 * a);

        if(small_root < t_max && small_root > t_min)
        {
            record.t = small_root;
            record.point = r.point_on_ray(small_root);
//            record.normal = (record.point-sphere_centre) / radius;

            Vec3 outward_normal = (record.point - sphere_centre) / radius;
            record.set_face_normal(r, outward_normal);
            return true;

        }


        double large_root =  (-b + std::sqrt(discriminant)) / (2.0 * a);

        if(large_root < t_max && large_root > t_min) {
            record.t = large_root;
            record.point = r.point_on_ray(large_root);
//            record.normal = (record.point-sphere_centre) / radius;
            Vec3 outward_normal = (record.point - sphere_centre) / radius;
            record.set_face_normal(r, outward_normal);
            return true;


        }
    }


}
