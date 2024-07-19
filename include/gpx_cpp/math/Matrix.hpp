/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Matrix.hpp
*/

#ifndef GPX_MATRIX_HPP
#define GPX_MATRIX_HPP

#include "gpx_cpp/math/Vector.hpp"

namespace GPX {

class Matrix3x3;
class Matrix4x4;

/*
 matrix structure components
*/
 struct Matrix3x3Components {
 	float M_00, M_10, M_20;
	 float M_01, M_11, M_21;
	 float M_02, M_12, M_22;
 };
 
 struct Matrix4x4Components {
 	 float M_00, M_10, M_20, M_30;
  	float M_01, M_11, M_21, M_31;
 	 float M_02, M_12, M_22, M_32;
   float M_03, M_13, M_23, M_33;
 };
 
 
 
/*
 matrix class
*/

 class Matrix3x3 {
  public:
  	float M_00, M_10, M_20;
	  float M_01, M_11, M_21;
	  float M_02, M_12, M_22;

	  Matrix3x3();
	  Matrix3x3(Matrix4x4 m);
	  Matrix3x3(float *array);
   void operator=(Matrix3x3 m);
   void operator=(Matrix4x4 m);
	  GPX::Matrix3x3 operator*(Matrix3x3 m);
	  GPX::Vector3 operator*(Vector3 v);

  	GPX::Matrix3x3 &operator*=(Matrix3x3 m);

	  float &Get(int row, int column);
	  float &operator[](int index);
	  
	  GPX::Matrix3x3Components& GetComponents();

	  int GetSize();
  	float* GetData();
  	float* begin();
  	float* end();
};



 class Matrix4x4 {
  public:
  	float M_00, M_10, M_20, M_30;
  	float M_01, M_11, M_21, M_31;
 	 float M_02, M_12, M_22, M_32;
   float M_03, M_13, M_23, M_33;

  	Matrix4x4();
  	Matrix4x4(Matrix3x3 m);
  	Matrix4x4(float *array);
   void operator=(Matrix3x3 m);
   void operator=(Matrix4x4 m);
  	GPX::Matrix4x4 operator*(Matrix4x4 m);
  	GPX::Vector4 operator*(Vector4 v);

	  GPX::Matrix4x4& operator*=(Matrix4x4 m);

  	float &Get(int row, int column);
  	float &operator[](int index);
  	
  	GPX::Matrix4x4Components& GetComponents();

  	int GetSize();
	  float* GetData();
  	float* begin();
  	float* end();
};

/*
 Matrix3x3 functions
*/
 void Identity(Matrix3x3& m);
 void MultiplyTranslate(Matrix3x3& m, Matrix3x3 m1, float x, float y);
 void Translate(Matrix3x3& m, float x, float y);
 void MultiplyScale(Matrix3x3 &m, Matrix3x3 m1, float x, float y);
 void Scale(Matrix3x3& m, float x, float y);
 void SetRotate(Matrix3x3& m, float angle);
 void Rotate(Matrix3x3& m, Matrix3x3 m1, float angle);
 void Transpose(Matrix3x3& m, Matrix3x3 m1);
 GPX::Matrix3x3 Transpose(Matrix3x3 m);
 void Invert(Matrix3x3& m, Matrix3x3 m1);
 GPX::Matrix3x3 Invert(Matrix3x3 m);
 float Determinant(GPX::Matrix3x3 m);
 void Multiply(Matrix3x3& m, Matrix3x3 a, Matrix3x3 b);
 void Multiply(Vector3& v, Matrix3x3 a, Vector3 b);
 GPX::Matrix3x3 Multiply(Matrix3x3 a, Matrix3x3 b);
 GPX::Vector3 Multiply(Matrix3x3 a, Vector3 b);

/*
 Matrix4x4 functions
*/
 void Identity(Matrix4x4& m);
 void MultiplyTranslate(Matrix4x4& m, Matrix4x4 m1, float x, float y, float z);
 void Translate(Matrix4x4& m, float x, float y, float z);
 void MultiplyScale(Matrix4x4 &m, Matrix4x4 m1, float x, float y, float z);
 void Scale(Matrix4x4& m, float x, float y, float z);

 void SetRotateX(Matrix4x4& m, float angle);
 void RotateX(Matrix4x4& m, Matrix4x4 m1, float angle);

 void SetRotateY(Matrix4x4& m, float angle);
 void RotateY(Matrix4x4& m, Matrix4x4 m1, float angle);

 void SetRotateZ(Matrix4x4& m, float angle);
 void RotateZ(Matrix4x4& m, Matrix4x4 m1, float angle);

 void Transpose(Matrix4x4& m, Matrix4x4 m1);
 GPX::Matrix4x4 Transpose(Matrix4x4 m);
 void Invert(Matrix4x4& m, Matrix4x4 m1);
 float Determinant(GPX::Matrix4x4 m);
 GPX::Matrix4x4 Invert(Matrix4x4 m);
 void Multiply(Matrix4x4& m, Matrix4x4 a, Matrix4x4 b);
 void Multiply(Vector4& v, Matrix4x4 a, Vector4 b);
 GPX::Matrix4x4 Multiply(Matrix4x4 a, Matrix4x4 b);
 GPX::Vector4 Multiply(Matrix4x4 a, Vector4 b);
 
 void EulerAngle(Matrix4x4& m, float pitch, float yaw, float roll);
} // namespace GPX

#endif
