/*
 * Image.hpp
 *
 *  Created on: Sep 14, 2012
 *      Author: Tibi
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "Color.h"
#include <cstring>

namespace Goblin {

class Image {

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

#endif /* IMAGE_HPP_ */
