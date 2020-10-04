cmake_minimum_required(VERSION 3.17)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 17)

#TODO Add multithreading flag

add_executable(Ray_tracer
        main.cpp utility/Vec3.cpp utility/Vec3.h utility/Ray.cpp utility/Ray.h shapes/Entity.cpp shapes/Entity.h shapes/Sphere.cpp shapes/Sphere.h shapes/Entity_list.cpp shapes/Entity_list.h utility/utility.h utility/Camera.h utility/utility.cpp utility/Thread_pool.cpp utility/Thread_pool.h)
