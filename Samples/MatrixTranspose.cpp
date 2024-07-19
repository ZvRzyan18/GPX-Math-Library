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
 
  Translate(m1, 5, 6);
  
  //GPX::Transpose() function 1
  m2 = Transpose(m1);
  
  //GPX::Transpose() function 2
  Transpose(m2, m1);
  
  Print(m2);
 
 cout << endl << endl;



/*
 Matrix4x4
*/

 Matrix4x4 m3, m4;
 
  Translate(m3, 5, 6, 7);
  
  //GPX::Transpose() function 1
  m4 = Transpose(m3);
  
  //GPX::Transpose() function 2
  Transpose(m4, m3);
  
  Print(m4);



	return 0;
}

