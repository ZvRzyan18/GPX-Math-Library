/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MatrixScale.cpp
*/

#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Matrix.hpp"

using namespace GPX;
using namespace std;

int main() {

/*
 Matrix3x3 scale
*/
 Matrix3x3 m1;
  // scale (5, 6)
  Scale(m1, 5, 6);
  Print(m1);
  
  cout << endl << endl;
  
 /*
  multiply scale 
 */
 Matrix3x3 m2;
 //scale (8, 8)
  MultiplyScale(m2, m2, 8, 8);
  Print(m2);
  

  cout << endl << endl;
 
/*
 Matrix4x4 scale
*/
 Matrix4x4 m3;
  // scale (5, 6, 7)
  Scale(m3, 5, 6, 7);
  Print(m3);
  
  cout << endl << endl;
  
 /*
  multiply scale 
 */
 Matrix4x4 m4;
 //scale (8, 8, 9)
  MultiplyScale(m4, m4, 8, 8, 9);
  Print(m4);
  
  
  
	return 0;
}

