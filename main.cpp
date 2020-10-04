#include <iostream>
#include <fstream>
#include <chrono>
#include "utility/Vec3.h"
#include "utility/Ray.h"
#include "shapes/Entity_list.h"
#include "shapes/Sphere.h"
#include "utility/utility.h"
#include "utility/Camera.h"


void write_colour(std::ostream &out, Colour pixel_colour, int samples_per_pixel) {

    double r = pixel_colour.x;
    double g = pixel_colour.y;
    double b = pixel_colour.z;

    double scale = 1.0 / samples_per_pixel;

    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);


    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
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

Colour ray_colour(const Ray &r, const Entity &world, int depth) {
    if (depth <= 0)
        return Colour(0, 0, 0);
    hit_record record;

    if (world.intersect(r, 0.001, infinity, record)) {

        Point3 target = record.point + record.normal + Vec3::random_in_unit_sphere();

        return ray_colour(Ray(record.point, target - record.point), world, depth - 1) * 0.5;
    }


    Vec3 unit_direction = Vec3::unit_vector(r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return Colour(1.0, 1.0, 1.0) * (1.0 - t) + Colour(0.5, 0.7, 1.0) * t;


}


int main() {

    //Measure rendering time
    auto t1 = std::chrono::high_resolution_clock::now();

    //Image metadata
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;
    const int max_depth = 50;

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
    Camera camera;
    Entity_list world;

    world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    //Output PPM file format
    std::ofstream image("raytrace.ppm");
    
    //Required metadata for the .ppm image format
    image << "P3\n" << image_width << " " << image_height << "\n255\n";


    for (int y = image_height; y >= 0; --y) {
        std::cerr << "\rLines left to render: " << y << ' ' << std::flush;
        for (int x = 0; x < image_width; ++x) {

            Colour pixel_colour(0, 0, 0);

            for (int samples = 0; samples < samples_per_pixel; ++samples) {
                double percent_x = (x + random_double()) / (image_width - 1);
                double percent_y = (y + random_double()) / (image_height - 1);

                Ray r = camera.get_ray(percent_x, percent_y);
                pixel_colour = pixel_colour + ray_colour(r, world, max_depth);

            }

            write_colour(image, pixel_colour, samples_per_pixel);
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << "\n" << duration / 1e6 << " seconds" << "\n" << "Samples: " << samples_per_pixel << "\n"
              << "Resolution: " << image_width << " * " << image_height << std::endl;


    return 0;
}

