/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : TrigonometryFunction.cpp
*/

#include <iostream>
#include "gpx_cpp/math/MathUtils.hpp"
#include "gpx_cpp/math/Trigonometry.hpp"

using namespace GPX;
using namespace std;

int main() {

/*
 GPX::Sin()
*/
 float sin_value = Sin(45 * GPX::PI_RAD);
 cout << "GPX::Sin : " << sin_value << endl;
 //cout << "std::sin : " << sin(45 * GPX::PI_RAD) << endl;
 
/*
 GPX::Cos()
*/
 float cos_value = Cos(120 * GPX::PI_RAD);
 cout << "GPX::Cos : " << cos_value << endl;
 //cout << "std::cos : " << cos(120 * GPX::PI_RAD) << endl;
 
/*
 GPX::Tan()
*/
 float tan_value = Tan(20 * GPX::PI_RAD);
 cout << "GPX::Tan : " << tan_value << endl;
 
/*
 GPX::Asin()
*/
 float asin_value = Asin(Sin(0.2f));
 cout << "GPX::Asin : " << asin_value << endl;

/*
 GPX::Acos()
*/
 float acos_value = Acos(Cos(0.3f));
 cout << "GPX::Acos : " << acos_value << endl;
 
/*
 GPX::Atan()
*/
 float atan_value = Atan(Tan(0.4));
 cout << "GPX::Atan : " << atan_value << endl;


	return 0;
}
