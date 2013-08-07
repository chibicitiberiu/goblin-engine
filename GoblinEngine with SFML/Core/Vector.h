/*
 * Vector.hpp
 *
 *  Created on: Sep 3, 2012
 *      Author: Tibi
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace Goblin {

const float PI_F = 3.141592653589793f;

/************************************************
 * Forward declarations                         *
 ************************************************/
class Vector3;
class Vector4;

/************************************************
 * Vector with 2 components                     *
 ************************************************/
class Vector2 {
public:
	// Static constants
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 UnitX;
	static const Vector2 UnitY;

	// Components
	float X, Y;

	// Constructors
	Vector2();
	Vector2(const float& all);
	Vector2(const float& x, const float& y);

	// Mathematical operators
	Vector2 operator+ (const Vector2 &a) const;
	Vector2 operator- (const Vector2 &a) const;
	Vector2 operator* (const Vector2 &a) const;
	Vector2 operator* (const float &a) const;
	friend Vector2 operator* (const float &a, const Vector2 &b);
	Vector2 operator/ (const Vector2 &a) const;
	Vector2 operator/ (const float &a) const;
	friend Vector2 operator/ (const float &a, const Vector2 &b) ;
	Vector2 operator- () const;

	Vector2& operator+= (const Vector2& a);
	Vector2& operator-= (const Vector2& a);
	Vector2& operator*= (const Vector2& a);
	Vector2& operator*= (const float& a);
	Vector2& operator/= (const Vector2& a);
	Vector2& operator/= (const float& a);

	// Comparison operators
	bool operator== (const Vector2 &a) const;
	bool operator!= (const Vector2 &a) const;

	// Assignment operator
	Vector2& operator= (const Vector2 &a);

	// Conversions
	Vector3 toVector3() const;
	Vector3 toVector3(const float& z) const;
	Vector4 toVector4() const;
	Vector4 toVector4(const float& z, const float& w) const;

	// Misc
	float getLength() const;
	float getLengthSquared() const;
	Vector2 negate() const;
	Vector2 normalize() const;

	// Static mathematical operations
	static Vector2 add (const Vector2& a, const Vector2& b);
	static Vector2 subtract (const Vector2& a, const Vector2& b);
	static Vector2 multiply (const Vector2& a, const Vector2& b);
	static Vector2 multiply (const Vector2& a, const float& b);
	static Vector2 multiply (const float& a, const Vector2& b);
	static Vector2 divide (const Vector2& a, const Vector2& b);
	static Vector2 divide (const Vector2& a, const float& b);
	static Vector2 divide (const float& a, const Vector2& b);

	static float dot (const Vector2& a, const Vector2& b);
	static float distance (const Vector2& a, const Vector2& b);
	static float distanceSquared (const Vector2& a, const Vector2& b);
	static Vector2 reflect (const Vector2& a, const Vector2& normal);

	static Vector2 lerp (const Vector2& a, const Vector2 &b, const float &t);
	static Vector2 cosInterpolation (const Vector2& a, const Vector2 &b, const float &t);
	static Vector2 polyInterpolation (const Vector2& a, const Vector2 &b, const float &t);

	static Vector2 getMax (const Vector2& a, const Vector2& b);
	static Vector2 getMin (const Vector2& a, const Vector2& b);
};


/************************************************
 * Vector with 3 components                     *
 ************************************************/
class Vector3 {
public:
	// Static constants
	static const Vector3 Zero;
	static const Vector3 One;
	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;
	static const Vector3 Forward;
	static const Vector3 Backward;
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Left;
	static const Vector3 Right;

	// Components
	float X, Y, Z;

	// Constructors
	Vector3();
	Vector3(const float& all);
	Vector3(const float& x, const float& y, const float& z);
	Vector3(const Vector2 &a);
	Vector3(const Vector2 &a, const float& z);

	// Mathematical operators
	Vector3 operator+ (const Vector3 &a) const;
	Vector3 operator- (const Vector3 &a) const;
	Vector3 operator* (const Vector3 &a) const;
	Vector3 operator* (const float &a) const;
	friend Vector3 operator* (const float &a, const Vector3& b);
	Vector3 operator/ (const Vector3 &a) const;
	Vector3 operator/ (const float &a) const;
	friend Vector3 operator/ (const float &a, const Vector3& b);
	Vector3 operator- () const;

	Vector3& operator+= (const Vector3& a);
	Vector3& operator-= (const Vector3& a);
	Vector3& operator*= (const Vector3& a);
	Vector3& operator*= (const float& a);
	Vector3& operator/= (const Vector3& a);
	Vector3& operator/= (const float& a);

	// Comparison operators
	bool operator== (const Vector3 &a) const;
	bool operator!= (const Vector3 &a) const;

	// Assignment operator
	Vector3& operator= (const Vector3 &a);

	// Conversions
	Vector2 toVector2() const;
	Vector4 toVector4() const;
	Vector4 toVector4(const float& w) const;

	// Misc
	float getLength() const;
	float getLengthSquared() const;
	Vector3 negate() const;
	Vector3 normalize() const;

	// Static mathematical operations
	static Vector3 add (const Vector3& a, const Vector3& b);
	static Vector3 subtract (const Vector3& a, const Vector3& b);
	static Vector3 multiply (const Vector3& a, const Vector3& b);
	static Vector3 multiply (const Vector3& a, const float& b);
	static Vector3 multiply (const float& a, const Vector3& b);
	static Vector3 divide (const Vector3& a, const Vector3& b);
	static Vector3 divide (const Vector3& a, const float& b);
	static Vector3 divide (const float& a, const Vector3& b);

	static Vector3 cross(const Vector3& a, const Vector3& b);
	static float dot (const Vector3& a, const Vector3& b);
	static float distance (const Vector3& a, const Vector3& b);
	static float distanceSquared (const Vector3& a, const Vector3& b);
	static Vector3 reflect (const Vector3& a, const Vector3& normal);


	static Vector3 lerp (const Vector3& a, const Vector3 &b, const float &t);

	static Vector3 getMax (const Vector3& a, const Vector3& b);
	static Vector3 getMin (const Vector3& a, const Vector3& b);
};


/************************************************
 * Vector with 4 components                     *
 ************************************************/
class Vector4 {
public:

	// Static constants
	static const Vector4 Zero;
	static const Vector4 One;
	static const Vector4 UnitX;
	static const Vector4 UnitY;
	static const Vector4 UnitZ;
	static const Vector4 UnitW;

	// Components
	float X, Y, Z, W;

	// Constructor
	Vector4();
	Vector4(const float& all);
	Vector4(const float& x, const float& y, const float& z, const float& w);
	Vector4(const Vector2 &a);
	Vector4(const Vector2 &a, const float& z);
	Vector4(const Vector2 &a, const float& z, const float& w);
	Vector4(const Vector3 &a);
	Vector4(const Vector3 &a, const float& w);

	// Mathematical operators
	Vector4 operator+ (const Vector4 &a) const;
	Vector4 operator- (const Vector4 &a) const;
	Vector4 operator* (const Vector4 &a) const;
	Vector4 operator* (const float &a) const;
	friend Vector4 operator* (const float &a, const Vector4& b);
	Vector4 operator/ (const Vector4 &a) const;
	Vector4 operator/ (const float &a) const;
	friend Vector4 operator/ (const float &a, const Vector4& b);
	Vector4 operator- () const;

	Vector4& operator+= (const Vector4& a);
	Vector4& operator-= (const Vector4& a);
	Vector4& operator*= (const Vector4& a);
	Vector4& operator*= (const float& a);
	Vector4& operator/= (const Vector4& a);
	Vector4& operator/= (const float& a);

	// Comparison operators
	bool operator== (const Vector4 &a) const;
	bool operator!= (const Vector4 &a) const;

	// Assignment operator
	Vector4& operator= (const Vector4 &a);

	// Conversions
	Vector2 toVector2() const;
	Vector3 toVector3() const;

	// Misc
	float getLength() const;
	float getLengthSquared() const;
	Vector4 negate() const;
	Vector4 normalize() const;

	// Static mathematical operations
	static Vector4 add (const Vector4& a, const Vector4& b);
	static Vector4 subtract (const Vector4& a, const Vector4& b);
	static Vector4 multiply (const Vector4& a, const Vector4& b);
	static Vector4 multiply (const Vector4& a, const float& b);
	static Vector4 multiply (const float& a, const Vector4& b);
	static Vector4 divide (const Vector4& a, const Vector4& b);
	static Vector4 divide (const Vector4& a, const float& b);
	static Vector4 divide (const float& a, const Vector4& b);

	static float dot (const Vector4& a, const Vector4& b);
	static float distance (const Vector4& a, const Vector4& b);
	static float distanceSquared (const Vector4& a, const Vector4& b);
	static Vector4 reflect (const Vector4& a, const Vector4& normal);

	static Vector4 lerp (const Vector4& a, const Vector4& b, const float& t);

	static Vector4 getMax (const Vector4& a, const Vector4& b);
	static Vector4 getMin (const Vector4& a, const Vector4& b);
};

}  // namespace Goblin


#endif /* VECTOR_HPP_ */
