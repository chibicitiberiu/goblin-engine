/*
 * Image.hpp
 *
 *  Created on: Sep 14, 2012
 *      Author: Tibi
 */

#pragma once

#include "Build.h"
#include "Color.h"
#include <cstring>

namespace Goblin {

	class DLLEXPORT Image {

	protected:
		uint32_t* data;
		size_t width, height;

	public:
		Image(size_t w, size_t h);
		Image(void* data, size_t w, size_t h);
		Image(const Image&);
		virtual ~Image();

		// Getters
		virtual size_t getWidth() const;
		virtual size_t getHeight() const;
		virtual void* getData() const;

		virtual Color get(size_t x, size_t y) const;

		// Setters
		virtual void set(size_t x, size_t y, const Color& c);

		// Misc
		virtual void clear(const Color& c = Colors::Transparent);

		// Operator =
		Image& operator= (const Image& b);
	};

}  // namespace Goblin

