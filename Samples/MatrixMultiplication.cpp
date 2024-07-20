/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MatrixMultiplication.cpp
*/

#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Matrix.hpp"
#include "gpx_cpp/math/Vector.hpp"

using namespace GPX;
using namespace std;

int main() {


/*
 Matrix3x3
*/

 Matrix3x3 m1, m2, m3;
 
 Translate(m1, 7, 8);
 SetRotate(m2, 90);
 
 // * operator
 m3 = m1 * m2;
 
 //GPX::Multiply() function 1
 m3 = Multiply(m1, m2);
 
 //GPX::Multiply() function 2
 Multiply(m3, m1, m2);
 
 Print(m3);
 
 

 cout << endl << endl;


/*
 Matrix 4x4
*/

 Matrix4x4 m4, m5, m6;
 
  Scale(m4, 3, 4, 1);
  Translate(m5, 7, 3, 6);
  
 
 // * operator
 m6 = m4 * m5;
 
 //GPX::Multiply() function 1
 m6 = Multiply(m4, m5);
 
 //GPX::Multiply() function 2
 Multiply(m6, m4, m5);
  
 Print(m6);
 

/*
 Matrix to Vector multiplication
*/

 Matrix3x3 m7;
 
 Vector3 v1, v2;
 
  v1.X = 3;
  v1.Y = 4;
  v1.Z = 5;
  
  Translate(m7, 2, 3);
 
  // * operator
  v2 = m7 * v1;
 
  //GPX::Multiply() function 1
  v2 = Multiply(m7, v1);
  
  //GPX::Multiply() function 2
  Multiply(v1, m7, v1);


  Print(v1); cout << endl;
  Print(v2); cout << endl;
  Print(m7); cout << endl;
  
  
  cout << endl << endl;
  
  
  
  
  
 
 Matrix4x4 m8;
 
 Vector4 v3, v4;
 
  v3.X = 10;
  v3.Y = 11;
  v3.Z = 12;
  v3.W = 88;
  
  Translate(m8, 2, 3, 4);
 
  // * operator
  v4 = m8 * v3;
 
  //GPX::Multiply() function 1
  v4 = Multiply(m8, v3);
  
  //GPX::Multiply() function 2
  Multiply(v4, m8, v3);


  Print(v3); cout << endl;
  Print(v4); cout << endl;
  Print(m8); cout << endl;
  
	return 0;
}

