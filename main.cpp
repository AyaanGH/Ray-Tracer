#include <iostream>
#include <fstream>
#include "Vec3.h"
int main()
{


    //Output PPM file format

    const int image_height = 256;
    const  int image_width = 256;

    std::ofstream image ("raytrace.ppm");

    //Required metadata for the .ppm image format
    image << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int y = 0; y < image_height ; ++y) {
        std::cerr << "\rLines rendered: " << y << ' ' << std::flush;
        for (int x = 0; x < image_width; ++x) {

            int r = x;
            int g = y;
            int b = x*y % 256;

            image << r <<" " << g << " "  << b << std::endl;


        }

    }



    return 0;
}

