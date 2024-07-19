/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Sqrt.cpp
*/

#include "gpx_cpp/math/Sqrt.hpp"
#include <stdint.h>


/*
 base sqrt approximation
*/
float GPX::Sqrt(float x) noexcept {
	const uint32_t tmp = *(uint32_t*)&x;
 const uint32_t tmp1 = 1065135222 + tmp;
 const uint32_t tmp2 = tmp1 >> 1;
 return *(float*)&tmp2;
}


/*
 medium precision sqrt
*/
float GPX::Sqrt_MP(float x) noexcept {
 float current =  GPX::Sqrt(x);
	float square_root = 0;

 // 2 iteration
	square_root =  0.5 * (current + x / current);
 current = square_root;
 
 square_root =  0.5 * (current + x / current);

 return square_root;
}



/*
 high precision sqrt
*/
float GPX::Sqrt_HP(float x) noexcept {
 float current = GPX::Sqrt(x);
	float square_root = 0;

 // 4 iteration
	square_root =  0.5 * (current + x / current);
 current = square_root;
 
 square_root =  0.5 * (current + x / current);
 current = square_root;
 
 square_root =  0.5 * (current + x / current);
 current = square_root;
 
 square_root =  0.5 * (current + x / current);

 return square_root;
}


/*
 Newton-Raphson iteration 
*/
float GPX::SqrtIteration(float x, const float base_number, int iteration) noexcept {
	float current = x;
	float square_root = 0;
	
	for(int i = 0; i < iteration; i++) {
		square_root =  0.5 * (current + base_number / current);
  current = square_root;
	}
	
	return square_root;
}



/*
 inverse sqrt
*/
float GPX::InvSqrt(float x) noexcept {
	return 1.0 / GPX::Sqrt(x);
}

/*
 medium precision inverse sqrt
*/
float GPX::InvSqrt_MP(float x) noexcept {
	return 1.0 / GPX::Sqrt_MP(x);
}

/*
 high precision inverse sqrt
*/
float GPX::InvSqrt_HP(float x) noexcept {
	return 1.0 / GPX::Sqrt_HP(x);
}

