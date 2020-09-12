cmake_minimum_required(VERSION 3.17)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ray_tracer
        main.cpp Vec3.cpp Vec3.h Ray.cpp Ray.h Entity.cpp Entity.h Sphere.cpp Sphere.h)
