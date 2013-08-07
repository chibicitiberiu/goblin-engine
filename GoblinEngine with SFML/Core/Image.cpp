/*
 * Image.cpp
 *
 *  Created on: Sep 14, 2012
 *      Author: Tibi
 */
#include <stdlib.h>
#include <string.h>
#include "Image.h"

namespace Goblin {

Image::Image(size_t w, size_t h)
{
	if (w * h > 5000 * 5000)
		throw 1; // InvalidInputException("Image too large!");

	this->width = w;
	this->height = h;
	this->data = new uint32_t[w * h];

	if (this->data == NULL)
		throw 2; // OutOfMemoryException("Could not allocate enough memory for this operation.");
}

Image::Image(void* data, size_t w, size_t h)
{
	if (data == NULL)
		throw 3; // InvalidInputException("The input data cannot be null.");

	if (w * h > 5000 * 5000)
		throw 5; //InvalidInputException("Image too large!");

	this->width = w;
	this->height = h;
	this->data = new uint32_t[w * h];

	if (this->data == NULL)
		throw 6; //OutOfMemoryException("Could not allocate enough memory for this operation.");

	::memcpy(this->data, data, w * h * 4);
}

Image::Image(const Image& b)
{
	// Copy the members
	this->height = b.height;
	this->width = b.width;

	// Allocate a new block with the required size
	this->data = new uint32_t[this->height * this->width];
	if (this->data == NULL)
		throw 10; // OutOfMemoryException("Could not allocate enough memory for this operation.");

	// Copy the image data
	memcpy(this->data, b.data, this->width * this->height * 4);
}

Image::~Image()
{
	delete[] this->data;
}

size_t Image::getWidth() const
{
	return this->width;
}

size_t Image::getHeight() const
{
	return this->height;
}

void* Image::getData() const
{
	return this->data;
}

Image& Image::operator= (const Image& b)
{
	if (this != &b)
	{
		// Copy the members
		this->height = b.height;
		this->width = b.width;

		// Free the allocated data
		delete[] this->data;

		// Allocate a new block with the required size
		this->data = new uint32_t[this->width * this->height];
		if (this->data == NULL)
			throw 7; //OutOfMemoryException("Could not allocate enough memory for this operation.");

		// Copy the image data
		memcpy(this->data, b.data, this->width * this->height * 4);
	}

	return *this;
}

Color Image::get(size_t x, size_t y) const
{
	uint32_t data = this->data[y * this->width + x];
	uint32_t r = (data >> 16) & 0xff;
	uint32_t g = (data >> 8) & 0xff;
	uint32_t b = data & 0xff;
	uint32_t a = (data >> 24) & 0xff;

	return Color((int)r, (int)g , (int)b , (int)a );
}

void Image::set(size_t x, size_t y, const Color& c)
{
	int r = c.getR(), g = c.getG(), b = c.getB(), a = c.getA();
	this->data[y * this->width + x] = (a << 24) + (r << 16) + (g << 8) + b;
}

// Misc
void Image::clear(const Color& c)
{
	uint32_t color = c.getARGB();

	for (size_t i = 0; i < this->width * this->height; i++)
		this->data[i] = color;
}

}  // namespace Goblin
