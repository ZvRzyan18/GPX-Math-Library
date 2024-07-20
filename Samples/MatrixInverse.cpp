/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MatrixInverse.cpp
*/

#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Matrix.hpp"

using namespace GPX;
using namespace std;

int main() {
/*
 Matrix3x3
*/

 Matrix3x3 m1, m2;
 
  SetRotate(m1, 12.3f);
  Translate(m1, 4, 6);
  
  //GPX::Invert() function 1
  m2 = Invert(m1);
  
  //GPX::Invert() function 2
  Invert(m2, m1);
  
 cout << "Inverted Matrix3x3:\n";
 Print(m2);
 
 // multiply to its original value 
 // the output is EQUAL or CLOSE to identity matrix
 cout << endl;
 Print(m2 * m1); 
 
 
 
/*
 Matrix4x4
*/



 cout << endl << endl;
 

 Matrix4x4 m3, m4;
 
  Scale(m3, 4, 5, 6);
  Translate(m3, 8, 2, 1);
  
  //GPX::Invert() function 1
  m4 = Invert(m3);
 
  //GPX::Invert() function 2
  Invert(m4, m3);
  
 cout << "Inverted Matrix4x4:\n";
 Print(m4);
 
 // multiply to its original value 
 // the output is EQUAL or CLOSE to identity matrix
 cout << endl;
 Print(m4 * m3);
 
 
 return 0;
}
