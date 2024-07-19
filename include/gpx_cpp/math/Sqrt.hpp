/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Sqrt.hpp
*/

#ifndef GPX_SQRT_HPP
#define GPX_SQRT_HPP

namespace GPX {


/*
 sqrt approximation
*/
float Sqrt(float x) noexcept;


/*
 medium precision sqrt
*/
float Sqrt_MP(float x) noexcept;


/*
 high precision sqrt
*/
float Sqrt_HP(float x) noexcept;


/*
 Newton-Raphson iteration 
*/
float SqrtIteration(float x, const float base_number, int iteration) noexcept;


/*
 inverse square root
*/
float InvSqrt(float x) noexcept;


/*
 medium precision inverse sqrt
*/
float InvSqrt_MP(float x) noexcept;

/*
 high precision inverse sqrt
*/
float InvSqrt_HP(float x) noexcept;


}

#endif
