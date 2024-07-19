/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Matrix.cpp
*/

#include "gpx_cpp/math/Matrix.hpp"
#include "gpx_cpp/math/Trigonometry.hpp"

/*
 Matrix3x3 class
*/
GPX::Matrix3x3::Matrix3x3() {
	GPX::Identity(*this);
}


GPX::Matrix3x3::Matrix3x3(Matrix4x4 m) {
	this->M_00 = m.M_00;
	this->M_10 = m.M_10;
	this->M_20 = m.M_20;
	
	this->M_01 = m.M_01;
	this->M_11 = m.M_11;
	this->M_21 = m.M_21;
	
	this->M_02 = m.M_02;
	this->M_12 = m.M_12;
	this->M_22 = m.M_22;
}


GPX::Matrix3x3::Matrix3x3(float* array) {
	this->M_00 = array[0];
	this->M_10 = array[1];
	this->M_20 = array[2];
	
	this->M_01 = array[3];
	this->M_11 = array[4];
	this->M_21 = array[5];
	
	this->M_02 = array[6];
	this->M_12 = array[7];
	this->M_22 = array[8];
}


void GPX::Matrix3x3::operator=(Matrix3x3 m) {
	this->M_00 = m.M_00;
	this->M_10 = m.M_10;
	this->M_20 = m.M_20;
	
	this->M_01 = m.M_01;
	this->M_11 = m.M_11;
	this->M_21 = m.M_21;
	
	this->M_02 = m.M_02;
	this->M_12 = m.M_12;
	this->M_22 = m.M_22;
}


void GPX::Matrix3x3::operator=(Matrix4x4 m) {
	this->M_00 = m.M_00;
	this->M_10 = m.M_10;
	this->M_20 = m.M_20;
	
	this->M_01 = m.M_01;
	this->M_11 = m.M_11;
	this->M_21 = m.M_21;
	
	this->M_02 = m.M_02;
	this->M_12 = m.M_12;
	this->M_22 = m.M_22;
}


GPX::Matrix3x3 GPX::Matrix3x3::operator*(Matrix3x3 m) {
	Matrix3x3 out;
	GPX::Multiply(out, *this, m);
 return out;
}


GPX::Vector3 GPX::Matrix3x3::operator*(Vector3 v) {
	Vector3 out;
	GPX::Multiply(out, *this, v);
 return out;
}


GPX::Matrix3x3& GPX::Matrix3x3::operator*=(Matrix3x3 m) {
 GPX::Multiply(*this, *this, m);
	return *this;
}

	 
float& GPX::Matrix3x3::Get(int row, int column) {
	return *(&M_00+(column * 3 + row));
}


float& GPX::Matrix3x3::operator[](int index) {
	return *(&M_00+index);
}


GPX::Matrix3x3Components& GPX::Matrix3x3::GetComponents() {
	return *(Matrix3x3Components*)(&this->M_00);
}


int GPX::Matrix3x3::GetSize() {
	return 9;
}


float* GPX::Matrix3x3::GetData() {
	return &M_00;
}

/*
 pointer iterator 
  begin();
  end();
*/
float* GPX::Matrix3x3::begin() {
	return &M_00;
}


float* GPX::Matrix3x3::end() {
	return &M_00+9;
}



/*
 Matrix4x4 class
*/

GPX::Matrix4x4::Matrix4x4() {
	GPX::Identity(*this);
}


GPX::Matrix4x4::Matrix4x4(Matrix3x3 m) {
	this->M_00 = m.M_00;
	this->M_10 = m.M_10;
	this->M_20 = m.M_20;
	
	this->M_01 = m.M_01;
	this->M_11 = m.M_11;
	this->M_21 = m.M_21;
	
	this->M_02 = m.M_02;
	this->M_12 = m.M_12;
	this->M_22 = m.M_22;
}


GPX::Matrix4x4::Matrix4x4(float* array) {
	this->M_00 = array[0];
	this->M_10 = array[1];
	this->M_20 = array[2];
	this->M_30 = array[3];
	
	this->M_01 = array[4];
	this->M_11 = array[5];
	this->M_21 = array[6];
	this->M_31 = array[7];
	
	this->M_02 = array[8];
	this->M_12 = array[9];
	this->M_22 = array[10];
	this->M_32 = array[11];
	
	this->M_03 = array[12];
	this->M_13 = array[13];
	this->M_23 = array[14];
	this->M_33 = array[15];
}


void GPX::Matrix4x4::operator=(Matrix3x3 m) {
	this->M_00 = m.M_00;
	this->M_10 = m.M_10;
	this->M_20 = m.M_20;
	this->M_30 = 0.0;
	
	this->M_01 = m.M_01;
	this->M_11 = m.M_11;
	this->M_21 = m.M_21;
	this->M_31 = 0.0;
	
	this->M_02 = m.M_02;
	this->M_12 = m.M_12;
	this->M_22 = m.M_22;
	this->M_32 = 0.0;

 this->M_03 = 0.0;
 this->M_13 = 0.0;
 this->M_23 = 0.0;
 this->M_33 = 1.0;
}


void GPX::Matrix4x4::operator=(Matrix4x4 m) {
	this->M_00 = m.M_00;
	this->M_10 = m.M_10;
	this->M_20 = m.M_20;
	this->M_30 = m.M_30;
	
	this->M_01 = m.M_01;
	this->M_11 = m.M_11;
	this->M_21 = m.M_21;
	this->M_31 = m.M_31;
	
	this->M_02 = m.M_02;
	this->M_12 = m.M_12;
	this->M_22 = m.M_22;
	this->M_32 = m.M_32;

 this->M_03 = m.M_03;
 this->M_13 = m.M_13;
 this->M_23 = m.M_23;
 this->M_33 = m.M_33;
}


GPX::Matrix4x4 GPX::Matrix4x4::operator*(Matrix4x4 m) {
	Matrix4x4 out;
	GPX::Multiply(out, *this, m);
 return out;
}


GPX::Vector4 GPX::Matrix4x4::operator*(Vector4 v) {
	Vector4 out;
	GPX::Multiply(out, *this, v);
 return out;
}


GPX::Matrix4x4& GPX::Matrix4x4::operator*=(Matrix4x4 m) {
	GPX::Multiply(*this, *this, m);
	return *this;
}

	 
float& GPX::Matrix4x4::Get(int row, int column) {
	return *(&M_00+(column * 3 + row));
}


float& GPX::Matrix4x4::operator[](int index) {
	return *(&M_00+index);
}


GPX::Matrix4x4Components& GPX::Matrix4x4::GetComponents() {
	return *(Matrix4x4Components*)(&this->M_00);
}


int GPX::Matrix4x4::GetSize() {
	return 16;
}


float* GPX::Matrix4x4::GetData() {
	return &M_00;
}

/*
 pointer iterator
  begin();
  end();
*/
float* GPX::Matrix4x4::begin() {
	return &M_00;
}


float* GPX::Matrix4x4::end() {
	return &M_00+16;
}



/*
 matrix implementation
*/

/*
 matrix 3x3
*/
void GPX::Identity(Matrix3x3& m) {
	m.M_00 = 1.0f;
	m.M_10 = 0.0f;
	m.M_20 = 0.0f;
	
 m.M_01 = 0.0f;
	m.M_11 = 1.0f;
	m.M_21 = 0.0f;
	
	m.M_02 = 0.0f;
	m.M_12 = 0.0f;
	m.M_22 = 1.0f;
}


void GPX::MultiplyTranslate(Matrix3x3& m, Matrix3x3 m1, float x, float y) {
	m.M_02 = m1.M_00 * x + m1.M_01 * y + m1.M_02;
	m.M_12 = m1.M_10 * x + m1.M_11 * y + m1.M_12;
}


void GPX::Translate(Matrix3x3& m, float x, float y) {
 m.M_02 += x;
 m.M_12 += y;
}


void GPX::MultiplyScale(Matrix3x3& m, Matrix3x3 m1, float x, float y) {
	m.M_00 = m1.M_00 * x;
	m.M_01 = m1.M_01 * x;
	m.M_10 = m1.M_10 * y;
	m.M_11 = m1.M_11 * y;
}


void GPX::Scale(Matrix3x3& m, float x, float y) {
	m.M_00 *= x;
	m.M_11 *= y;
}


void GPX::SetRotate(Matrix3x3& m, float angle) {
 const float radians = angle * 57.2957801819;
	const float s = GPX::Sin(radians);
	const float c = GPX::Cos(radians);
	 m.M_00 = c;
  m.M_10 = s;
  m.M_01 = -s;
  m.M_11 = c;
}


void GPX::Rotate(Matrix3x3& m, Matrix3x3 m1, float angle) {
 Matrix3x3 tmp;
 GPX::SetRotate(tmp, angle);
 GPX::Multiply(m, m, tmp);
}


void GPX::Transpose(Matrix3x3& m, Matrix3x3 m1) {
	m.M_00 = m1.M_00;
	m.M_10 = m1.M_01;
	m.M_20 = m1.M_02;
	
	m.M_01 = m1.M_10;
	m.M_11 = m1.M_11;
	m.M_21 = m1.M_12;
	
	m.M_02 = m1.M_20;
	m.M_12 = m1.M_21;
	m.M_22 = m1.M_22;
}


GPX::Matrix3x3 GPX::Transpose(Matrix3x3 m) {
	Matrix3x3 out;
	GPX::Transpose(out, m);
	return out;
}


void GPX::Invert(Matrix3x3& m, Matrix3x3 m1) {
 float temp[3];
	temp[0] = m1.M_11 * m1.M_22 - m1.M_21 * m1.M_12;
	temp[1] = m1.M_10 * m1.M_22 - m1.M_12 * m1.M_20;
	temp[2] = m1.M_10 * m1.M_21 - m1.M_11 * m1.M_20;

	float inverse_determinant = 1.0 / (m1.M_00 * temp[0] - m1.M_01 * temp[1] + m1.M_02 * temp[2]);

	m.M_00 = (temp[0]) * inverse_determinant;
 m.M_01 = -(m1.M_01 * m1.M_22 - m1.M_02 * m1.M_21) * inverse_determinant;
 m.M_02 = (m1.M_01 * m1.M_12 - m1.M_02 * m1.M_11) * inverse_determinant;
 
 m.M_10 = -(temp[1]) * inverse_determinant;
 m.M_11 = (m1.M_00 * m1.M_22 - m1.M_02 * m1.M_20) * inverse_determinant;
 m.M_12 = -(m1.M_00 * m1.M_12 - m1.M_02 * m1.M_10) * inverse_determinant;
 
 m.M_20 = (temp[2]) * inverse_determinant;
 m.M_21 = -(m1.M_00 * m1.M_21 - m1.M_02 * m1.M_20) * inverse_determinant;
 m.M_22 = (m1.M_00 * m1.M_11 - m1.M_10 * m1.M_01) * inverse_determinant;
}


GPX::Matrix3x3 GPX::Invert(Matrix3x3 m) {
	Matrix3x3 out;
	GPX::Invert(out, m);
	return out;
}


float GPX::Determinant(GPX::Matrix3x3 m) {
	return (m.M_00 * (m.M_11 * m.M_22 - m.M_21 * m.M_12) - m.M_01 * (m.M_10 * m.M_22 - m.M_12 * m.M_20) + m.M_02 * (m.M_10 * m.M_21 - m.M_11 * m.M_20));
}


void GPX::Multiply(Matrix3x3& m, Matrix3x3 a, Matrix3x3 b) {
	m.M_00 = a.M_00 * b.M_00 + a.M_10 * b.M_01 + a.M_20 * b.M_02;
	m.M_10 = a.M_00 * b.M_10 + a.M_10 * b.M_11 + a.M_20 * b.M_12;
	m.M_20 = a.M_00 * b.M_20 + a.M_10 * b.M_21 + a.M_20 * b.M_22;
 
	m.M_01 = a.M_01 * b.M_00 + a.M_11 * b.M_01 + a.M_21 * b.M_02;
	m.M_11 = a.M_01 * b.M_10 + a.M_11 * b.M_11 + a.M_21 * b.M_12;
	m.M_21 = a.M_01 * b.M_20 + a.M_11 * b.M_21 + a.M_21 * b.M_22;

	m.M_02 = a.M_02 * b.M_00 + a.M_12 * b.M_01 + a.M_22 * b.M_02;
	m.M_12 = a.M_02 * b.M_10 + a.M_12 * b.M_11 + a.M_22 * b.M_12;
	m.M_22 = a.M_02 * b.M_20 + a.M_12 * b.M_21 + a.M_22 * b.M_22;
}


void GPX::Multiply(Vector3& v, Matrix3x3 a, Vector3 b) {
 v.X = a.M_00 * b.X + a.M_01 * b.Y + a.M_02 * b.Z;
 v.Y = a.M_10 * b.X + a.M_11 * b.Y + a.M_12 * b.Z;
 v.Z = a.M_20 * b.X + a.M_21 * b.Y + a.M_22 * b.Z;
}


GPX::Matrix3x3 GPX::Multiply(Matrix3x3 a, Matrix3x3 b) {
	Matrix3x3 out;
	GPX::Multiply(out, a, b);
	return out;
}


GPX::Vector3 GPX::Multiply(Matrix3x3 a, Vector3 b) {
	Vector3 out;
	GPX::Multiply(out, a, b);
	return out;
}


/*
 Matrix4x4 functions
*/
void GPX::Identity(Matrix4x4& m) {
 m.M_00 = 1.0f;
	m.M_10 = 0.0f;
	m.M_20 = 0.0f;
	m.M_30 = 0.0f;

	m.M_01 = 0.0f;
	m.M_11 = 1.0f;
	m.M_21 = 0.0f;
	m.M_31 = 0.0f;
	
	m.M_02 = 0.0f;
	m.M_12 = 0.0f;
	m.M_22 = 1.0f;
	m.M_32 = 0.0f;

	m.M_03 = 0.0f;
	m.M_13 = 0.0f;
	m.M_23 = 0.0f;
	m.M_33 = 1.0f;
}


void GPX::MultiplyTranslate(Matrix4x4& m, Matrix4x4 m1, float x, float y, float z) {
	m.M_03 = m1.M_00 * x + m1.M_01 * y + m1.M_02 * z + m1.M_03;
	m.M_13 = m1.M_10 * x + m1.M_11 * y + m1.M_12 * z + m1.M_13;
	m.M_23 = m1.M_20 * x + m1.M_21 * y + m1.M_22 * z + m1.M_23;
}


void GPX::Translate(Matrix4x4& m, float x, float y, float z) {
 m.M_03 += x;
 m.M_13 += y;
 m.M_23 += z;
}


void GPX::MultiplyScale(Matrix4x4 &m, Matrix4x4 m1, float x, float y, float z) {
	m.M_00 = m1.M_00 * x;
	m.M_01 = m1.M_01 * x;
	m.M_02 = m1.M_02 * x;
	
	m.M_10 = m1.M_10 * y;
	m.M_11 = m1.M_11 * y;
	m.M_12 = m1.M_12 * y;
	
	m.M_20 = m1.M_20 * z;
	m.M_21 = m1.M_21 * z;
	m.M_22 = m1.M_22 * z;
}


void GPX::Scale(Matrix4x4& m, float x, float y, float z) {
 m.M_00 *= x;
 m.M_11 *= y;
 m.M_22 *= z;
}


void GPX::SetRotateX(Matrix4x4& m, float angle) {
 const float radians = angle * 57.2957801819;
	const float s = GPX::Sin(radians);
 const float c = GPX::Cos(radians);
	 m.M_11 = c;
  m.M_21 = -s;
  m.M_12 = s;
  m.M_22 = c;
}


void GPX::RotateX(Matrix4x4& m, Matrix4x4 m1, float angle) {
 Matrix4x4 tmp;
 GPX::SetRotateX(tmp, angle);
 GPX::Multiply(m, m, tmp);
}


void GPX::SetRotateY(Matrix4x4& m, float angle) {
 const float radians = angle * 57.2957801819;
	const float s = GPX::Sin(radians);
 const float c = GPX::Cos(radians);
  m.M_00 = c;
  m.M_20 = s;
  m.M_02 = -s;
  m.M_22 = c;
}


void GPX::RotateY(Matrix4x4& m, Matrix4x4 m1, float angle) {
 Matrix4x4 tmp;
 GPX::SetRotateY(tmp, angle);
 GPX::Multiply(m, m, tmp);
}


void GPX::SetRotateZ(Matrix4x4& m, float angle) {
 const float radians = angle * 57.2957801819;
	const float s = GPX::Sin(radians);
 const float c = GPX::Cos(radians);
  m.M_00 = c;
  m.M_10 = -s;
  m.M_01 = s;
  m.M_11 = c;
}


void GPX::RotateZ(Matrix4x4& m, Matrix4x4 m1, float angle) {
 Matrix4x4 tmp;
 GPX::SetRotateZ(tmp, angle);
 GPX::Multiply(m, m, tmp);
}


void GPX::Transpose(Matrix4x4& m, Matrix4x4 m1) {
	m.M_00 = m1.M_00;
	m.M_10 = m1.M_01;
	m.M_20 = m1.M_02;
	m.M_30 = m1.M_03;

	m.M_01 = m1.M_10;
	m.M_11 = m1.M_11;
	m.M_21 = m1.M_12;
	m.M_31 = m1.M_13;
	
	m.M_02 = m1.M_20;
	m.M_12 = m1.M_21;
	m.M_22 = m1.M_22;
	m.M_32 = m1.M_23;

	m.M_03 = m1.M_30;
	m.M_13 = m1.M_31;
	m.M_23 = m1.M_32;
	m.M_33 = m1.M_33;
}


GPX::Matrix4x4 GPX::Transpose(Matrix4x4 m) {
	Matrix4x4 out;
	GPX::Transpose(out, m);
	return out;
}


void GPX::Invert(Matrix4x4& m, Matrix4x4 m1) {
 float temp[12];

	temp[0] = m1.M_00 * m1.M_11 - m1.M_10 * m1.M_01;
	temp[1] = m1.M_00 * m1.M_12 - m1.M_10 * m1.M_02;
	temp[2] = m1.M_00 * m1.M_13 - m1.M_10 * m1.M_03;
	temp[3] = m1.M_01 * m1.M_12 - m1.M_11 * m1.M_02;
	temp[4] = m1.M_01 * m1.M_13 - m1.M_11 * m1.M_03;
	temp[5] = m1.M_02 * m1.M_13 - m1.M_12 * m1.M_03;
	
	temp[6] = m1.M_22 * m1.M_33 - m1.M_32 * m1.M_23;
	temp[7] = m1.M_21 * m1.M_33 - m1.M_31 * m1.M_23;
	temp[8] = m1.M_21 * m1.M_32 - m1.M_31 * m1.M_22;
	temp[9] = m1.M_20 * m1.M_33 - m1.M_30 * m1.M_23;
	temp[10] =m1.M_20 * m1.M_32 - m1.M_30 * m1.M_22;
	temp[11] =m1.M_20 * m1.M_31 - m1.M_30 * m1.M_21;

 float inverse_determinant = 1.0 / (temp[0] * temp[6] - temp[1] * temp[7] + temp[2] * temp[8] + temp[3] * temp[9] - temp[4] * temp[10] + temp[5] * temp[11]);

 m.M_00 = (m1.M_11 * temp[6] - m1.M_12 * temp[7] + m1.M_13 * temp[8]) * inverse_determinant;
 m.M_01 = (-m1.M_01 * temp[6] + m1.M_02 * temp[7] - m1.M_03 * temp[8]) * inverse_determinant;
 m.M_02 = (m1.M_31 * temp[5] - m1.M_32 * temp[4] + m1.M_33 * temp[3]) * inverse_determinant;
 m.M_03 = (-m1.M_21 * temp[5] + m1.M_22 * temp[4] - m1.M_23 * temp[3]) * inverse_determinant;

 m.M_10 = (-m1.M_10 * temp[6] + m1.M_12 * temp[9] - m1.M_13 * temp[10]) * inverse_determinant;
 m.M_11 = (m1.M_00 * temp[6] - m1.M_02 * temp[9] + m1.M_03 * temp[10]) * inverse_determinant;
 m.M_12 = (-m1.M_30 * temp[5] + m1.M_32 * temp[2] - m1.M_33 * temp[1]) * inverse_determinant;
 m.M_13 = (m1.M_20 * temp[5] - m1.M_22 * temp[2] + m1.M_23 * temp[1]) * inverse_determinant;

 m.M_20 = (m1.M_10 * temp[7] - m1.M_11 * temp[9] + m1.M_13 * temp[11]) * inverse_determinant;
 m.M_21 = (-m1.M_00 * temp[7] + m1.M_01 * temp[9] - m1.M_03 * temp[11]) * inverse_determinant;
 m.M_22 = (m1.M_30 * temp[4] - m1.M_31 * temp[2] + m1.M_33 * temp[0]) * inverse_determinant;
 m.M_23 = (-m1.M_20 * temp[4] + m1.M_21 * temp[2] - m1.M_23 * temp[0]) * inverse_determinant;

 m.M_30 = (-m1.M_10 * temp[8] + m1.M_11 * temp[10] - m1.M_12 * temp[11]) * inverse_determinant;
 m.M_31 = (m1.M_00 * temp[8] - m1.M_01 * temp[10] + m1.M_02 * temp[11]) * inverse_determinant;
 m.M_32 = (-m1.M_30 * temp[3] + m1.M_31 * temp[1] - m1.M_32 * temp[0]) * inverse_determinant;
 m.M_33 = (m1.M_20 * temp[3] - m1.M_21 * temp[1] + m1.M_22 * temp[0]) * inverse_determinant;
}


GPX::Matrix4x4 GPX::Invert(Matrix4x4 m) {
	Matrix4x4 out;
	GPX::Invert(out, m);
	return out;
}


float GPX::Determinant(GPX::Matrix4x4 m) {
	return ((m.M_00 * m.M_11 - m.M_10 * m.M_01)
	     * (m.M_22 * m.M_33 - m.M_32 * m.M_23) 
	     - (m.M_00 * m.M_12 - m.M_10 * m.M_02) 
	     * (m.M_21 * m.M_33 - m.M_31 * m.M_23) 
	     + (m.M_00 * m.M_13 - m.M_10 * m.M_03) 
	     * (m.M_21 * m.M_32 - m.M_31 * m.M_22) 
	     + (m.M_01 * m.M_12 - m.M_11 * m.M_02) 
	     * (m.M_20 * m.M_33 - m.M_30 * m.M_23) 
	     - (m.M_01 * m.M_13 - m.M_11 * m.M_03) 
	     * (m.M_20 * m.M_32 - m.M_30 * m.M_22) 
	     + (m.M_02 * m.M_13 - m.M_12 * m.M_03) 
	     * (m.M_20 * m.M_31 - m.M_30 * m.M_21));
}


void GPX::Multiply(Matrix4x4& m, Matrix4x4 a, Matrix4x4 b) {
	m.M_00 = a.M_00 * b.M_00 + a.M_10 * b.M_01 + a.M_20 * b.M_02 + a.M_30 * b.M_03;
	m.M_10 = a.M_00 * b.M_10 + a.M_10 * b.M_11 + a.M_20 * b.M_12 + a.M_30 * b.M_13;
	m.M_20 = a.M_00 * b.M_20 + a.M_10 * b.M_21 + a.M_20 * b.M_22 + a.M_30 * b.M_23;
	m.M_30 = a.M_00 * b.M_30 + a.M_10 * b.M_31 + a.M_20 * b.M_32 + a.M_30 * b.M_33;

	m.M_01 = a.M_01 * b.M_00 + a.M_11 * b.M_01 + a.M_21 * b.M_02 + a.M_31 * b.M_03;
	m.M_11 = a.M_01 * b.M_10 + a.M_11 * b.M_11 + a.M_21 * b.M_12 + a.M_31 * b.M_13;
	m.M_21 = a.M_01 * b.M_20 + a.M_11 * b.M_21 + a.M_21 * b.M_22 + a.M_31 * b.M_23;
	m.M_31 = a.M_01 * b.M_30 + a.M_11 * b.M_31 + a.M_21 * b.M_32 + a.M_31 * b.M_33;

	m.M_02 = a.M_02 * b.M_00 + a.M_12 * b.M_01 + a.M_22 * b.M_02 + a.M_32 * b.M_03;
	m.M_12 = a.M_02 * b.M_10 + a.M_12 * b.M_11 + a.M_22 * b.M_12 + a.M_32 * b.M_13;
	m.M_22 = a.M_02 * b.M_20 + a.M_12 * b.M_21 + a.M_22 * b.M_22 + a.M_32 * b.M_23;
	m.M_32 = a.M_02 * b.M_30 + a.M_12 * b.M_31 + a.M_22 * b.M_32 + a.M_32 * b.M_33;

	m.M_03 = a.M_03 * b.M_00 + a.M_13 * b.M_01 + a.M_23 * b.M_02 + a.M_33 * b.M_03;
	m.M_13 = a.M_03 * b.M_10 + a.M_13 * b.M_11 + a.M_23 * b.M_12 + a.M_33 * b.M_13;
	m.M_23 = a.M_03 * b.M_20 + a.M_13 * b.M_21 + a.M_23 * b.M_22 + a.M_33 * b.M_23;
	m.M_33 = a.M_03 * b.M_30 + a.M_13 * b.M_31 + a.M_23 * b.M_32 + a.M_33 * b.M_33;
}


void GPX::Multiply(Vector4& v, Matrix4x4 a, Vector4 b) {
	v.X = a.M_00 * b.X + a.M_01 * b.Y + a.M_02 * b.Z + a.M_03 * b.W;
 v.Y = a.M_10 * b.X + a.M_11 * b.Y + a.M_12 * b.Z + a.M_13 * b.W;
	v.Z = a.M_20 * b.X + a.M_21 * b.Y + a.M_22 * b.Z + a.M_23 * b.W;
	v.W = a.M_30 * b.X + a.M_31 * b.Y + a.M_32 * b.Z + a.M_33 * b.W;
}


GPX::Matrix4x4 GPX::Multiply(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 out;
	GPX::Multiply(out, a, b);
	return out;
}


GPX::Vector4 GPX::Multiply(Matrix4x4 a, Vector4 b) {
	Vector4 out;
	GPX::Multiply(out, a, b);
	return out;
}


void GPX::EulerAngle(Matrix4x4& m, float pitch, float yaw, float roll) {
 float radians = yaw * 57.2957801819;
 const float cp = GPX::Cos(radians);
 const float sp = GPX::Sin(radians);
  radians = pitch * 57.2957801819;
 const float sr = GPX::Sin(radians);
 const float cr = GPX::Cos(radians);
  radians = roll * 57.2957801819;
 const float sy = GPX::Sin(radians);
 const float cy = GPX::Cos(radians);
//calculate to matrix
  m.M_00 = cp * cy;
  m.M_10 = (sr * sp * cy) - (cr * sy);
  m.M_20 = (cr * sp * cy) + (sr * sy);
  m.M_01 = cp * sy;
  m.M_11 = (sr * sp * sy) + (cr * cy);
  m.M_21 = (cr * sp * sy) - (sr * cy);
  m.M_02 = -sp;
  m.M_12 = sr * cp;
  m.M_22 = cr * cp;
}

