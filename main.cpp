#include <iostream>
#include <fstream>
#include "Vec3.h"

int main() {



    Vec3 myVec( 3,3,3);

    Vec3 newVec = myVec/3.0;

    std::cout << newVec.x << newVec.y <<newVec.z;

    //Image metadata

    const float aspect_ratio = 16.0f / 0.0f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    //Camera metadata
    Point3 camera_origin(0,0,0);
    float focal_length = 1.0; //Distance from eye to viewport

    //Viewport metadata
    float viewport_height = 2.0; // range from -1 to 1
    float viewport_width = aspect_ratio * viewport_height;

    Vec3 horizontal_vector = Vec3(viewport_width,0,0);
    Vec3 vertical_vector = Vec3(0,viewport_height,0);








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

            image << r << " " << g << " " << b << std::endl;


        }

    }


    return 0;
}

