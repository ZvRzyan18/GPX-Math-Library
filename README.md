# GPX-Math-Library

Simple and lightweight Math Library for graphics programming.


# Source And Header Files

Header Files
```
 include/gpx_cpp/math/MathUtils.hpp
 include/gpx_cpp/math/Matrix.hpp
 include/gpx_cpp/math/Quaternion.hpp
 include/gpx_cpp/math/Sqrt.hpp
 include/gpx_cpp/math/Trigonometry.hpp
 include/gpx_cpp/math/Vector.hpp
```
Source Files
```
 include/gpx_cpp/math/MathUtils.cpp
 include/gpx_cpp/math/Matrix.cpp
 include/gpx_cpp/math/Quaternion.cpp
 include/gpx_cpp/math/Sqrt.cpp
 include/gpx_cpp/math/Trigonometry.cpp
 include/gpx_cpp/math/Vector.cpp
```

# Build And Linking 

run command to build static and dynamic linkable file "GPX_Math_Static", "GPX_Math_Dynamic"
```
 cmake /project/directory
 make
```
or
```
 cmake .. && make
```
linking library
```cmake
 add_subdirectory(/project/directory)
 
 include_directories(...
    /project/directory/include
    )
 
 target_link_libraries(your_project GPX_Math_Static)
 #or
 target_link_libraries(your_project GPX_Math_Dynamic)

```

