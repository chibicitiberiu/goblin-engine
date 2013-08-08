/*
 * Rectangle.h
 *
 *  Created on: May 11, 2013
 *      Author: chibi_000
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Vector.h"
#include "Build.h"

namespace Goblin {

	class DLLEXPORT Rectangle {

	public:

		static const Rectangle Zero;

		float Left, Top, Right, Bottom;

		// Constructors
		Rectangle();
		Rectangle(float left, float top, float right, float bottom);
		Rectangle(const Vector2& topLeft, const Vector2& botRight);
		Rectangle(const Vector2& topLeft, float width, float height);

		virtual ~Rectangle();

		// Getters
		Vector2 getTopLeft() const;
		Vector2 getBotRight() const;
		Vector2 getSize() const;

		float getWidth() const;
		float getHeight() const;

		// Setters
		void setTopLeft(const Vector2& value);
		void setTopLeft(float x, float y);
		void setBotRight(const Vector2& value);
		void setBotRight(float x, float y);
		void setSize(const Vector2& value);
		void setSize(float w, float h);
		void setWidth(float value);
		void setHeight(float value);

		// Operators
		bool operator== (const Rectangle& other) const;
		bool operator!= (const Rectangle& other) const;

		// Other operations
		bool contains (const Vector2& point) const;
		bool contains (const Rectangle& rect) const;
		bool intersectsWith(const Rectangle& rect) const;
		Rectangle move (const Vector2& offset) const;
		Rectangle move (float offset_x, float offset_y) const;
		Rectangle intersect (const Rectangle& rect) const;

		// Static operations
		static Rectangle intersect (const Rectangle& a, const Rectangle& b);
	};

}  // namespace Goblin

#endif /* RECTANGLE_H_ */
