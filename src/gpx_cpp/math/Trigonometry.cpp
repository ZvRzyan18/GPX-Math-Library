/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Trigonometry.cpp
*/
#include "gpx_cpp/math/Trigonometry.hpp"
#include "gpx_cpp/math/MathUtils.hpp"


float GPX::Sin(float theta) noexcept {
 //sine taylor series
 const float x = GPX::Mod(theta, GPX::PI_2);
 const float x_squared = x * x;
 float result = 0;
 float sign = 1;
 float pow = x;
 float factorial = 1;
 
 //term 1
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 6;
 
 //term 2
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 20;
 
 //term 3
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 42;
 
 //term 4
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 72;
 
 //term 5
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 110;
 
 //term 6
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 156;

 //term 7
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 210;
 
 //term 8
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 272;
 
 //term 9
 result += (sign * pow) / factorial;
 sign *= -1.0;
 pow *= x_squared;
 factorial *= 342;
 
 //term 10
 result += (sign * pow) / factorial;
 
 return result;
}


float GPX::Cos(float theta) noexcept {
	//cosine taylor series
 const float x = GPX::Mod(theta, GPX::PI_2);
 const float x_squared = x * x;
 float result = 0.0;
 float sign = 1.0;
 float pow = 1.0;
 float factorial = 1.0;
 
 //term 1
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 2;
 
 //term 2
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 12;
 
 //term 3
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 30;
 
 //term 4
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 56;
 
 //term 5
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 90;
 
 //term 6
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 132;
 
 //term 7
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 182;
 
 //term 8
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 240;
 
 //term 9
 result += (sign * pow) / factorial;
 sign *= -1.0;  
 pow *= x_squared;
 factorial *= 306;
 
 //term 10
 result += (sign * pow) / factorial;
 
 return result;
}


float GPX::Tan(float theta) noexcept {
	return GPX::Sin(theta) / GPX::Cos(theta);
}

