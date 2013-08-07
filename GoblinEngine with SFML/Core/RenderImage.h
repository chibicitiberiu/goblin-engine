/*
 * RenderImage.h
 *
 *  Created on: May 8, 2013
 *      Author: chibi_000
 */

#ifndef RENDERIMAGE_H_
#define RENDERIMAGE_H_

#include "Image.h"
#include "RenderSurface.h"

namespace Goblin {

	class RenderImage: public Image, public RenderSurface {

	protected:
		void blend(size_t x, size_t y, const Color& c);

	public:
		RenderImage(size_t w, size_t h);
		RenderImage(void* data, size_t w, size_t h);
		RenderImage(const RenderImage& img);
		virtual ~RenderImage();

		virtual void drawImage(const Image& img, const Vector2& topLeft, const Rectangle& area);
		virtual void drawRectangle(const Color& fill, const Rectangle& rect);
		virtual void drawEllipse(const Color& fill, const Rectangle& rect);

	};

}  // namespace Goblin

#endif /* RENDERIMAGE_H_ */
