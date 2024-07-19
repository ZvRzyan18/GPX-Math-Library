/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Vector.cpp
*/

#include "gpx_cpp/math/Vector.hpp"
#include "gpx_cpp/math/Sqrt.hpp"

/*
 Vector2 class
*/
GPX::Vector2::Vector2() {
	X = 0;
	Y = 0;
}

GPX::Vector2::Vector2(Vector3 vector) {
	X = vector.X;
	Y = vector.Y;
}

GPX::Vector2::Vector2(Vector4 vector) {
	X = vector.X;
	Y = vector.Y;
}

GPX::Vector2::Vector2(float x, float y) {
	X = x;
	Y = y;
}

GPX::Vector2::Vector2(float* array) {
	X = array[0];
	Y = array[1];
}

void GPX::Vector2::operator=(Vector2 vector) {
	X = vector.X;
	Y = vector.Y;
}

void GPX::Vector2::operator=(Vector3 vector) {
 X = vector.X;
 Y = vector.Y;
}

void GPX::Vector2::operator=(Vector4 vector) {
	X = vector.X;
	Y = vector.Y;
}

bool GPX::Vector2::operator==(Vector2 vector) {
	return X == vector.X && Y == vector.Y;
}

bool GPX::Vector2::operator!=(Vector2 vector) {
	return !(X == vector.X && Y == vector.Y);
}

GPX::Vector2 GPX::Vector2::operator+(Vector2 a) {
	return GPX::Vector2(X+a.X, Y+a.Y);
}

GPX::Vector2 GPX::Vector2::operator-(Vector2 a) {
	return GPX::Vector2(X-a.X, Y-a.Y);
}

GPX::Vector2 GPX::Vector2::operator*(Vector2 a) {
	return GPX::Vector2(X*a.X, Y*a.Y);
}

GPX::Vector2 GPX::Vector2::operator/(Vector2 a) {
	return GPX::Vector2(X/a.X, Y/a.Y);
}


GPX::Vector2 GPX::Vector2::operator+(float a) {
	return GPX::Vector2(X+a, Y+a);
}

GPX::Vector2 GPX::Vector2::operator-(float a) {
	return GPX::Vector2(X-a, Y-a);
}

GPX::Vector2 GPX::Vector2::operator*(float a) {
	return GPX::Vector2(X*a, Y*a);
}

GPX::Vector2 GPX::Vector2::operator/(float a) {
	return GPX::Vector2(X/a, Y/a);
}

GPX::Vector2& GPX::Vector2::operator+=(Vector2 a) {
	X += a.X;
	Y += a.Y;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator-=(Vector2 a) {
	X -= a.X;
	Y -= a.Y;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator*=(Vector2 a) {
	X *= a.X;
	Y *= a.Y;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator/=(Vector2 a) {
	X /= a.X;
	Y /= a.Y;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator+=(float a) {
	X += a;
	Y += a;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator-=(float a) {
	X -= a;
	Y -= a;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator*=(float a) {
	X *= a;
	Y *= a;
	return *this;
}

GPX::Vector2& GPX::Vector2::operator/=(float a) {
	X /= a;
	Y /= a;
	return *this;
}

float& GPX::Vector2::operator[](int index) {
	return *(&X+index);
}

int GPX::Vector2::GetSize() {
	return 2;
}

float* GPX::Vector2::GetData() {
	return &X;
}

float* GPX::Vector2::begin() {
	return &X;
}

float* GPX::Vector2::end() {
	return &X+2;
}

/*
 Vector3 class
*/

GPX::Vector3::Vector3() {
	X = 0;
	Y = 0;
	Z = 0;
}

GPX::Vector3::Vector3(Vector2 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = 0;
}

GPX::Vector3::Vector3(Vector4 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = vector.Z;
}

GPX::Vector3::Vector3(float x, float y, float z) {
	X = x;
	Y = y;
	Z = z;
}

GPX::Vector3::Vector3(float* array) {
	X = array[0];
	Y = array[1];
	Z = array[2];
}

void	GPX::Vector3::operator=(Vector2 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = 0;
}

void GPX::Vector3::operator=(Vector3 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = vector.Z;
}

void GPX::Vector3::operator=(Vector4 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = vector.Z;
}

bool GPX::Vector3::operator==(Vector3 vector) {
	return X == vector.X && Y == vector.Y && Z == vector.Z;
}

bool GPX::Vector3::operator!=(Vector3 vector) {
	return !(X == vector.X && Y == vector.Y && X == vector.Z);
}

GPX::Vector3 GPX::Vector3::operator+(Vector3 a) {
	return GPX::Vector3(X+a.X, Y+a.Y, Z+a.Z);
}

GPX::Vector3 GPX::Vector3::operator-(Vector3 a) {
	return GPX::Vector3(X-a.X, Y-a.Y, Z-a.Z);
}

GPX::Vector3 GPX::Vector3::operator*(Vector3 a) {
	return GPX::Vector3(X*a.X, Y*a.Y, Z*a.Z);
}

GPX::Vector3 GPX::Vector3::operator/(Vector3 a) {
	return GPX::Vector3(X/a.X, Y/a.Y, Z/a.Z);
}


GPX::Vector3 GPX::Vector3::operator+(float a) {
	return GPX::Vector3(X+a, Y+a, Z+a);
}

GPX::Vector3 GPX::Vector3::operator-(float a) {
	return GPX::Vector3(X-a, Y-a, Z-a);
}

GPX::Vector3 GPX::Vector3::operator*(float a) {
	return GPX::Vector3(X*a, Y*a, Z*a);
}

GPX::Vector3 GPX::Vector3::operator/(float a) {
	return GPX::Vector3(X/a, Y/a, Z/a);
}

GPX::Vector3& GPX::Vector3::operator+=(Vector3 a) {
	X += a.X;
	Y += a.Y;
	Z += a.Z;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator-=(Vector3 a) {
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator*=(Vector3 a) {
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator/=(Vector3 a) {
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator+=(float a) {
	X += a;
	Y += a;
	Z += a;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator-=(float a) {
	X -= a;
	Y -= a;
	Z -= a;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator*=(float a) {
	X *= a;
	Y *= a;
	Z *= a;
	return *this;
}

GPX::Vector3& GPX::Vector3::operator/=(float a) {
	X /= a;
	Y /= a;
	Z /= a;
	return *this;
}

float& GPX::Vector3::operator[](int index) {
	return *(&X+index);
}

int GPX::Vector3::GetSize() {
	return 3;
}

float* GPX::Vector3::GetData() {
	return &X;
}

float* GPX::Vector3::begin() {
	return &X;
}

float* GPX::Vector3::end() {
	return &X+3;
}

/*
 Vector4 class
*/

GPX::Vector4::Vector4() {
	X = 0;
	Y = 0;
	Z = 0;
	W = 0;
}

GPX::Vector4::Vector4(Vector2 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = 0;
	W = 0;
}

GPX::Vector4::Vector4(Vector3 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = vector.Z;
	W = 0;
}

GPX::Vector4::Vector4(float x, float y, float z, float w) {
	X = x;
	Y = y;
	Z = z;
	W = w;
}

GPX::Vector4::Vector4(float* array) {
	X = array[0];
	Y = array[1];
	Z = array[2];
	W = array[3];
}

void	GPX::Vector4::operator=(Vector2 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = 0;
	W = 0;
}

void GPX::Vector4::operator=(Vector3 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = vector.Z;
	W = 0;
}

void GPX::Vector4::operator=(Vector4 vector) {
	X = vector.X;
	Y = vector.Y;
	Z = vector.Z;
	W = vector.W;
}

bool GPX::Vector4::operator==(Vector4 vector) {
	return X == vector.X && Y == vector.Y && Z == vector.Z && W == vector.W;
}

bool GPX::Vector4::operator!=(Vector4 vector) {
	return !(X == vector.X && Y == vector.Y && Z == vector.Z && W == vector.W);
}

GPX::Vector4 GPX::Vector4::operator+(Vector4 a) {
	return GPX::Vector4(X+a.X, Y+a.Y, Z+a.Z, W+a.W);
}

GPX::Vector4 GPX::Vector4::operator-(Vector4 a) {
	return GPX::Vector4(X-a.X, Y-a.Y, Z-a.Z, W-a.W);
}

GPX::Vector4 GPX::Vector4::operator*(Vector4 a) {
	return GPX::Vector4(X*a.X, Y*a.Y, Z*a.Z, W*a.W);
}

GPX::Vector4 GPX::Vector4::operator/(Vector4 a) {
	return GPX::Vector4(X/a.X, Y/a.Y, Z/a.Z, W/a.W);
}


GPX::Vector4 GPX::Vector4::operator+(float a) {
	return GPX::Vector4(X+a, Y+a, Z+a, W+a);
}

GPX::Vector4 GPX::Vector4::operator-(float a) {
	return GPX::Vector4(X-a, Y-a, Z-a, W-a);
}

GPX::Vector4 GPX::Vector4::operator*(float a) {
	return GPX::Vector4(X*a, Y*a, Z*a, W*a);
}

GPX::Vector4 GPX::Vector4::operator/(float a) {
	return GPX::Vector4(X/a, Y/a, Z/a, W/a);
}

GPX::Vector4& GPX::Vector4::operator+=(Vector4 a) {
	X += a.X;
	Y += a.Y;
	Z += a.Z;
	W += a.W;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator-=(Vector4 a) {
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;
	W -= a.W;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator*=(Vector4 a) {
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;
	W *= a.W;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator/=(Vector4 a) {
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;
	W /= a.W;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator+=(float a) {
	X += a;
	Y += a;
	Z += a;
	W += a;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator-=(float a) {
	X -= a;
	Y -= a;
	Z -= a;
	W -= a;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator*=(float a) {
	X *= a;
	Y *= a;
	Z *= a;
	W *= a;
	return *this;
}

GPX::Vector4& GPX::Vector4::operator/=(float a) {
	X /= a;
	Y /= a;
	Z /= a;
	W /= a;
	return *this;
}

float& GPX::Vector4::operator[](int index) {
	return *(&X+index);
}

int GPX::Vector4::GetSize() {
	return 3;
}

float* GPX::Vector4::GetData() {
	return &X;
}

float* GPX::Vector4::begin() {
	return &X;
}

float* GPX::Vector4::end() {
	return &X+3;
}

/*
 vector functions
*/

float GPX::Dot(Vector2 a, Vector2 b) {
	return a.X * b.X + a.Y * b.Y;
}

float GPX::Dot(Vector3 a, Vector3 b) {
	return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

float GPX::Dot(Vector4 a, Vector4 b) {
	return a.X * b.X + a.Y * b.Y + a.Z * b.Z + a.W * b.W;
}

float GPX::Length(Vector2 a) {
	return GPX::Sqrt_MP(GPX::Dot(a, a));
}

float GPX::Length(Vector3 a) {
	return GPX::Sqrt_MP(GPX::Dot(a, a));
}

float GPX::Length(Vector4 a) {
	return GPX::Sqrt_MP(GPX::Dot(a, a));
}

void GPX::Normalize(Vector2& out, Vector2 a) {
 float inverse_length = GPX::InvSqrt_MP(GPX::Dot(a, a));
 out.X = a.X * inverse_length;
 out.Y = a.Y * inverse_length;
}

void GPX::Normalize(Vector3& out, Vector3 a) {
 float inverse_length = GPX::InvSqrt_MP(GPX::Dot(a, a));
 out.X = a.X * inverse_length;
 out.Y = a.Y * inverse_length;
 out.Z = a.Z * inverse_length;
}

void GPX::Normalize(Vector4& out, Vector4 a) {
 float inverse_length = GPX::InvSqrt_MP(GPX::Dot(a, a));
 out.X = a.X * inverse_length;
 out.Y = a.Y * inverse_length;
 out.Z = a.Z * inverse_length;
 out.W = a.W * inverse_length;
}

GPX::Vector2 GPX::Normalize(Vector2 a) {
	Vector2 out;
	GPX::Normalize(out, a);
 return out;
}

GPX::Vector3 GPX::Normalize(Vector3 a) {
	Vector3 out;
	GPX::Normalize(out, a);
	return out;
}

GPX::Vector4 GPX::Normalize(Vector4 a) {
	Vector4 out;
	GPX::Normalize(out, a);
 return out;
}

GPX::Vector3 GPX::Cross(Vector3 a, Vector3 b) {
 return GPX::Vector3(
  a.Y * b.Z - a.Z * b.Y,
  a.Z * b.X - a.X * b.Z,
  a.X * b.Y - a.Y * b.X
 );
}

