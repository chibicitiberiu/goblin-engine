/*
 * Rectangle.cpp
 *
 *  Created on: May 11, 2013
 *      Author: chibi_000
 */

#include "Rectangle.h"
#include <cfloat>
#include <algorithm>

#define FLOAT_EQUALS(a,b) (abs((a) - (b)) < FLT_EPSILON)

namespace Goblin {

const Rectangle Rectangle::Zero(0, 0, 0, 0);

// Constructors
Rectangle::Rectangle()
	: Left(), Top(), Right(), Bottom()
{
}

Rectangle::Rectangle(float left, float top, float right, float bottom)
	: Left(left), Top(top), Right(right), Bottom(bottom)
{
}

Rectangle::Rectangle(const Vector2& topLeft, const Vector2& botRight)
	: Left(topLeft.X), Top(topLeft.Y), Right(botRight.X), Bottom(botRight.Y)
{
}

Rectangle::Rectangle(const Vector2& topLeft, float width, float height)
	: Left(topLeft.X), Top(topLeft.Y), Right(topLeft.X + width), Bottom(topLeft.Y + height)
{
}

Rectangle::~Rectangle()
{
}

// Getters
Vector2 Rectangle::getTopLeft() const
{
	return Vector2(this->Left, this->Top);
}

Vector2 Rectangle::getBotRight() const
{
	return Vector2(this->Right, this->Bottom);
}

Vector2 Rectangle::getSize() const
{
	return Vector2(this->Right - this->Left, this->Bottom - this->Top);
}

float Rectangle::getWidth() const
{
	return this->Right - this->Left;
}

float Rectangle::getHeight() const
{
	return this->Bottom - this->Top;
}

// Setters
void Rectangle::setTopLeft(const Vector2& value)
{
	this->Left = value.X;
	this->Top = value.Y;
}

void Rectangle::setTopLeft(float x, float y)
{
	this->Left = x;
	this->Top = y;
}

void Rectangle::setBotRight(const Vector2& value)
{
	this->Right = value.X;
	this->Bottom = value.Y;
}

void Rectangle::setBotRight(float x, float y)
{
	this->Right = x;
	this->Bottom = y;
}

void Rectangle::setSize(const Vector2& value)
{
	this->Right = this->Left + value.X;
	this->Bottom = this->Top + value.Y;
}

void Rectangle::setSize(float w, float h)
{
	this->Right = this->Left + w;
	this->Bottom = this->Top + h;
}

void Rectangle::setWidth(float value)
{
	this->Right = this->Left + value;
}

void Rectangle::setHeight(float value)
{
	this->Bottom = this->Top + value;
}

// Operators
bool Rectangle::operator== (const Rectangle& other) const
{
	return FLOAT_EQUALS(this->Left, other.Left) &&
		   FLOAT_EQUALS(this->Top, other.Top) &&
		   FLOAT_EQUALS(this->Right, other.Right) &&
		   FLOAT_EQUALS(this->Bottom, other.Bottom);
}

bool Rectangle::operator!= (const Rectangle& other) const
{
	return !this->operator ==(other);
}

// Other operations
bool Rectangle::contains (const Vector2& point) const
{
	return (this->Left <= point.X) &&
		   (this->Top <= point.Y) &&
		   (point.X <= this->Right) &&
		   (point.Y <= this->Bottom);
}

bool Rectangle::contains (const Rectangle& rect) const
{
	return this->contains(rect.getTopLeft()) && this->contains(rect.getBotRight());
}

bool Rectangle::intersectsWith(const Rectangle& rect) const
{
	return !(rect.Left > this->Right ||
			 rect.Right < this->Left ||
			 rect.Top > this->Bottom ||
			 rect.Bottom < this->Top);
}

Rectangle Rectangle::move (const Vector2& offset) const
{
	return Rectangle( this->Left + offset.X,
					  this->Top + offset.Y,
					  this->Right + offset.X,
					  this->Bottom + offset.Y );
}

Rectangle Rectangle::move (float offset_x, float offset_y) const
{
	return Rectangle( this->Left + offset_x,
					  this->Top + offset_y,
					  this->Right + offset_x,
					  this->Bottom + offset_y );
}

Rectangle Rectangle::intersect (const Rectangle& rect) const
{
	Rectangle res( std::max(this->Left, rect.Left),
				   std::max(this->Top, rect.Top),
				   std::min(this->Right, rect.Right),
				   std::min(this->Bottom, rect.Bottom) );

	return (res.getWidth() < 0 || res.getHeight() < 0) ? Zero : res;
}

// Static operations
Rectangle Rectangle::intersect (const Rectangle& a, const Rectangle& b)
{
	Rectangle res( std::max(a.Left, b.Left),
				   std::max(a.Top, b.Top),
				   std::min(a.Right, b.Right),
				   std::min(a.Bottom, b.Bottom) );

	return (res.getWidth() < 0 || res.getHeight() < 0) ? Zero : res;
}

}  // namespace Goblin
