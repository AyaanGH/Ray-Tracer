#ifndef RAY_TRACER_UTILITY_H
#define RAY_TRACER_UTILITY_H






#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

#include "Ray.h"
#include "Vec3.h"

//constants


const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

double degrees_to_radians(double degrees)
{
    return degrees*pi / 180.0;
}



#endif //RAY_TRACER_UTILITY_H
