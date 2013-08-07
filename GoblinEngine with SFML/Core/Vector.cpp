/*
 * Vector.cpp
 *
 *  Created on: Sep 4, 2012
 *      Author: Tibi
 */

#include <algorithm>
#include <cfloat>
#include <cmath>
#include "Vector.h"

#define FLOAT_EQUALS(a,b) (abs((a) - (b)) < FLT_EPSILON)

namespace Goblin {

/************************************************
* Implementations: Vector with 2 components    *
************************************************/
// Static constants
const Vector2 Vector2::Zero (0.0f);
const Vector2 Vector2::One (1.0f);
const Vector2 Vector2::UnitX (1.0f, 0.0f);
const Vector2 Vector2::UnitY (0.0f, 1.0f);

// Constructors
Vector2::Vector2()
{
	this->X = 0.0f;
	this->Y = 0.0f;
}

Vector2::Vector2(const float& all)
{
	this->X = all;
	this->Y = all;
}

Vector2::Vector2(const float& x, const float& y)
{
	this->X = x;
	this->Y = y;
}

// Operators
Vector2 Vector2::operator+ (const Vector2 &a) const
{
	return Vector2(this->X + a.X, this->Y + a.Y);
}

Vector2 Vector2::operator- (const Vector2 &a) const
{
	return Vector2(this->X - a.X, this->Y - a.Y);
}

Vector2 Vector2::operator* (const Vector2 &a) const
{
	return Vector2(this->X * a.X, this->Y * a.Y);
}

Vector2 Vector2::operator* (const float &a) const
{
	return Vector2(this->X * a, this->Y * a);
}

Vector2 operator* (const float &a, const Vector2& b)
{
	return Vector2(a * b.X, a * b.Y);
}

Vector2 Vector2::operator/ (const Vector2 &a) const
{
	return Vector2(this->X / a.X, this->Y / a.Y);
}

Vector2 Vector2::operator/ (const float &a) const
{
	return Vector2(this->X / a, this->Y / a);
}

Vector2 operator/ (const float &a, const Vector2& b)
{
	return Vector2(a / b.X, a / b.Y);
}

Vector2 Vector2::operator- () const
{
	return Vector2(-this->X, -this->Y);
}


Vector2& Vector2::operator+= (const Vector2 &a)
{
	this->X = this->X + a.X;
	this->Y = this->Y + a.Y;

	return *this;
}

Vector2& Vector2::operator-= (const Vector2 &a)
{
	this->X = this->X - a.X;
	this->Y = this->Y - a.Y;

	return *this;
}

Vector2& Vector2::operator*= (const Vector2 &a)
{
	this->X = this->X * a.X;
	this->Y = this->Y * a.Y;

	return *this;
}

Vector2& Vector2::operator*= (const float &a)
{
	this->X = this->X * a;
	this->Y = this->Y * a;

	return *this;
}

Vector2& Vector2::operator/= (const Vector2 &a)
{
	this->X = this->X / a.X;
	this->Y = this->Y / a.Y;

	return *this;
}

Vector2& Vector2::operator/= (const float &a)
{
	this->X = this->X / a;
	this->Y = this->Y / a;

	return *this;
}

// Comparison operators
bool Vector2::operator== (const Vector2 &a) const
{
	return (FLOAT_EQUALS(this->X, a.X) &&
			FLOAT_EQUALS(this->Y, a.Y)) ;
}

bool Vector2::operator!= (const Vector2 &a) const
{
	return !(*this == a);
}

// Assignment operator
Vector2& Vector2::operator= (const Vector2 &a)
{
	if (this != &a)
	{
		this->X = a.X;
		this->Y = a.Y;
	}

	return *this;
}

// Conversions
Vector3 Vector2::toVector3() const
{
	return Vector3(this->X, this->Y, 0.0f);
}

Vector3 Vector2::toVector3(const float& z) const
{
	return Vector3(this->X, this->Y, z);
}

Vector4 Vector2::toVector4() const
{
	return Vector4(this->X, this->Y, 0.0f, 0.0f);
}

Vector4 Vector2::toVector4(const float& z, const float& w) const
{
	return Vector4(this->X, this->Y, z, w);
}

// Misc
float Vector2::getLength() const
{
	return sqrtf((this->X * this->X) + (this->Y * this->Y));
}

float Vector2::getLengthSquared() const
{
	return (this->X * this->X) + (this->Y * this->Y);
}

Vector2 Vector2::negate () const
{
	return Vector2(-this->X, -this->Y);
}

Vector2 Vector2::normalize() const
{
	float len = this->getLength();

	return Vector2(this->X / len, this->Y / len);
}


// Static mathematical operations
Vector2 Vector2::add (const Vector2& a, const Vector2& b)
{
	return Vector2(a.X + b.X, a.Y + b.Y);
}

Vector2 Vector2::subtract (const Vector2& a, const Vector2& b)
{
	return Vector2(a.X - b.X, a.Y - b.Y);
}

Vector2 Vector2::multiply (const Vector2& a, const Vector2& b)
{
	return Vector2(a.X * b.X, a.Y * b.Y);
}

Vector2 Vector2::multiply (const Vector2& a, const float& b)
{
	return Vector2(a.X * b, a.Y * b);
}

Vector2 Vector2::multiply (const float& a, const Vector2& b)
{
	return Vector2(a * b.X, a * b.Y);
}

Vector2 Vector2::divide (const Vector2& a, const Vector2& b)
{
	return Vector2(a.X / b.X, a.Y / b.Y);
}

Vector2 Vector2::divide (const Vector2& a, const float& b)
{
	return Vector2(a.X / b, a.Y / b);
}

Vector2 Vector2::divide (const float& a, const Vector2& b)
{
	return Vector2(a / b.X, a / b.Y);
}

Vector2 Vector2::reflect(const Vector2& a, const Vector2& n)
{
	Vector2 n2 = n.normalize();
	return (a - n2 * 2.0f * Vector2::dot(a, n2));
}

float Vector2::dot (const Vector2& a, const Vector2& b)
{
	return (a.X * b.X) + (a.Y * b.Y);
}

float Vector2::distance (const Vector2& a, const Vector2& b)
{
	return sqrtf((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

float Vector2::distanceSquared (const Vector2& a, const Vector2& b)
{
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

Vector2 Vector2::lerp (const Vector2& a, const Vector2& b, const float &t)
{
	return a * (1 - t) + b * t;
}

Vector2 Vector2::cosInterpolation (const Vector2& a, const Vector2& b, const float &t)
{
	float f = (1 - cosf(t * PI_F)) / 2.0f;
	return a * (1 - f) + b * f;
}

Vector2 Vector2::polyInterpolation (const Vector2& a, const Vector2& b, const float &t)
{
	float f = t * t * (3 - 2 * t);
	return a * (1 - f) + b * f;
}

Vector2 Vector2::getMax (const Vector2& a, const Vector2& b)
{
	return Vector2(std::max(a.X, b.X), std::max(a.Y, b.Y));
}

Vector2 Vector2::getMin (const Vector2& a, const Vector2& b)
{
	return Vector2(std::min(a.X, b.X), std::min(a.Y, b.Y));
}


/************************************************
* Implementations: Vector with 3 components    *
************************************************/
// Static constants
const Vector3 Vector3::Zero (0.0f);
const Vector3 Vector3::One (1.0f);
const Vector3 Vector3::UnitX (1.0f, 0.0f, 0.0f);
const Vector3 Vector3::UnitY (0.0f, 1.0f, 0.0f);
const Vector3 Vector3::UnitZ (0.0f, 0.0f, 1.0f);
const Vector3 Vector3::Forward (0.0f, 0.0f, -1.0f);
const Vector3 Vector3::Backward (0.0f, 0.0f, 1.0f);
const Vector3 Vector3::Up (0.0f, 1.0f, 0.0f);
const Vector3 Vector3::Down (0.0f, -1.0f, 0.0f);
const Vector3 Vector3::Left (-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Right (1.0f, 0.0f, 0.0f);

// Constructors
Vector3::Vector3()
{
	this->X = 0.0f;
	this->Y = 0.0f;
	this->Z = 0.0f;
}

Vector3::Vector3(const float& all)
{
	this->X = all;
	this->Y = all;
	this->Z = all;
}

Vector3::Vector3(const float& x, const float& y, const float& z)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
}

Vector3::Vector3(const Vector2 &a)
{
	X = a.X;
	Y = a.Y;
	Z = 0.0f;
}

Vector3::Vector3(const Vector2 &a, const float& z)
{
	X = a.X;
	Y = a.Y;
	Z = z;
}


// Mathematical operators
Vector3 Vector3::operator+ (const Vector3 &a) const
{
	return Vector3(
			this->X + a.X,
			this->Y + a.Y,
			this->Z + a.Z );
}

Vector3 Vector3::operator- (const Vector3 &a) const
{
	return Vector3(
			this->X - a.X,
			this->Y - a.Y,
			this->Z - a.Z );
}

Vector3 Vector3::operator* (const Vector3 &a) const
{
	return Vector3(
			this->X * a.X,
			this->Y * a.Y,
			this->Z * a.Z );
}

Vector3 Vector3::operator* (const float &a) const
{
	return Vector3(
			this->X * a,
			this->Y * a,
			this->Z * a );
}

Vector3 operator* (const float &a, const Vector3 &b)
{
	return Vector3(
			a * b.X,
			a * b.Y,
			a * b.Z );
}

Vector3 Vector3::operator/ (const Vector3 &a) const
{
	return Vector3(
			this->X / a.X,
			this->Y / a.Y,
			this->Z / a.Z );
}

Vector3 Vector3::operator/ (const float &a) const
{
	return Vector3(
			this->X / a,
			this->Y / a,
			this->Z / a );
}

Vector3 operator/ (const float &a, const Vector3 &b)
{
	return Vector3(
			a / b.X,
			a / b.Y,
			a / b.Z );
}


Vector3 Vector3::operator- () const
{
	return Vector3(-this->X, -this->Y, -this->Z);
}


Vector3& Vector3::operator+= (const Vector3 &a)
{
	this->X = this->X + a.X;
	this->Y = this->Y + a.Y;
	this->Z = this->Z + a.Z;

	return *this;
}

Vector3& Vector3::operator-= (const Vector3 &a)
{
	this->X = this->X - a.X;
	this->Y = this->Y - a.Y;
	this->Z = this->Z - a.Z;

	return *this;
}

Vector3& Vector3::operator*= (const Vector3 &a)
{
	this->X = this->X * a.X;
	this->Y = this->Y * a.Y;
	this->Z = this->Z * a.Z;

	return *this;
}

Vector3& Vector3::operator*= (const float &a)
{
	this->X = this->X * a;
	this->Y = this->Y * a;
	this->Z = this->Z * a;

	return *this;
}

Vector3& Vector3::operator/= (const Vector3 &a)
{
	this->X = this->X / a.X;
	this->Y = this->Y / a.Y;
	this->Z = this->Z / a.Z;

	return *this;
}

Vector3& Vector3::operator/= (const float &a)
{
	this->X = this->X / a;
	this->Y = this->Y / a;
	this->Z = this->Z / a;

	return *this;
}

// Comparison operators
bool Vector3::operator== (const Vector3 &a) const
{
	return (FLOAT_EQUALS(this->X, a.X) &&
			FLOAT_EQUALS(this->Y, a.Y) &&
			FLOAT_EQUALS(this->Z, a.Z));
}

bool Vector3::operator!= (const Vector3 &a) const
{
	return !(*this == a);
}

// Assignment operator
Vector3& Vector3::operator= (const Vector3 &a)
{
	if (this != &a)
	{
		this->X = a.X;
		this->Y = a.Y;
		this->Z = a.Z;
	}
	return *this;
}

// Conversion
Vector2 Vector3::toVector2() const
{
	return Vector2 (this->X, this->Y);
}

Vector4 Vector3::toVector4() const
{
	return Vector4 (this->X, this->Y, this->Z, 0.0f);
}

Vector4 Vector3::toVector4(const float& w) const
{
	return Vector4 (this->X, this->Y, this->Z, w);
}

// Misc
float Vector3::getLength() const
{
	return sqrtf((this->X * this->X) +
				 (this->Y * this->Y) +
				 (this->Z * this->Z));
}

float Vector3::getLengthSquared() const
{
	return (this->X * this->X) +
			(this->Y * this->Y) +
			(this->Z * this->Z);
}

Vector3 Vector3::negate() const
{
	return Vector3(-this->X, -this->Y, -this->Z);
}

Vector3 Vector3::normalize() const
{
	float len = this->getLength();

	return Vector3(this->X / len, this->Y / len, this->Z / len);
}


// Static mathematical operations
Vector3 Vector3::add (const Vector3& a, const Vector3& b)
{
	return Vector3(
			a.X + b.X,
			a.Y + b.Y,
			a.Z + b.Z );
}

Vector3 Vector3::subtract (const Vector3& a, const Vector3& b)
{
	return Vector3(
			a.X - b.X,
			a.Y - b.Y,
			a.Z - b.Z );
}

Vector3 Vector3::multiply (const Vector3& a, const Vector3& b)
{
	return Vector3(
			a.X * b.X,
			a.Y * b.Y,
			a.Z * b.Z );
}

Vector3 Vector3::multiply (const Vector3& a, const float& b)
{
	return Vector3(
			a.X * b,
			a.Y * b,
			a.Z * b );
}

Vector3 Vector3::multiply (const float& a, const Vector3& b)
{
	return Vector3(
			a * b.X,
			a * b.Y,
			a * b.Z );
}

Vector3 Vector3::divide (const Vector3& a, const Vector3& b)
{
	return Vector3(
			a.X / b.X,
			a.Y / b.Y,
			a.Z / b.Z );
}

Vector3 Vector3::divide (const Vector3& a, const float& b)
{
	return Vector3(
			a.X / b,
			a.Y / b,
			a.Z / b );
}

Vector3 Vector3::divide (const float& a, const Vector3& b)
{
	return Vector3(
			a / b.X,
			a / b.Y,
			a / b.Z );
}

Vector3 Vector3::reflect(const Vector3& a, const Vector3& n)
{
	Vector3 n2 = n.normalize();
	return (a - n2 * 2.0f * Vector3::dot(a, n2));
}

Vector3 Vector3::cross (const Vector3& a, const Vector3& b)
{
	return Vector3(
			a.Y * b.Z - a.Z * b.Y,
			a.Z * b.X - a.X * b.Z,
			a.X * b.Y - a.Y * b.X );
}

float Vector3::dot (const Vector3& a, const Vector3& b)
{
	return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
}

float Vector3::distanceSquared (const Vector3& a, const Vector3& b)
{
	return (a.X - b.X) * (a.X - b.X) +
			(a.Y - b.Y) * (a.Y - b.Y) +
			(a.Z - b.Z) * (a.Z - b.Z);
}

Vector3 Vector3::lerp (const Vector3& a, const Vector3& b, const float& t)
{
	return a * (1 - t) + b * t;
}

Vector3 Vector3::getMax (const Vector3& a, const Vector3& b)
{
	return Vector3(
			std::max(a.X, b.X),
			std::max(a.Y, b.Y),
			std::max(a.Z, b.Z) );
}

Vector3 Vector3::getMin (const Vector3& a, const Vector3& b)
{
	return Vector3(
			std::min(a.X, b.X),
			std::min(a.Y, b.Y),
			std::min(a.Z, b.Z) );
}


/************************************************
 * Implementations: Vector with 4 components    *
 ************************************************/
// Static constants
const Vector4 Vector4::Zero (0.0f);
const Vector4 Vector4::One (1.0f);
const Vector4 Vector4::UnitX (1.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::UnitY (0.0f, 1.0f, 0.0f, 0.0f);
const Vector4 Vector4::UnitZ (0.0f, 0.0f, 1.0f, 0.0f);
const Vector4 Vector4::UnitW (0.0f, 0.0f, 1.0f, 0.0f);

// Constructor
Vector4::Vector4()
{
	this->X = 0.0f;
	this->Y = 0.0f;
	this->Z = 0.0f;
	this->W = 0.0f;
}

Vector4::Vector4(const float& all)
{
	this->X = all;
	this->Y = all;
	this->Z = all;
	this->W = all;
}

Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
	this->W = w;
}

Vector4::Vector4(const Vector2 &a)
{
	this->X = a.X;
	this->Y = a.Y;
	this->Z = 0.0f;
	this->W = 0.0f;
}

Vector4::Vector4(const Vector2 &a, const float& z)
{
	this->X = a.X;
	this->Y = a.Y;
	this->Z = z;
	this->W = 0.0f;
}

Vector4::Vector4(const Vector2 &a, const float& z, const float& w)
{
	this->X = a.X;
	this->Y = a.Y;
	this->Z = z;
	this->W = w;
}

Vector4::Vector4(const Vector3 &a, const float& w)
{
	this->X = a.X;
	this->Y = a.Y;
	this->Z = a.Z;
	this->W = w;
}


// Mathematical operators
Vector4 Vector4::operator+ (const Vector4 &a) const
{
	return Vector4(
			this->X + a.X,
			this->Y + a.Y,
			this->Z + a.Z,
			this->W + a.W );
}

Vector4 Vector4::operator- (const Vector4 &a) const
{
	return Vector4(
			this->X - a.X,
			this->Y - a.Y,
			this->Z - a.Z,
			this->W - a.W );
}

Vector4 Vector4::operator* (const Vector4 &a) const
{
	return Vector4(
			this->X * a.X,
			this->Y * a.Y,
			this->Z * a.Z,
			this->W * a.W );
}

Vector4 Vector4::operator* (const float &a) const
{
	return Vector4(
			this->X * a,
			this->Y * a,
			this->Z * a,
			this->W * a );
}

Vector4 operator* (const float &a, const Vector4 &b)
{
	return Vector4(
			a * b.X,
			a * b.Y,
			a * b.Z,
			a * b.W );
}

Vector4 Vector4::operator/ (const Vector4 &a) const
{
	return Vector4(
			this->X / a.X,
			this->Y / a.Y,
			this->Z / a.Z,
			this->W / a.W );
}

Vector4 Vector4::operator/ (const float &a) const
{
	return Vector4(
			this->X / a,
			this->Y / a,
			this->Z / a,
			this->W / a );
}

Vector4 operator/ (const float &a, const Vector4 &b)
{
	return Vector4(
			a / b.X,
			a / b.Y,
			a / b.Z,
			a / b.W );
}

Vector4 Vector4::operator- () const
{
	return Vector4(-this->X, -this->Y, -this->Z, -this->W);
}


Vector4& Vector4::operator+= (const Vector4 &a)
{
	this->X = this->X + a.X;
	this->Y = this->Y + a.Y;
	this->Z = this->Z + a.Z;
	this->W = this->W + a.W;

	return *this;
}

Vector4& Vector4::operator-= (const Vector4 &a)
{
	this->X = this->X - a.X;
	this->Y = this->Y - a.Y;
	this->Z = this->Z - a.Z;
	this->W = this->W - a.W;

	return *this;
}

Vector4& Vector4::operator*= (const Vector4 &a)
{
	this->X = this->X * a.X;
	this->Y = this->Y * a.Y;
	this->Z = this->Z * a.Z;
	this->W = this->W * a.W;

	return *this;
}

Vector4& Vector4::operator*= (const float &a)
{
	this->X = this->X * a;
	this->Y = this->Y * a;
	this->Z = this->Z * a;
	this->W = this->W * a;

	return *this;
}

Vector4& Vector4::operator/= (const Vector4 &a)
{
	this->X = this->X / a.X;
	this->Y = this->Y / a.Y;
	this->Z = this->Z / a.Z;
	this->W = this->W / a.W;

	return *this;
}

Vector4& Vector4::operator/= (const float &a)
{
	this->X = this->X / a;
	this->Y = this->Y / a;
	this->Z = this->Z / a;
	this->W = this->W / a;

	return *this;
}

// Comparison operators
bool Vector4::operator== (const Vector4 &a) const
{
	return (FLOAT_EQUALS(this->X, a.X) &&
			FLOAT_EQUALS(this->Y, a.Y) &&
			FLOAT_EQUALS(this->Z, a.Z) &&
			FLOAT_EQUALS(this->W, a.W));
}

bool Vector4::operator!= (const Vector4 &a) const
{
	return !(*this == a);
}

// Assignment operator
Vector4& Vector4::operator= (const Vector4 &a)
{
	if (this != &a)
	{
		this->X = a.X;
		this->Y = a.Y;
		this->Z = a.Z;
		this->W = a.W;
	}

	return *this;
}


// Conversions
Vector2 Vector4::toVector2() const
{
	return Vector2 (this->X, this->Y);
}

Vector3 Vector4::toVector3() const
{
	return Vector3 (this->X, this->Y, this->Z);
}


// Misc
float Vector4::getLength() const
{
	return sqrtf((this->X * this->X) +
				 (this->Y * this->Y) +
				 (this->Z * this->Z) +
				 (this->W * this->W));
}

float Vector4::getLengthSquared() const
{
	return  (this->X * this->X) +
			(this->Y * this->Y) +
			(this->Z * this->Z) +
			(this->W * this->W);
}

Vector4 Vector4::negate() const
{
	return Vector4(-this->X, -this->Y, -this->Z, -this->W);
}

Vector4 Vector4::normalize() const
{
	float len = this->getLength();

	return Vector4(this->X / len, this->Y / len, this->Z / len, this->W / len);
}


// Static mathematical operations
Vector4 Vector4::add (const Vector4& a, const Vector4& b)
{
	return Vector4(
			a.X + b.X,
			a.Y + b.Y,
			a.Z + b.Z,
			a.W + b.W );
}

Vector4 Vector4::subtract (const Vector4& a, const Vector4& b)
{
	return Vector4(
			a.X - b.X,
			a.Y - b.Y,
			a.Z - b.Z,
			a.W - b.W );
}

Vector4 Vector4::multiply (const Vector4& a, const Vector4& b)
{
	return Vector4(
			a.X * b.X,
			a.Y * b.Y,
			a.Z * b.Z,
			a.W * b.W );
}

Vector4 Vector4::multiply (const Vector4& a, const float& b)
{
	return Vector4(
			a.X * b,
			a.Y * b,
			a.Z * b,
			a.W * b );
}

Vector4 Vector4::multiply (const float& a, const Vector4& b)
{
	return Vector4(
			a * b.X,
			a * b.Y,
			a * b.Z,
			a * b.W );
}

Vector4 Vector4::divide (const Vector4& a, const Vector4& b)
{
	return Vector4(
			a.X / b.X,
			a.Y / b.Y,
			a.Z / b.Z,
			a.W / b.W );
}

Vector4 Vector4::divide (const Vector4& a, const float& b)
{
	return Vector4(
			a.X / b,
			a.Y / b,
			a.Z / b,
			a.W / b );
}

Vector4 Vector4::divide (const float& a, const Vector4& b)
{
	return Vector4(
			a / b.X,
			a / b.Y,
			a / b.Z,
			a / b.W );
}

Vector4 Vector4::reflect(const Vector4& a, const Vector4& n)
{
	Vector4 n2 = n.normalize();
	return (a - n2 * 2.0f * Vector4::dot(a, n2));
}

float Vector4::dot (const Vector4& a, const Vector4& b)
{
	return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z) + (a.W * b.W);
}

float Vector4::distance (const Vector4& a, const Vector4& b)
{
	return sqrtf((a.X - b.X) * (a.X - b.X) +
				 (a.Y - b.Y) * (a.Y - b.Y) +
				 (a.Z - b.Z) * (a.Z - b.Z) +
				 (a.W - b.W) * (a.W - b.W));
}

float Vector4::distanceSquared (const Vector4& a, const Vector4& b)
{
	return (a.X - b.X) * (a.X - b.X) +
			(a.Y - b.Y) * (a.Y - b.Y) +
			(a.Z - b.Z) * (a.Z - b.Z) +
			(a.W - b.W) * (a.W - b.W);
}

Vector4 Vector4::lerp (const Vector4& a, const Vector4& b, const float& t)
{
	return a * (1 - t) + b * t;
}


Vector4 Vector4::getMax (const Vector4& a, const Vector4& b)
{
	return Vector4(
			std::max(a.X, b.X),
			std::max(a.Y, b.Y),
			std::max(a.Z, b.Z),
			std::max(a.W, b.W) );
}

Vector4 Vector4::getMin (const Vector4& a, const Vector4& b)
{
	return Vector4(
			std::min(a.X, b.X),
			std::min(a.Y, b.Y),
			std::min(a.Z, b.Z),
			std::min(a.W, b.W) );
}

}  // namespace Goblin

