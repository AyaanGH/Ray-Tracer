#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Ray.h"


void write_colour(std::ostream &out, Colour pixel_colour) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_colour.x) << ' '
        << static_cast<int>(255.999 * pixel_colour.y) << ' '
        << static_cast<int>(255.999 * pixel_colour.z ) << '\n';
}


Colour ray_colour(const Ray& r) {
    Vec3 unit_direction = Vec3::unit_vector(r.direction);
    float t = 0.5 * (unit_direction.y + 1.0);
    return Colour(1.0, 1.0, 1.0)*(1.0-t) + Colour(0.5, 0.7, 1.0) *t;
}


int main() {


    //Image metadata

    const float aspect_ratio = 16.0f / 9.0f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    //Camera metadata
    Point3 camera_origin(0, 0, 0);
    float focal_length = 1.0; //Distance from eye to viewport

    //Viewport metadata
    float viewport_height = 2.0; // range from -1 to 1
    float viewport_width = aspect_ratio * viewport_height;

    Vec3 horizontal_vector = Vec3(viewport_width, 0, 0);
    Vec3 vertical_vector = Vec3(0, viewport_height, 0);
    Point3 lower_left_corner = camera_origin - horizontal_vector / 2 - vertical_vector / 2 - Vec3(0, 0, focal_length);

    std::cout <<" 1";




    //Output PPM file format
    std::ofstream image("raytrace.ppm");


    //Required metadata for the .ppm image format
    image << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int y = 0; y < image_height; ++y) {
        std::cerr << "\rLines rendered: " << y << ' ' << std::flush;
        for (int x = 0; x < image_width; ++x) {

            int r = x;
            int g = y;
            int b = x * y % 256;

            float percent_x = float(y) / (image_width - 1);
            float percent_y = float(x) / (image_height - 1);

//            Colour pixel_colour(percent_x, percent_y, 0.25);

            Ray camera_ray(camera_origin,lower_left_corner - camera_origin + horizontal_vector * percent_x + horizontal_vector * percent_y);
            Colour pixel_colour = ray_colour(camera_ray);
            write_colour(image, pixel_colour);


        }

    }


    return 0;
}

