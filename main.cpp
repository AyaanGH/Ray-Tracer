#include <iostream>
#include <fstream>
#include "utility/Vec3.h"
#include "utility/Ray.h"
#include "shapes/Entity_list.h"
#include "shapes/Sphere.h"
#include "utility/utility.h"


void write_colour(std::ostream &out, Colour pixel_colour) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_colour.x) << ' '
        << static_cast<int>(255.999 * pixel_colour.y) << ' '
        << static_cast<int>(255.999 * pixel_colour.z ) << '\n';
}


double hit_sphere(const Point3 sphere_centre, double radius, const Ray &r) {
    //Quadratic formula to find root

    const Vec3 oc = r.origin - sphere_centre;

    double a = Vec3::dot(r.direction, r.direction);
    double b = 2.0 * Vec3::dot(r.direction, oc);
    double c = Vec3::dot(oc, oc) - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant)) / (2.0 * a);
    }


}

Colour ray_colour(const Ray &r, const Entity& world)
{

    hit_record record;

    if(world.intersect(r,0,infinity,record))
    {
        return  (record.normal + Colour(1,1,1)) *0.5;
    }


    Vec3 unit_direction = Vec3::unit_vector(r.direction);
    double t = 0.5*(unit_direction.y + 1.0);
    return Colour(1.0, 1.0, 1.0) * (1.0-t) + Colour(0.5, 0.7, 1.0) *t;




//    if (t > 0.0) {
//        Point3 normal = Vec3::unit_vector(r.point_on_ray(t) - Vec3(0, 0, -1));
//
//        return (Colour(normal.x + 1, normal.y + 1, normal.z + 1) * 0.5);
//    }
//
//    Vec3 unit_direction = Vec3::unit_vector(r.direction);
//    t = 0.5 * (unit_direction.y + 1.0);
//    return Colour(1.0, 1.0, 1.0) * (1.0 - t) + Colour(0.5, 0.7, 1.0) * t;
}


int main() {


    //Image metadata

    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    //Camera metadata
    Point3 camera_origin(0, 0, 0);
    double focal_length = 1.0; //Distance from eye to viewport

    //Viewport metadata
    double viewport_height = 2.0; // range from -1 to 1
    double viewport_width = aspect_ratio * viewport_height;

    Vec3 horizontal_vector = Vec3(viewport_width, 0, 0);
    Vec3 vertical_vector = Vec3(0, viewport_height, 0);
    Point3 lower_left_corner = camera_origin - horizontal_vector / 2 - vertical_vector / 2 - Vec3(0, 0, focal_length);


    //Scene

    Entity_list world;

    world.add(std::make_shared<Sphere>(Point3(0,0,-1),0.5));
    world.add(std::make_shared<Sphere>(Point3(0,-100.5,-1),100));








    //Output PPM file format
    std::ofstream image("raytrace.ppm");


    //Required metadata for the .ppm image format
    image << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int y = 0; y < image_height; ++y) {
        std::cerr << "\rLines rendered: " << y << ' ' << std::flush;
        for (int x = 0; x < image_width; ++x) {


            double percent_x = double(x) / (image_width - 1);
            double percent_y = double(y) / (image_height - 1);

            Ray camera_ray(camera_origin, lower_left_corner + horizontal_vector * percent_x +
                                          vertical_vector * percent_y - camera_origin);
            Colour pixel_colour = ray_colour(camera_ray,world);
            write_colour(image, pixel_colour);


        }

    }


    return 0;
}

