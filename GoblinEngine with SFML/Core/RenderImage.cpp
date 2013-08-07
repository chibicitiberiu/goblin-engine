/*
 * RenderImage.cpp
 *
 *  Created on: May 8, 2013
 *      Author: chibi_000
 */

#include "RenderImage.h"
#include <cassert>
#include <algorithm>

namespace Goblin {

RenderImage::RenderImage(size_t w, size_t h)
	: Image(w, h)
{
}

RenderImage::RenderImage(void* data, size_t w, size_t h)
	: Image(data, w, h)
{
}

RenderImage::RenderImage(const RenderImage& img)
	: Image(img)
{
}

RenderImage::~RenderImage()
{
}

void RenderImage::blend(size_t x, size_t y, const Color& c1)
{
	// Get color
	Color c2 = this->get(x, y);

	// Calculate blend result
	float alpha = c1.A + c2.A * (1 - c1.A);
	Color out = (alpha == 0) ? 0x0 : ((c1 * c1.A + c2 * c2.A * (1 - c1.A)) / alpha);
	out.A = alpha;

	// Set pixel
	this->set(x, y, out);
}

void RenderImage::drawImage(const Image& img, const Vector2& topLeft, const Rectangle& area)
{
	size_t x0 = (size_t)topLeft.X, y0 = (size_t)topLeft.Y;
	size_t x1 = (size_t)area.Left, y1 = (size_t)area.Top;
	size_t w = (size_t)area.getWidth(), h = (size_t)area.getHeight();

	// Put pixels
	for(size_t y = y0; y < y0 + h && y < this->getHeight(); y++)
		for (size_t x = x0; x < x0 + w && x < this->getWidth(); x++)
			this->blend(x, y, img.get(x - x0 + x1, y - y0 + y1));
}

void RenderImage::drawRectangle(const Color& fill, const Rectangle& rect)
{
	size_t x0 = (size_t)rect.Left, y0 = (size_t)rect.Top;
	size_t x1 = (size_t)rect.Right, y1 = (size_t)rect.Bottom;

	// Put pixels
	for(size_t y = y0; y < y1 && y < this->getHeight(); y++)
			for (size_t x = x0; x < x1 && x < this->getWidth(); x++)
				this->blend(x, y, fill);
}

void RenderImage::drawEllipse(const Color& fill, const Rectangle& rect)
{
	// Get some ellipse properties
	Vector2 center = (rect.getTopLeft() + rect.getBotRight()) / 2.0f;
	Vector2 radius = (rect.getBotRight() - rect.getTopLeft()) / 2.0f;
	Vector2 radius_sq (radius.X * radius.X, radius.Y * radius.Y);
	float thickness = std::min(radius.X, radius.Y) / 1.5f;

	// Draw
	for (float y = rect.Top; y < rect.Bottom; y++)
		for (float x = rect.Left; x < rect.Right; x++)
		{
			// Implicit formula
			float a = (x - center.X) * (x - center.X) / radius_sq.X +
					  (y - center.Y) * (y - center.Y) / radius_sq.Y;

			// Draw pixel
			if (a <= 1.0f)
				this->blend((size_t)x, (size_t)y, fill);

			// Verify error (here we do anti-aliasing)
			else
			{
				float error = (a - 1.0f) * thickness;
				if (error < 0) error *= 1;

				if (error <= 1)
					this->blend((size_t)x, (size_t)y, Color(fill.R, fill.G, fill.B, (1 - error) * fill.A ));
			}
		}
}

}  // namespace Goblin
