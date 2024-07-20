/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MathUtils.cpp
*/

#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Trigonometry.hpp"
#include <stdint.h>
#include <iostream>

const float GPX::EPSILON = 0.0000000001;
const float GPX::PI_2 = 6.2831854820;
const float GPX::PI_RAD = 0.0174532925;
const float GPX::INV_PI_RAD = 57.2957801819;
const float GPX::PI = 3.1415926535;
const float GPX::PI_HALF = 1.5707963268;

/*
 matrix projection 
*/
void GPX::Frustum(GPX::Matrix4x4& m, float left, float right, float bottom, float top, float near, float far) {
 float proj[9];
 proj[0] = 1.0 / (right - left);
 proj[1] = 1.0 / (top - bottom);
 proj[2] = 1.0 / (near - far);
 proj[3] = (near * proj[0]) * 2.0;
 proj[4] = (near * proj[1]) * 2.0;
 proj[5] = (right + left) * proj[0];
 proj[6] = (top + bottom) * proj[1];
 proj[7] = (far + near) * proj[2];
 proj[8] = (far * near * proj[2]) * 2.0;
 
 m.M_00 = proj[3];
 m.M_10 = 0.0;
 m.M_20 = 0.0;
 m.M_30 = 0.0;
 
 m.M_01 = 0.0;
 m.M_11 = proj[4];
 m.M_21 = 0.0;
 m.M_31 = 0.0;
 
 m.M_02 = proj[5];
 m.M_12 = proj[6];
 m.M_22 = proj[7];
 m.M_32 = 0.0;
 
 m.M_03 = 0.0;
 m.M_13 = 0.0;
 m.M_23 = proj[8];
 m.M_33 = 1.0;
}


void GPX::Ortho(GPX::Matrix4x4& m, float left, float right, float bottom, float top, float near, float far) {
 float proj[9];
 proj[0] = 1.0 / (right - left);
 proj[1] = 1.0 / (top - bottom);
 proj[2] = 1.0 / (far - near);
 proj[3] = proj[0] * 2.0;
 proj[4] = proj[1] * 2.0;
 proj[5] = proj[2] * -2.0;
 proj[6] = -(right + left) * proj[0];
 proj[7] = -(top + bottom) * proj[1];
 proj[8] = -(far + near) * proj[2];

 m.M_00 = proj[3];
 m.M_10 = 0.0;
 m.M_20 = 0.0;
 m.M_30 = 0.0;
 
 m.M_01 = 0.0;
 m.M_11 = proj[4];
 m.M_21 = 0.0;
 m.M_31 = 0.0;
 
 m.M_02 = 0.0;
 m.M_12 = 0.0;
 m.M_22 = proj[5];
 m.M_32 = 0.0;
 
 m.M_03 = proj[6];
 m.M_13 = proj[7];
 m.M_23 = proj[8];
 m.M_33 = 1.0;
}


void GPX::Perspective(GPX::Matrix4x4& m, float aspect, float fov, float near, float far) {
 const float yscale = static_cast<float>(1.0 / GPX::Tan(57.2957801819 * (fov * 0.5)));
 const float xscale = yscale / aspect;
 const float nearfar = near-far;
 
 m.M_00 = xscale;
 m.M_10 = 0.0;
 m.M_20 = 0.0;
 m.M_30 = 0.0;
 
 m.M_01 = 0.0;
 m.M_11 = yscale;
 m.M_21 = 0.0;
 m.M_31 = 0.0;
 
 m.M_02 = 0.0;
 m.M_12 = 0.0;
 m.M_22 = (far + near) / nearfar;
 m.M_32 = -1.0;
 
 m.M_03 = 0.0;
 m.M_13 = 0.0;
 m.M_23 = 2.0 * far * near / nearfar;
 m.M_33 = 1.0;
}


void GPX::Ortho(GPX::Matrix3x3& m, float left, float right, float bottom, float top, float near, float far) {
 const float rl = (right - left);
 const float tb = (top - bottom);
  m.M_00 = 2.0 / rl;
  m.M_01 = 0.0;
  m.M_02 = 0.0;
  
  m.M_10 = 0.0;
  m.M_11 = 2.0 / tb;
  m.M_12 = 0.0;
  
  m.M_20 = -(right + left) / rl;
  m.M_21 = -(top + bottom) / tb;
  m.M_22 = 1.0;
}


void GPX::Project(GPX::Vector3& v, GPX::Vector3 in, GPX::Matrix4x4 model, GPX::Matrix4x4 project, int viewport[4]) {
 Matrix4x4 proj_model;
 Vector3 projected;
 GPX::Multiply(proj_model, project, model);
 GPX::Multiply(projected, proj_model, in);
 v.X = viewport[0] + viewport[2] * (projected.X + 1.0) * 0.5;
 v.Y = viewport[1] + viewport[3] * (projected.Y + 1.0) * 0.5;
 v.Z = (projected.Z + 1.0) * 0.5;
}


void GPX::UnProject(GPX::Vector3& v, GPX::Vector3 in, GPX::Matrix4x4 model, GPX::Matrix4x4 project, int viewport[4]) {
 Matrix4x4 proj_model, inv_pm;
 Vector3 vec_input;
 GPX::Multiply(proj_model, project, model);
 GPX::Multiply(inv_pm, proj_model);
 vec_input.X = 2.0 * (in.X - viewport[0]) / viewport[2] - 1.0;
 vec_input.Y = 2.0 * (in.Y - viewport[1]) / viewport[3] - 1.0;
 vec_input.Z = 2.0 * in.Z - 1.0;
 GPX::Multiply(v, inv_pm, vec_input);
}


/*
 mod
*/
float GPX::Mod(float a, float b) {
	return ((a) - (int32_t)((a) / (b)) * (b));
}

/*
 min and max
*/
float GPX::Min(float a, float b) {
	return a < b ? a : b;
}


float GPX::Max(float a, float b) {
	return a < b ? b : a;
}


/*
 absolute value
*/
float GPX::Abs(float x) {
	return x < 0.0 ? -x : x;
}


GPX::Vector2 GPX::Abs(GPX::Vector2 vec) {
	return GPX::Vector2(GPX::Abs(vec.X), GPX::Abs(vec.Y));
}


GPX::Vector3 GPX::Abs(GPX::Vector3 vec) {
	return GPX::Vector3(GPX::Abs(vec.X), GPX::Abs(vec.Y), GPX::Abs(vec.Z));
}


GPX::Vector4 GPX::Abs(GPX::Vector4 vec) {
	return GPX::Vector4(GPX::Abs(vec.X), GPX::Abs(vec.Y), GPX::Abs(vec.Z), GPX::Abs(vec.W));
}


/*
 clamp
*/
float GPX::Clamp(float x, float min, float max) {
	return GPX::Min(GPX::Max(x, min), max);
}


GPX::Vector2 GPX::Clamp(GPX::Vector2 vec, GPX::Vector2 min, GPX::Vector2 max) {
	return GPX::Vector2(GPX::Clamp(vec.X, min.X, max.X), GPX::Clamp(vec.Y, min.Y, max.Y));
}


GPX::Vector3 GPX::Clamp(GPX::Vector3 vec, GPX::Vector3 min, GPX::Vector3 max) {
	return GPX::Vector3(GPX::Clamp(vec.X, min.X, max.X), GPX::Clamp(vec.Y, min.Y, max.Y), GPX::Clamp(vec.Z, min.Z, max.Z));
}


GPX::Vector4 GPX::Clamp(GPX::Vector4 vec, GPX::Vector4 min, GPX::Vector4 max) {
	return GPX::Vector4(GPX::Clamp(vec.X, min.X, max.X), GPX::Clamp(vec.Y, min.Y, max.Y), GPX::Clamp(vec.Z, min.Z, max.Z), GPX::Clamp(vec.W, min.W, max.W));
}





void GPX::Print(GPX::Matrix3x3 m) {
	int i = 0;
	for(float& f : m) {
  if(i % 3 == 0) std::cout << std::endl;
		std::cout << f << ", ";
		i++;
	}
}


void GPX::Print(GPX::Matrix4x4 m) {
	int i = 0;
	for(float& f : m) {
		if(i % 4 == 0) std::cout << std::endl;
		std::cout << f << ", ";
		i++;
	}
}


void GPX::Print(GPX::Quaternion q) {
	for(float& f : q)
	 std::cout << f << ", ";
}


void GPX::Print(GPX::Vector2 v) {
	for(float& f : v)
	 std::cout << f << ", ";
}


void GPX::Print(GPX::Vector3 v) {
	for(float& f : v)
	 std::cout << f << ", ";
}


void GPX::Print(GPX::Vector4 v) {
	for(float& f : v)
	 std::cout << f << ", ";
}
