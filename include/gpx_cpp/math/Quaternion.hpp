/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Quaternion.hpp
*/

#ifndef GPX_QUATERNION_HPP
#define GPX_QUATERNION_HPP

#include "gpx_cpp/math/Matrix.hpp"

namespace GPX {

 class Quaternion {
 	public:
 	 float W, X, Y, Z;
 	 
 	Quaternion();
 	Quaternion(float w, float x, float y, float z);
 	Quaternion(float* array);
 	
 	Quaternion operator*(Quaternion q);
 	Quaternion& operator*=(Quaternion q);
 	
 	float& operator[](int index);
 	
 	int GetSize();
 	float* GetData();
 	float* begin();
 	float* end();
 };

 void Identity(Quaternion& q);
 void Normalize(Quaternion& q, Quaternion q1);
 Quaternion Normalize(Quaternion q);
 float Dot(Quaternion q, Quaternion q1);
 float Length(Quaternion q);
 void Invert(Quaternion& q, Quaternion q1);
 Quaternion Invert(Quaternion q);

 void ToMatrix3x3(Matrix3x3& m, Quaternion q);
 Matrix3x3 ToMatrix3x3(Quaternion q);
 void ToMatrix4x4(Matrix4x4& m, Quaternion q);
 Matrix4x4 ToMatrix4x4(Quaternion q);

 void ToQuaternion(Quaternion& q, Matrix3x3 m);
 Quaternion ToQuaternion(Matrix3x3 m);
 void ToQuaternion(Quaternion& q, Matrix4x4 m);
 Quaternion ToQuaternion(Matrix4x4 m);
 
 void Slerp(Quaternion& q, Quaternion a, Quaternion b, float i);
 Quaternion Slerp(Quaternion a, Quaternion b, float i);
 void EulerAngle(Quaternion& q, float pitch, float yaw, float roll);
 Quaternion EulerAngle(float pitch, float yaw, float roll);
 void AxisAngle(Quaternion& q, float angle, float x, float y, float z);
 Quaternion AxisAngle(float angle, float x, float y, float z);
 void Multiply(Quaternion& q, Quaternion a, Quaternion b);
 Quaternion Multiply(Quaternion a, Quaternion b);
}

#endif
