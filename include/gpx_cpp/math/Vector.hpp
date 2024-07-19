/*
* This file is part of GPX Project under BSD 3-Clause License
* see LICENSE.txt
*/

/*
 file name : Vector.hpp
*/

#ifndef GPX_VECTOR_HPP
#define GPX_VECTOR_HPP


namespace GPX {
/*
 classes
*/
 class Vector2;
 class Vector3;
 class Vector4;


/*
 Vector2 class
*/
	class Vector2 {
		public:
		float X, Y;
		
		Vector2();
		Vector2(Vector3 vector);
		Vector2(Vector4 vector);
		Vector2(float x, float y);
		Vector2(float* array);

/*
 assign operator
*/
		void operator=(Vector2 vector);
		void operator=(Vector3 vector);
		void operator=(Vector4 vector);
		
/*
 compare operator
*/
		bool operator==(Vector2 vector);
		bool operator!=(Vector2 vector);
		
/*
 arithmetic operator
*/
		Vector2 operator+(Vector2 a);
		Vector2 operator-(Vector2 a);
		Vector2 operator*(Vector2 a);
		Vector2 operator/(Vector2 a);

		Vector2 operator+(float a);
		Vector2 operator-(float a);
		Vector2 operator*(float a);
		Vector2 operator/(float a);
		
		Vector2& operator+=(Vector2 a);
		Vector2& operator-=(Vector2 a);
		Vector2& operator*=(Vector2 a);
		Vector2& operator/=(Vector2 a);
		
		Vector2& operator+=(float a);
		Vector2& operator-=(float a);
		Vector2& operator*=(float a);
		Vector2& operator/=(float a);
		
/*
 element access function
*/
		float& operator[](int index);
		
		int GetSize();
		float* GetData();
		float* begin();
		float* end();
	};

/*
 Vector3 class
*/
	class Vector3 {
		public:
		float X, Y, Z;
		
		Vector3();
		Vector3(Vector2 vector);
		Vector3(Vector4 vector);
		Vector3(float x, float y, float z);
		Vector3(float* array);
	
/*
 assign operator
*/
	 void	operator=(Vector2 vector);
	 void operator=(Vector3 vector);
	 void operator=(Vector4 vector);
	 
/*
 comapare operator
*/
		bool operator==(Vector3 vector);
		bool operator!=(Vector3 vector);

/*
 arithmetic operator
*/
		Vector3 operator+(Vector3 a);
		Vector3 operator-(Vector3 a);
		Vector3 operator*(Vector3 a);
		Vector3 operator/(Vector3 a);

		Vector3 operator+(float a);
		Vector3 operator-(float a);
		Vector3 operator*(float a);
		Vector3 operator/(float a);
		
		Vector3& operator+=(Vector3 a);
		Vector3& operator-=(Vector3 a);
		Vector3& operator*=(Vector3 a);
		Vector3& operator/=(Vector3 a);
		
		Vector3& operator+=(float a);
		Vector3& operator-=(float a);
		Vector3& operator*=(float a);
		Vector3& operator/=(float a);

/*
 element access function
*/
		float& operator[](int index);
		
		int GetSize();
		float* GetData();
		float* begin();
		float* end();
	};

/*
 Vector4 class
*/
	class Vector4 {
		public:
		float X, Y, Z, W;
		
		Vector4();
		Vector4(Vector2 vector);
		Vector4(Vector3 vector);
		Vector4(float x, float y, float z, float w);
		Vector4(float* array);

	 void	operator=(Vector2 vector);
	 void operator=(Vector3 vector);
	 void operator=(Vector4 vector);
	 
		bool operator==(Vector4 vector);
		bool operator!=(Vector4 vector);
		
		Vector4 operator+(Vector4 a);
		Vector4 operator-(Vector4 a);
		Vector4 operator*(Vector4 a);
		Vector4 operator/(Vector4 a);

		Vector4 operator+(float a);
		Vector4 operator-(float a);
		Vector4 operator*(float a);
		Vector4 operator/(float a);
		
		Vector4& operator+=(Vector4 a);
		Vector4& operator-=(Vector4 a);
		Vector4& operator*=(Vector4 a);
		Vector4& operator/=(Vector4 a);
		
		Vector4& operator+=(float a);
		Vector4& operator-=(float a);
		Vector4& operator*=(float a);
		Vector4& operator/=(float a);

/*
 element access function
*/
		float& operator[](int index);
		
		int GetSize();
		float* GetData();
		float* begin();
		float* end();
	};


/*
 other vector functions
*/

/*
 vector dot product
*/
	float Dot(Vector2 a, Vector2 b);
	float Dot(Vector3 a, Vector3 b);
	float Dot(Vector4 a, Vector4 b);

/*
 vector magnitude
*/
	float Length(Vector2 a);
	float Length(Vector3 a);
	float Length(Vector4 a);

/*
 vector normalize
*/
	void Normalize(Vector2& out, Vector2 a);
	void Normalize(Vector3& out, Vector3 a);
	void Normalize(Vector4& out, Vector4 a);

/*
 vector return normalize 
*/
 Vector2 Normalize(Vector2 a);
 Vector3 Normalize(Vector3 a);
 Vector4 Normalize(Vector4 a);

/*
 cross multiplication
*/
 Vector3 Cross(Vector3 a, Vector3 b);
 
 
}

#endif
