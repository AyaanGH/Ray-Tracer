#include "Vec3.h"
#include "cmath"
#include "utility.h"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

double Vec3::magnitude() {
    return std::sqrt(pow(x,2) + pow(y,2) + pow(z,2)) ;
}

Vec3 Vec3::operator+(const Vec3 &other) const {
    return Vec3(x+ other.x, y+ other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3 &other) const {
    return Vec3(x- other.x, y- other.y, z - other.z);

}

Vec3 Vec3::operator*(double other) const {
    return Vec3(x* other, y * other, z * other);
}

Vec3 Vec3::operator*(const Vec3 &other) const {
    return Vec3(x * other.x, y * other.y, z * other.z);
}

double Vec3::length_squared() const {
    return std::pow(x,2) + std::pow(y,2) + std::pow(z,2);
}

double Vec3::length() const {
    return std::sqrt(length_squared());
}

double Vec3::dot(const Vec3 &a, const Vec3 &b) {
    return  (a.x*b.x) + ( a.y * b.y) + (a.z * b.z);
}

Vec3 Vec3::operator/( double other) const {
    return *this* (1/other);
}

Vec3 Vec3::unit_vector(Vec3 V) {
    return V/V.length();
}

Vec3::Vec3() {
    x= 0;
    y=0;
    z=0;

}

Vec3 Vec3::vec_random() {
    return Vec3(random_double(),random_double(),random_double());
}

Vec3 Vec3::vec_random(double min, double max) {
    return Vec3(random_double(min,max),random_double(min,max),random_double(min,max));
}

Vec3 Vec3::random_in_unit_sphere() {
    while (true)
    {
        Vec3 p = Vec3::vec_random(-1, 1);
        if (p.length_squared() >=1)
        {
            continue;

        }

        return p;


    }
}



