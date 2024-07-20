
/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : MatrixTranslation.cpp
*/
#include <iostream>
#include "gpx_cpp/math/Matrix.hpp"
#include "gpx_cpp/math/MathUtils.hpp"

using namespace GPX;
using namespace std;


int main() {
 
/*
 translation 
*/
 
 Matrix3x3 m1;
 
 //translate (3, 5)
 Translate(m1, 3, 5);
 Print(m1);
 
 
 cout << endl << endl;
 
/*
 multiply translate
*/
 Matrix3x3 m2;
 
 //translate (2, 3)
 MultiplyTranslate(m2, m2, 2, 3);
 Print(m2);

/*
  Matrix4x4 translation
*/

 Matrix4x4 m3;
 
 //translate (2, 8, 7)
 Translate(m3, 2, 8, 7);
 //print matrix
 Print(m3);
 
 
 cout << endl << endl;
 
/*
 multiply translate
*/
 Matrix4x4 m4;
 //translate (8, 7, 6)
 MultiplyTranslate(m4, m4, 8, 7, 6);
 Print(m4);
 
 return 0;
}

