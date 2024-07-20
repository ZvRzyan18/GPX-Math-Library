/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : QuaternionTransformation.cpp
*/

#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Quaternion.hpp"
#include "gpx_cpp/math/Matrix.hpp"

using namespace GPX;
using namespace std;

int main() {

/*
  Quarernion Euler Angle
*/
 Quaternion q1;

 /*
  pitch (3)
  yaw   (6)
  roll  (8)
 */
 
 //GPX::EulerAngle() function 1
 q1 = EulerAngle(3, 6, 8);
 
 //GPX::EulerAngle() function 2
 EulerAngle(q1, 3, 6, 8);


 Print(q1);
 
 

 cout << endl << endl;
 

/*
  Quaternion Axis Angle
*/
  Quaternion q2;
  
  /*
   rotation 18.32°
   y-axis 
  */
  
  //GPX::AxisAngle() function 1
  q2 = AxisAngle(18.32f, 0, 1, 0);
 
  //GPX::AxisAngle() function 2
  AxisAngle(q2, 18.32f, 0, 1, 0);
  
 Print(q2);
 
 
 
 cout << endl << endl;
 


/*
 Quaternion Multiplication
*/

 Quaternion q3, q4, q5;
 
  AxisAngle(q3, 45, 1, 0, 0);
  AxisAngle(q4, 12.3f, 0, 1, 0);
  
  // * operator
  q5 = q3 * q4;
  
  //GPX::Multiply() function 1
  q5 = Multiply(q3, q4);
  
  //GPX::Multiply() function 2
  Multiply(q5, q3, q4);
  
  Print(q5);
  
  
 cout << endl << endl;


/*
  Quaternion Slerp
*/

 Quaternion q6, q7, q8;
 
  AxisAngle(q6, 11, 0, 0, 1);
  AxisAngle(q7, 3, 0, 1, 0);


  //GPX::Slerp() function 1
  q8 = Slerp(q6, q7, 0.5);
  
  //GPX::Slerp() function 2
  Slerp(q8, q6, q7, 0.5);
  
  
  Print(q8);
  
  
  
 cout << endl << endl;
 
 
/*
 Quaternion Matrix Convertion
*/

 Quaternion q9;
 Matrix3x3 m1;
 Matrix4x4 m2;
  
 
  EulerAngle(q9, 3.4f, 6, 7);
  
  //GPX::ToMatrix3x3 function 1
  m1 = ToMatrix3x3(q9);
  
  //GPX::ToMatrix3x3 function2
  ToMatrix3x3(m1, q9);
  
  //GPX::ToMatrix4x4 function 1
  m2 = ToMatrix4x4(q9);
  
  //GPX::ToMatrix4x4 function2
  ToMatrix4x4(m2, q9);
  
 
 Print(q9); cout << endl;
 Print(m1); cout << endl;
 Print(m2); cout << endl;
  
	return 0;
}

