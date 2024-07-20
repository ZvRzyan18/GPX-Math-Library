#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Matrix.hpp"

using namespace GPX;
using namespace std;

int main() {

/*
 Matrix3x3
*/
 float a_array[9];
 //fill array with some value
 fill(a_array, a_array+9, 2.7);
 
 Matrix3x3& b = *reinterpret_cast<Matrix3x3*>(a_array);
 Identity(b);
 
 for(int i = 0; i < 9; i++) {
 	if(i % 3 == 0) cout << endl;
 	cout << a_array[i] << ", ";
 }
 
 

 cout << endl << endl;

/*
 Matrix4x4
*/
 float m_array[16];
 fill(m_array, m_array+16, 3.4);
 
 // convert float array into matrix
 Matrix4x4& m = *reinterpret_cast<Matrix4x4*>(m_array);
 Identity(m);

 // print m_array
 for(int i = 0; i < 16; i++) {
 	if(i % 4 == 0) cout << endl;
 	cout << m_array[i] << ", ";
 }

	return 0;
}
