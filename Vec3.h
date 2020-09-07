#ifndef RAY_FloatRACER_VEC3_H
#define RAY_FloatRACER_VEC3_H

#include <cmath>

class Vec3 {


public:

    float x,y,z;

    Vec3(float x, float y, float z);

    float magnitude();

    float dot(const Vec3 &a , const  Vec3 &b);

    float cross();

    float length();

    float length_squared() const;



    //TODO transfer overloads to outside of class definition
    Vec3 operator+(const Vec3& other) const;

    Vec3 operator-(const Vec3& other) const;


    Vec3 operator*(const Vec3& other) const;

    Vec3 operator*(float other) const;

    Vec3 operator/(float other) const;

    static Vec3 unit_vector(Vec3 V);

};


using Point3 = Vec3;
using Colour = Vec3;




#endif //RAY_FloatRACER_VEC3_H
