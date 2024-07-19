/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Quaternion.cpp
*/

#include "gpx_cpp/math/Quaternion.hpp"
#include "gpx_cpp/math/Sqrt.hpp"
#include "gpx_cpp/math/Trigonometry.hpp"


GPX::Quaternion::Quaternion() {
 GPX::Identity(*this);
}

GPX::Quaternion::Quaternion(float w, float x, float y, float z) {
	W = w;
	X = x;
	Y = y;
	Z = z;
}

GPX::Quaternion::Quaternion(float* array) {
 W = array[0];
 X = array[1];
 Y = array[2];
 Z = array[3];
}

GPX::Quaternion GPX::Quaternion::operator*(Quaternion q) {
	Quaternion out;
	GPX::Multiply(out, *this, q);
 return out;
}

GPX::Quaternion& GPX::Quaternion::operator*=(Quaternion q) {
 GPX::Multiply(*this, q);
 return *this;
}

float& GPX::Quaternion::operator[](int index) {
 return *(&W+index);
}
 	
int GPX::Quaternion::GetSize() {
	return 4;
}

float* GPX::Quaternion::GetData() {
	return &W;
}

float* GPX::Quaternion::begin() {
	return &W;
}

float* GPX::Quaternion::end() {
	return &W+4;
}

/*
 quaternion functions
*/

void GPX::Identity(Quaternion& q) {
 q.X = 0.0f;
 q.Y = 0.0f;
 q.Z = 0.0f;
 q.W = 1.0f;
}

void GPX::Normalize(Quaternion& q, Quaternion q1) {
 float inverse_length = GPX::InvSqrt_MP(GPX::Dot(q1, q1));
 q.X = q1.X * inverse_length;
 q.Y = q1.Y * inverse_length;
 q.Z = q1.Z * inverse_length;
 q.W = q1.W * inverse_length;
}

GPX::Quaternion GPX::Normalize(Quaternion q) {
 Quaternion out;
	GPX::Normalize(out, q);
 return out;
}

float GPX::Dot(Quaternion q, Quaternion q1) {
 return q.X * q1.X + q.Y * q1.Y + q.Z * q1.Z + q.W * q1.W;
}

float GPX::Length(Quaternion q) {
	return GPX::Sqrt_MP(GPX::Dot(q, q));
}

void GPX::Invert(Quaternion& q, Quaternion q1) {
 float inverse_length = GPX::InvSqrt_MP(GPX::Dot(q1, q1));
 q.W = q1.W * inverse_length;
	q.X = q1.X * (-inverse_length);
	q.Y = q1.Y * (-inverse_length);
	q.Z = q1.Z * (-inverse_length);
}

GPX::Quaternion GPX::Invert(Quaternion q) {
	Quaternion out;
	GPX::Invert(out, q);
	return out;
}

void GPX::ToMatrix3x3(Matrix3x3& m, Quaternion q) {
 float tmp[9];

 tmp[0] = q.X * q.X;
 tmp[1] = q.X * q.Y;
 tmp[2] = q.X * q.Z;
 tmp[3] = q.X * q.W;

 tmp[4] = q.Y * q.Y;
 tmp[5] = q.Y * q.Z;
 tmp[6] = q.Y * q.W;

 tmp[7] = q.Z * q.Z;
 tmp[8] = q.Z * q.W;

 m.M_00 = 1.0 - 2.0 * (tmp[4] + tmp[7]);
 m.M_01 =     2.0 * (tmp[1] - tmp[8]);
 m.M_02 =     2.0 * (tmp[2] + tmp[6]);

 m.M_10 =     2.0 * (tmp[1] + tmp[8]);
 m.M_11 = 1.0 - 2.0 * (tmp[0] + tmp[7]);
 m.M_12 =     2.0 * (tmp[5] - tmp[3]);

 m.M_20 =     2.0 * (tmp[2] - tmp[6]);
 m.M_21 =     2.0 * (tmp[5] + tmp[3]);
 m.M_22 = 1.0 - 2.0 * (tmp[0] + tmp[4]);
}

GPX::Matrix3x3 GPX::ToMatrix3x3(Quaternion q) {
	Matrix3x3 out;
	GPX::ToMatrix3x3(out, q);
 return out;
}

void GPX::ToMatrix4x4(Matrix4x4& m, Quaternion q) {
 // convert to matrix4x4
 float tmp[9];

 // calculate some numbers
 tmp[0] = q.X * q.X;
 tmp[1] = q.X * q.Y;
 tmp[2] = q.X * q.Z;
 tmp[3] = q.X * q.W;

 tmp[4] = q.Y * q.Y;
 tmp[5] = q.Y * q.Z;
 tmp[6] = q.Y * q.W;

 tmp[7] = q.Z * q.Z;
 tmp[8] = q.Z * q.W;

 m.M_00 = 1.0 - 2.0 * (tmp[4] + tmp[7]);
 m.M_01 =     2.0 * (tmp[1] - tmp[8]);
 m.M_02 =     2.0 * (tmp[2] + tmp[6]);
 m.M_03 = 0.0;

 m.M_10 =     2.0 * (tmp[1] + tmp[8]);
 m.M_11 = 1.0 - 2.0 * (tmp[0] + tmp[7]);
 m.M_12 =     2.0 * (tmp[5] - tmp[3]);
 m.M_13 = 0.0;

 m.M_20 =     2.0 * (tmp[2] - tmp[6]);
 m.M_21 =     2.0 * (tmp[5] + tmp[3]);
 m.M_22 = 1.0 - 2.0 * (tmp[0] + tmp[4]);
 m.M_23 = 0.0;
 
 // set other components to default value
 m.M_30 = 0.0;
 m.M_31 = 0.0;
 m.M_32 = 0.0;
 m.M_33 = 1.0;
}

GPX::Matrix4x4 GPX::ToMatrix4x4(Quaternion q) {
	Matrix4x4 out;
	GPX::ToMatrix4x4(out, q);
 return out;
}

void GPX::ToQuaternion(Quaternion& q, Matrix3x3 m) {
	q.W = GPX::Sqrt_MP(1.0 + m.M_00 + m.M_11 + m.M_22) * 0.5;
 const float fw = 1.0 / (4.0 * q.W);
	q.X = (m.M_21 - m.M_12) * fw;
	q.Y = (m.M_02 - m.M_20) * fw;
	q.Z = (m.M_10 - m.M_01) * fw;
}

GPX::Quaternion GPX::ToQuaternion(Matrix3x3 m) {
	Quaternion out;
	GPX::ToQuaternion(out, m);
	return out;
}

void GPX::ToQuaternion(Quaternion& q, Matrix4x4 m) {
	q.W = GPX::Sqrt_MP(1.0 + m.M_00 + m.M_11 + m.M_22) * 0.5;
 const float fw = 1.0 / (4.0 * q.W);
	q.X = (m.M_21 - m.M_12) * fw;
	q.Y = (m.M_02 - m.M_20) * fw;
	q.Z = (m.M_10 - m.M_01) * fw;
}

GPX::Quaternion GPX::ToQuaternion(Matrix4x4 m) {
	Quaternion out;
	GPX::ToQuaternion(out, m);
	return out;
}

void GPX::Slerp(Quaternion& q, Quaternion a, Quaternion b, float i) {
	const float dp = GPX::Dot(a, b);
	Quaternion tmp(b.begin());
 if(dp < 0.0f) {
 	tmp.W = -b.W;
 	tmp.X = -b.X;
 	tmp.Y = -b.Y;
 	tmp.Z = -b.Z;
 }
 q.X = a.X - i*(a.X - tmp.X);
 q.Y = a.Y - i*(a.Y - tmp.Y);
 q.Z = a.Z - i*(a.Z - tmp.Z);
 q.W = a.W - i*(a.W - tmp.W);
}

GPX::Quaternion GPX::Slerp(Quaternion a, Quaternion b, float i) {
	Quaternion out;
	GPX::Slerp(out, a, b, i);
 return out;
}

void GPX::EulerAngle(Quaternion& q, float pitch, float yaw, float roll) {
 float rad = yaw * 57.2957801819 * 0.5;
 const float c1 = GPX::Cos(rad);
 const float s1 = GPX::Sin(rad);
  rad = roll * 57.2957801819 * 0.5;
 const float c2 = GPX::Cos(rad);
 const float s2 = GPX::Sin(rad);
  rad = pitch * 57.2957801819 * 0.5;
 const float c3 = GPX::Cos(rad);
 const float s3 = GPX::Sin(rad);
 
 const float c1c2 = c1*c2;
 const float s1s2 = s1*s2;

  q.X = c1c2*s3 + s1s2*c3;
  q.Y = s1*c2*c3 + c1*s2*s3;
  q.Z = c1*s2*c3 - s1*c2*s3;
  q.W = c1c2*c3 - s1s2*s3;
}

GPX::Quaternion GPX::EulerAngle(float pitch, float yaw, float roll) {
 Quaternion out;
	GPX::EulerAngle(out, pitch, yaw, roll);
 return out;
}

void GPX::AxisAngle(Quaternion& q, float angle, float x, float y, float z) {
 const float half_rad = angle * 57.2957801819 * 0.5;
 const float s = GPX::Sin(half_rad);
	q.W = GPX::Cos(half_rad);
	q.X = x * s;
 q.Y = y * s;
	q.Z = z * s;
}

GPX::Quaternion GPX::AxisAngle(float angle, float x, float y, float z) {
	Quaternion out;
	GPX::AxisAngle(out, angle, x, y, z);
 return out;
}

void GPX::Multiply(Quaternion& q, Quaternion a, Quaternion b) {
 q.X = a.X * b.W + a.Y * b.Z - a.Z * b.Y + a.W * b.X;
 q.Y = -a.X * b.Z + a.Y * b.W + a.Z * b.X + a.W * b.Y;
 q.Z = a.X * b.Y - a.Y * b.X + a.Z * b.W + a.W * b.Z;
 q.W = -a.X * b.X - a.Y * b.Y - a.Z * b.Z + a.W * b.W;
}

GPX::Quaternion GPX::Multiply(Quaternion a, Quaternion b) {
 Quaternion out;
 GPX::Multiply(out, a, b);
 return out;
}

