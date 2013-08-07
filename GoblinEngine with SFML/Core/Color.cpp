/*
 * Color.cpp
 *
 *  Created on: Sep 1, 2012
 *      Author: Tibi
 */

#include "Color.h"
#include <cfloat>
#include <algorithm>

#define FLOAT_EQUALS(a,b) (abs((a) - (b)) < FLT_EPSILON)


namespace Goblin {


Color::Color()
{
	this->R = 0.0f;
	this->G = 0.0f;
	this->B = 0.0f;
	this->A = 1.0f;
}

Color::Color(uint32_t rgba)
{
	this->R = 0.0f;
	this->G = 0.0f;
	this->B = 0.0f;
	this->A = 1.0f;

	this->setARGB(rgba);
}

Color::Color(int r, int g, int b, int a)
{
	this->R = this->linearToFloat(r);
	this->G = this->linearToFloat(g);
	this->B = this->linearToFloat(b);
	this->A = this->linearToFloat(a);
}

Color::Color(float r, float g, float b, float a)
{
	this->R = r;
	this->G = g;
	this->B = b;
	this->A = a;
}

Color::Color(const Vector3& v)
{
	this->R = v.X;
	this->G = v.Y;
	this->B = v.Z;
	this->A = 1.0f;
}

Color::Color(const Vector4& v)
{
	this->R = v.X;
	this->G = v.Y;
	this->B = v.Z;
	this->A = v.W;
}

Color::~Color()
{
}

int Color::linearToInteger(float v) const
{
	return (int)(255.0f * v);
}

float Color::linearToFloat (int v) const
{
	return (float)(v) / 255.0f;
}

// Integer versions
int Color::getR() const
{
	return this->linearToInteger(this->R);
}

int Color::getG() const
{
	return this->linearToInteger(this->G);
}

int Color::getB() const
{
	return this->linearToInteger(this->B);
}

int Color::getA() const
{
	return this->linearToInteger(this->A);
}

uint32_t Color::getARGB() const
{
	uint32_t r = 0;
	r += this->linearToInteger(this->A) << 24;
	r += this->linearToInteger(this->R) << 16;
	r += this->linearToInteger(this->G) << 8;
	r += this->linearToInteger(this->B);

	return r;
}

// Setters
void Color::setARGB(uint32_t rgba)
{
	this->A = this->linearToFloat((rgba>>24) & 0xff);
	this->R = this->linearToFloat((rgba>>16) & 0xff);
	this->G = this->linearToFloat((rgba>>8) & 0xff);
	this->B = this->linearToFloat(rgba & 0xff);
}

void Color::setR(int r)
{
	this->R = this->linearToFloat(r);
}

void Color::setG(int g)
{
	this->G = this->linearToFloat(g);
}

void Color::setB(int b)
{
	this->B = this->linearToFloat(b);
}

void Color::setA(int a)
{
	this->A = this->linearToFloat(a);
}

// Mathematical operators
Color Color::operator+ (const Color &a) const
{
	return Color(
			this->R + a.R,
			this->G + a.G,
			this->B + a.B,
			this->A + a.A );
}

Color Color::operator- (const Color &a) const
{
	return Color(
			this->R - a.R,
			this->G - a.G,
			this->B - a.B,
			this->A - a.A );
}

Color Color::operator* (const Color &a) const
{
	return Color(
			this->R * a.R,
			this->G * a.G,
			this->B * a.B,
			this->A * a.A );
}

Color Color::operator* (const float &a) const
{
	return Color(
			this->R * a,
			this->G * a,
			this->B * a,
			this->A * a );
}

Color operator* (const float &a, const Color &b)
{
	return Color(
			a * b.R,
			a * b.G,
			a * b.B,
			a * b.A );
}

Color Color::operator/ (const Color &a) const
{
	return Color(
			this->R / a.R,
			this->G / a.G,
			this->B / a.B,
			this->A / a.A );
}

Color Color::operator/ (const float &a) const
{
	return Color(
			this->R / a,
			this->G / a,
			this->B / a,
			this->A / a );
}

Color operator/ (const float &a, const Color &b)
{
	return Color(
			a / b.R,
			a / b.G,
			a / b.B,
			a / b.A );
}

Color Color::operator- () const
{
	return Color(-this->R, -this->G, -this->B, -this->A);
}


Color& Color::operator+= (const Color &a)
{
	this->R = this->R + a.R;
	this->G = this->G + a.G;
	this->B = this->B + a.B;
	this->A = this->A + a.A;

	return *this;
}

Color& Color::operator-= (const Color &a)
{
	this->R = this->R - a.R;
	this->G = this->G - a.G;
	this->B = this->B - a.B;
	this->A = this->A - a.A;

	return *this;
}

Color& Color::operator*= (const Color &a)
{
	this->R = this->R * a.R;
	this->G = this->G * a.G;
	this->B = this->B * a.B;
	this->A = this->A * a.A;

	return *this;
}

Color& Color::operator*= (const float &a)
{
	this->R = this->R * a;
	this->G = this->G * a;
	this->B = this->B * a;
	this->A = this->A * a;

	return *this;
}

Color& Color::operator/= (const Color &a)
{
	this->R = this->R / a.R;
	this->G = this->G / a.G;
	this->B = this->B / a.B;
	this->A = this->A / a.A;

	return *this;
}

Color& Color::operator/= (const float &a)
{
	this->R = this->R / a;
	this->G = this->G / a;
	this->B = this->B / a;
	this->A = this->A / a;

	return *this;
}

// Comparison operators
bool Color::operator== (const Color &a) const
{
	return (FLOAT_EQUALS(this->R, a.R) &&
			FLOAT_EQUALS(this->G, a.G) &&
			FLOAT_EQUALS(this->B, a.B) &&
			FLOAT_EQUALS(this->A, a.A));
}

bool Color::operator!= (const Color &a) const
{
	return !(*this == a);
}

// Assignment operator
Color& Color::operator= (const Color &a)
{
	if (this != &a)
	{
		this->R = a.R;
		this->G = a.G;
		this->B = a.B;
		this->A = a.A;
	}

	return *this;
}


// Conversions
Vector3 Color::toVector3() const
{
	return Vector3 (this->R, this->G, this->B);
}

Vector4 Color::toVector4() const
{
	return Vector4 (this->R, this->G, this->B, this->A);
}


// Static mathematical operations
Color Color::add (const Color& a, const Color& b)
{
	return Color(
			a.R + b.R,
			a.G + b.G,
			a.B + b.B,
			a.A + b.A );
}

Color Color::subtract (const Color& a, const Color& b)
{
	return Color(
			a.R - b.R,
			a.G - b.G,
			a.B - b.B,
			a.A - b.A );
}

Color Color::multiply (const Color& a, const Color& b)
{
	return Color(
			a.R * b.R,
			a.G * b.G,
			a.B * b.B,
			a.A * b.A );
}

Color Color::multiply (const Color& a, const float& b)
{
	return Color(
			a.R * b,
			a.G * b,
			a.B * b,
			a.A * b );
}

Color Color::multiply (const float& a, const Color& b)
{
	return Color(
			a * b.R,
			a * b.G,
			a * b.B,
			a * b.A );
}

Color Color::divide (const Color& a, const Color& b)
{
	return Color(
			a.R / b.R,
			a.G / b.G,
			a.B / b.B,
			a.A / b.A );
}

Color Color::divide (const Color& a, const float& b)
{
	return Color(
			a.R / b,
			a.G / b,
			a.B / b,
			a.A / b );
}

Color Color::divide (const float& a, const Color& b)
{
	return Color(
			a / b.R,
			a / b.G,
			a / b.B,
			a / b.A );
}

float Color::dot (const Color& a, const Color& b)
{
	return (a.R * b.R) + (a.G * b.G) + (a.B * b.B) + (a.A * b.A);
}

Color Color::lerp (const Color& a, const Color& b, const float& t)
{
	return a * (1 - t) + b * t;
}


Color Color::getMax (const Color& a, const Color& b)
{
	return Color(
			std::max(a.R, b.R),
			std::max(a.G, b.G),
			std::max(a.B, b.B),
			std::max(a.A, b.A) );
}

Color Color::getMin (const Color& a, const Color& b)
{
	return Color(
			std::min(a.R, b.R),
			std::min(a.G, b.G),
			std::min(a.B, b.B),
			std::min(a.A, b.A) );
}

}  // namespace Goblin

