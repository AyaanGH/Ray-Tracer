#ifndef RAY_FloatRACER_VEC3_H
#define RAY_FloatRACER_VEC3_H

#include <cmath>

class Vec3 {

    float x,y,z;

public:


    Vec3(float x, float y, float z);

    float magnitude();

    float dot(const Vec3 &a , const  Vec3 &b);

    float cross();

    float length();

    float length_squared() const;


   

    Vec3 operator+(const Vec3& other) const;

    Vec3 operator-(const Vec3& other) const;

    Vec3 operator*(float other) const;

    Vec3 operator*(const Vec3& other) const;



};






#endif //RAY_FloatRACER_VEC3_H
