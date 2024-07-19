/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Trigonometry.cpp
*/
#include "gpx_cpp/math/Trigonometry.hpp"
#include "gpx_cpp/math/MathUtils.hpp"

/*
 Taylor Series Sine/Cosine Implementation
*/

/*
 sine formula

 sin(x) = x - (x^3 / 3!) + (x^5 / 5!) - (x^7 / 7!) + (x^9 / 9!) ....
*/
float GPX::Sin(float theta) noexcept {
 const float x = GPX::Mod(theta, GPX::PI_2);
 const float x_squared = x * x;
 float result = 0.0f;
 float pow = x;
 float factorial = 1.0f;
 
 //term 1
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 6;
 
 //term 2
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 20;
 
 //term 3
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 42;
 
 //term 4
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 72;
 
 //term 5
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 110;
 
 //term 6
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 156;

 //term 7
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 210;
 
 //term 8
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 272;
 
 //term 9
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 342;
 
 //term 10
 result -= pow / factorial;

 //...
 return result;
}


/*
 cosine formula
 
 cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) - (x^6 / 6!) + (x^8 / 8!) ....
*/
float GPX::Cos(float theta) noexcept {
 const float x = GPX::Mod(theta, GPX::PI_2);
 const float x_squared = x * x;
 float result = 0.0f;
 float pow = 1.0f;
 float factorial = 1.0f;
 
 //term 1
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 2;
 
 //term 2
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 12;
 
 //term 3
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 30;
 
 //term 4
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 56;
 
 //term 5
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 90;
 
 //term 6
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 132;
 
 //term 7
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 182;
 
 //term 8
 result -= pow / factorial;
 pow *= x_squared;
 factorial *= 240;
 
 //term 9
 result += pow / factorial;
 pow *= x_squared;
 factorial *= 306;
 
 //term 10
 result -= pow / factorial;

 //...
 return result;
}

/*
 tangent formula
 
 tan(x) = sin(x) / cos(x)
*/
float GPX::Tan(float theta) noexcept {
	return GPX::Sin(theta) / GPX::Cos(theta);
}
