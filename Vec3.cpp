#include "Vec3.h"
#include "cmath"

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vec3::magnitude() {
    return std::sqrt(pow(x,2) + pow(y,2) + pow(z,2)) ;
}

Vec3 Vec3::operator+(const Vec3 &other) const {
    return Vec3(x+ other.x, y+ other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3 &other) const {
    return Vec3(x- other.x, y- other.y, z - other.z);

}

Vec3 Vec3::operator*(float other) const {
    return Vec3(x* other, y * other, z * other);
}

Vec3 Vec3::operator*(const Vec3 &other) const {
    return Vec3(x * other.x, y * other.y, z * other.z);
}

float Vec3::length_squared() const {
    return std::pow(x,2) + std::pow(y,2) + std::pow(z,2);
}

float Vec3::length() {
    return std::sqrt(length_squared());
}

float Vec3::dot(const Vec3 &a, const Vec3 &b) {
    return  a.x+b.x * a.y + b.y * a.z + b.z;
}

Vec3 Vec3::operator/( float other) const {
    return *this* (1/other);
}
