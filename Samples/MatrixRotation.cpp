/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MatrixRotation.cpp
*/

#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Matrix.hpp"

using namespace GPX;
using namespace std;

int main() {

/*
 Matrix3x3 rotation
*/

  Matrix3x3 m1;
  // rotate (45°)
  SetRotate(m1, 45);
  Print(m1);
  
  
  
  cout << endl << endl;
  
  
  
  
  Matrix3x3 m2;
  //rotate (90°)
  Rotate(m2, m2, 90);
  Print(m2);
  
  
  cout << endl << endl;




/*
 Matrix4x4 rotation
*/

  Matrix4x4 m3, m4, m5;
  
   //rotate x-axis (12°)
   SetRotateX(m3, 12);
   
   //rotate y-axis (120°)
   SetRotateY(m4, 120);
   
   //rotate z-axis (50°)
   SetRotateZ(m5, 50);
   
  Print(m3); cout << endl;
  Print(m4); cout << endl;
  Print(m5); cout << endl;
  
  
  cout << endl << endl;
  
 
 
 
 Matrix4x4 m6, m7, m8;
 
   //rotate x-axis (12°)
   RotateX(m6, m6, 12);
   
   //rotate y-axis (120°)
   RotateY(m7, m7, 120);
   
   //rotate z-axis (50°)
   RotateZ(m8, m8, 50);
   
  Print(m6); cout << endl;
  Print(m7); cout << endl;
  Print(m8); cout << endl;


/*
 euler angle rotation
*/

 cout << endl;

 Matrix4x4 m9;
  
  // pitch (30)
  // yaw   (12)
  // roll  (18)
  EulerAngle(m9, 30, 12, 18);
  
  Print(m9);
  
  
	return 0;
}

