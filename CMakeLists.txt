cmake_minimum_required(VERSION 3.6.0)

project(GPX_MATH)

# -std=c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# src file
set(SOURCES 
 src/gpx_cpp/math/MathUtils.cpp
 src/gpx_cpp/math/Matrix.cpp
 src/gpx_cpp/math/Quaternion.cpp
 src/gpx_cpp/math/Sqrt.cpp
 src/gpx_cpp/math/Trigonometry.cpp
 src/gpx_cpp/math/Vector.cpp
 )

# static library
add_library(GPX_Math_Static STATIC ${SOURCES})

# dynamic library
add_library(GPX_Math_Dynamic SHARED ${SOURCES})
