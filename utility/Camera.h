#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H


#include "Vec3.h"
#include "Ray.h"

class Camera {

public:


    //Image metadata
   Camera() {
        const double aspect_ratio = 16.0 / 9.0;
        const int image_width = 400;
        const int image_height = static_cast<int>(image_width / aspect_ratio);

        //Camera metadata
        camera_origin = Point3 (0, 0, 0);
        double focal_length = 1.0; //Distance from eye to viewport

        //Viewport metadata
        double viewport_height = 2.0; // range from -1 to 1
        double viewport_width = aspect_ratio * viewport_height;

        horizontal_vector = Vec3(viewport_width, 0, 0);
        vertical_vector = Vec3(0, viewport_height, 0);
        lower_left_corner = camera_origin - horizontal_vector / 2 - vertical_vector / 2 - Vec3(0, 0, focal_length);
    }

    Ray get_ray(double percent_x, double percent_y)
    {
        return Ray(camera_origin, lower_left_corner + horizontal_vector * percent_x +
                                      vertical_vector * percent_y - camera_origin);
    }


private:
    Point3 camera_origin;
    Point3 lower_left_corner;
    Vec3 horizontal_vector;
    Vec3 vertical_vector;

};


#endif
