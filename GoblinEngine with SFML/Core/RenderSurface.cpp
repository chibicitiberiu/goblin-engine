/*
 * RenderTarget.cpp
 *
 *  Created on: May 8, 2013
 *      Author: chibi_000
 */

#include "RenderSurface.h"

namespace Goblin {

RenderSurface::RenderSurface()
{
}

RenderSurface::~RenderSurface()
{
}

void RenderSurface::drawRectangle(const Color& fill, const Vector2& topLeft, const Vector2& botRight)
{
	this->drawRectangle(fill, Rectangle(topLeft, botRight));
}

void RenderSurface::drawRectangle(const Color& fill, float left, float top, float right, float bottom)
{
	this->drawRectangle(fill, Rectangle(left, top, right, bottom));
}

void RenderSurface::drawEllipse(const Color& fill, const Vector2& topLeft, const Vector2& botRight)
{
	this->drawEllipse(fill, Rectangle(topLeft, botRight));
}

void RenderSurface::drawEllipse(const Color& fill, float left, float top, float right, float bottom)
{
	this->drawEllipse(fill, Rectangle(left, top, right, bottom));
}

}  // namespace Goblin
