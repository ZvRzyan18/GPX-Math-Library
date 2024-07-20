/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MathUtils.hpp
*/

#ifndef GPX_MATH_UTILS_H
#define GPX_MATH_UTILS_H

#include "gpx_cpp/math/Matrix.hpp"
#include "gpx_cpp/math/Vector.hpp"
#include "gpx_cpp/math/Quaternion.hpp"

namespace GPX {
	
/*
 math constants
*/
extern const float EPSILON;
extern const float PI_2; // π * 2
extern const float PI_RAD; // π / 180
extern const float INV_PI_RAD; // 1 / (PI_RAD)
extern const float PI; // π
extern const float PI_HALF; // π * 0.5

/*
 matrix projection
*/
void Frustum(GPX::Matrix4x4& m, float left, float right, float bottom, float top, float near, float far);
void Ortho(GPX::Matrix4x4& m, float left, float right, float bottom, float top, float near, float far);

void Perspective(GPX::Matrix4x4& m, float aspect, float fov, float near, float far);
void Ortho(GPX::Matrix3x3& m, float left, float right, float bottom, float top, float near, float far);

void Project(GPX::Vector3& v, GPX::Vector3 in, GPX::Matrix4x4 model, GPX::Matrix4x4 project, int viewport[4]);
void UnProject(GPX::Vector3& v, GPX::Vector3 in, GPX::Matrix4x4 model, GPX::Matrix4x4 project, int viewport[4]);


/*
 mod
*/
float Mod(float a, float b);

/*
 min and max
*/
float Min(float a, float b);
float Max(float a, float b);

/*
 absolute value
*/
float Abs(float x);
GPX::Vector2 Abs(GPX::Vector2 vec);
GPX::Vector3 Abs(GPX::Vector3 vec);
GPX::Vector4 Abs(GPX::Vector4 vec);

/*
 clamp
*/
float Clamp(float x, float min, float max);
GPX::Vector2 Clamp(GPX::Vector2 vec, GPX::Vector2 min, GPX::Vector2 max);
GPX::Vector3 Clamp(GPX::Vector3 vec, GPX::Vector3 min, GPX::Vector3 max);
GPX::Vector4 Clamp(GPX::Vector4 vec, GPX::Vector4 min, GPX::Vector4 max);

/*
 printable 
*/
void Print(GPX::Matrix3x3 m);
void Print(GPX::Matrix4x4 m);
void Print(GPX::Quaternion q);
void Print(GPX::Vector2 v);
void Print(GPX::Vector3 v);
void Print(GPX::Vector4 v);
}

#endif
