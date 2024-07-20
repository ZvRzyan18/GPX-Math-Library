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
 
              x^3   x^5   x^7   x^9
 sin(x) = x - ___ + ___ - ___ + ___ ...
               3!    5!    7!    9!

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

              x^2   x^4   x^6   x^8
 cos(x) = 1 - ___ + ___ - ___ + ___ ...
               2!    4!    6!    8!
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
 
          sin(x)
 tan(x) = ______
          cos(x)
*/
float GPX::Tan(float theta) noexcept {
	return GPX::Sin(theta) / GPX::Cos(theta);
}


/*
 Arc Sine formula
 
 asin(x) = x + (1/2) * (x^3 / 3) + (1*3 / 2*4) * (x^5 / 5) + (1*3*5 / 2*4*6) * (x^7 / 7) ...

               1     x^3        1*3   x^5        1*3*5   x^7
 asin(x) = x + __ *  ____   +   ___ * ___   +    _____ * ___  ....
               2      3         2*4    5         2*4*6    7
*/
float GPX::Asin(float x) noexcept {
	const float x_squared = x * x;
	float result = x;
 float pow = x * x_squared;
	
	//term 1
	       /* (1/2) */
	result += 0.5f * (pow * 0.33333f);
	pow *= x_squared;
	
	//term 2
	       /* ((1*3)/(2*4)) */
	result += 0.375f * (pow * 0.20000f);
	pow *= x_squared;
	
	//term 3
	       /*  ((1*3*5)/(2*4*6)) */
	result += 0.3125f * (pow * 0.14286f);
	pow *= x_squared;
	
	//term 4
	       /* ((1*3*5*7)/(2*4*6*8)) */
	result += 0.2734375f * (pow * 0.11111f);
	pow *= x_squared;
	
	//term 5
	       /* (1*3*5*7*9)/(2*4*6*8*10)) */
	result += 0.24609375f * (pow * 0.09091f);
	pow *= x_squared;
	
	//term 6
	       /* ((1*3*5*7*9*11)/(2*4*6*8*10*12)) */
	result += 0.2255859375f * (pow * 0.07692f);
	pow *= x_squared;
	
	//term 7
	       /* ((1*3*5*7*9*11*13)/(2*4*6*8*10*12*14)) */
	result += 0.20947265625f * (pow * 0.06667f);
	pow *= x_squared;
	
	//term 8
	       /* ((1*3*5*7*9*11*13*15)/(2*4*6*8*10*12*14*16)) */
	result += 0.196380615234375 * (pow * 0.05882f);
	pow *= x_squared;
	
	//term 9
	       /* ((1*3*5*7*9*11*13*15*17)/(2*4*6*8*10*12*14*16*18)) */
	result += 0.1854705810546875f * (pow * 0.05263f);
	
/*
  Newton's method
 
          (sin(y) - x)
  y = y - ____________
            cos(y)
  
  uses 4 iteration for better accurate results
*/
	float final_iter = result;
	
	 final_iter = final_iter - (GPX::Sin(final_iter) - x) / GPX::Cos(final_iter);
  final_iter = final_iter - (GPX::Sin(final_iter) - x) / GPX::Cos(final_iter);

	 final_iter = final_iter - (GPX::Sin(final_iter) - x) / GPX::Cos(final_iter);
  final_iter = final_iter - (GPX::Sin(final_iter) - x) / GPX::Cos(final_iter);


	return final_iter;
}


/*
 Arc Cosine formula
           π
 acos(x) = _ - asin(x)
           2
*/
float GPX::Acos(float x) noexcept {
	return GPX::PI_HALF - Asin(x);
}


/*
 Arc Tangent formula
 
 atan(x) = x - (x^3/3) + (x^5/5) - (x^7/7) + (x^9/9) ...

               x^3   x^5   x^7   x^9
 atan(x) = x - ___ + ___ - ___ + ___  ...
                3     5     7     9
*/
float GPX::Atan(float x) noexcept {
	const float x_squared = x * x;
	float result = x;
	float pow = x * x_squared;
	
	//term 1
	result += pow * 0.33333f;
	pow *= x_squared;
	
	//term 2
	result += pow * 0.20000f;
	pow *= x_squared;
	
	//term 3
	result += pow * 0.14286f;
	pow *= x_squared;
	
	//term 4
	result += pow * 0.11111f;
	pow *= x_squared;
	
	//term 5
	result += pow * 0.09091f;
	pow *= x_squared;
	
	//term 6
	result += pow * 0.07692f;
	pow *= x_squared;
	
	//term 7
	result += pow * 0.06667f;
	pow *= x_squared;
	
	//term 8
	result += pow * 0.05882f;
	pow *= x_squared;
	
	//term 9
	result += pow * 0.05263f;
	pow *= x_squared;
	
	//term 10
	result += pow * 0.04762f;
	pow *= x_squared;
	
	//term 11
	result += pow * 0.04348f;
	pow *= x_squared;
	
	//term 12
	result += pow * 0.04000f;
	pow *= x_squared;
	
	//term 13
	result += pow * 0.03704f;
	pow *= x_squared;
	
	//term 14
	result += pow * 0.03448f;
	pow *= x_squared;
	
	//term 15
	result += pow * 0.03226f;
	pow *= x_squared;

	//term 16
	result += pow * 0.03030f;
	pow *= x_squared;
	
/*
  Newton's method
  
             (tan(y) - x)
  y = y - ___________________
          (1.0 + tan(y) ^ 2)
  
  uses 4 iteration for better accurate results
*/

 float tangent;
 float final_iter = result;
 
 tangent = GPX::Tan(final_iter);
 final_iter = final_iter - (tangent - x) / (1.0f + tangent * tangent);

 tangent = GPX::Tan(final_iter);
 final_iter = final_iter - (tangent - x) / (1.0f + tangent * tangent);

 tangent = GPX::Tan(final_iter);
 final_iter = final_iter - (tangent - x) / (1.0f + tangent * tangent);

 tangent = GPX::Tan(final_iter);
 final_iter = final_iter - (tangent - x) / (1.0f + tangent * tangent);


/*
 floating point error
  
  tan(0.73) -> tan(1.0)
*/
 if(x > 1.2f) {
  final_iter /= (1.0856f * final_iter);
  return final_iter;
 }
 
 if(x > 1.0f)  {
  final_iter /= (1.1256f * final_iter);
  return final_iter;
 }
 
 if(x > 0.9f) {
 	final_iter /= (1.3456f * final_iter);
  return final_iter;
 }

	return final_iter;
}



