/*
 * RenderTarget.h
 *
 *  Created on: May 8, 2013
 *      Author: chibi_000
 */

#ifndef RENDERSURFACE_H_
#define RENDERSURFACE_H_

#include "Color.h"
#include "Image.h"
#include "Rectangle.h"

namespace Goblin {

	class RenderSurface {

	private:

	public:
		RenderSurface();
		virtual ~RenderSurface();

		virtual void drawImage(const Image& img, const Vector2& topLeft, const Rectangle& area) = 0;

		virtual void drawRectangle(const Color& fill, const Rectangle& rect) = 0;
		virtual void drawRectangle(const Color& fill, const Vector2& topLeft, const Vector2& botRight);
		virtual void drawRectangle(const Color& fill, float left, float top, float right, float bottom);

		virtual void drawEllipse(const Color& fill, const Rectangle& rect) = 0;
		virtual void drawEllipse(const Color& fill, const Vector2& topLeft, const Vector2& botRight);
		virtual void drawEllipse(const Color& fill, float left, float top, float right, float bottom);

	};

}  // namespace Goblin

#endif /* RENDERTARGET_H_ */
