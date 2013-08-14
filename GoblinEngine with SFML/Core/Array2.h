/*
 * Array2.h
 *
 *  Created on: May 5, 2013
 *      Author: chibi_000
 */

#ifndef ARRAY2_H_
#define ARRAY2_H_

namespace Goblin {

	/// <summary>Bidimensional array.</summary>
	/// <typeparam name="T">Generic type parameter.</typeparam>
	template <typename T>
	class Array2 {

	private:
		T* data;
		size_t w, h;

	public:

	// Constructors
		/// <summary>Constructor.</summary>
		/// <param name="w">The width of the array.</param>
		/// <param name="h">The height of the array.</param>
		Array2(size_t w, size_t h);

		/// <summary>Constructor.</summary>
		/// <param name="w">The width of the array.</param>
		/// <param name="h">The height of the array.</param>
		/// <param name="vals">An array which contains at least width * height values.</param>
		Array2(size_t w, size_t h, const T* vals);

		/// <summary>Copy constructor.</summary>
		/// <param name="a">The array to copy from.</param>
		Array2(const Array2&);

		/// <summary>Destructor.</summary>
		virtual ~Array2();

	// Getters
		/// <summary>Gets the data from the specified location.</summary>
		/// <param name="x">The column.</param>
		/// <param name="y">The row.</param>
		T& get(size_t x, size_t y) const;

		/// <summary>Gets the width of the array.</summary>
		/// <returns>The width&lt;typename t&gt;</returns>
		size_t getWidth() const;

		/// <summary>Gets the height of the array.</summary>
		/// <returns>The height&lt;typename t&gt;</returns>
		size_t getHeight() const;

	// Setters
		/// <summary>Sets the data in the specified location.</summary>
		/// <param name="x">The column.</param>
		/// <param name="y">The row.</param>
		/// <param name="value">The value to set.</param>
		void set(size_t x, size_t y, const T& value);

	// Assignment operator
		/// <summary>Assignment operator.</summary>
		/// <param name="a">The value to assign.</param>
		Array2& operator= (const Array2& a);
	};


	template <typename T>
	Array2<T>::Array2(size_t w, size_t h)
	{
		this->w = w;
		this->h = h;
		this->data = new T[this->w * this->h];
	}

	template <typename T>
	Array2<T>::Array2(size_t w, size_t h, const T* vals)
	{
		this->w = w;
		this->h = h;
		this->data = new T[this->w * this->h];

		for (size_t i = 0; i < this->w * this->h; i++)
			this->data[i] = vals[i];
	}

	template <typename T>
	Array2<T>::Array2(const Array2& a)
	{
		this->w = a.w;
		this->h = a.h;
		this->data = new T[this->w * this->h];

		for (size_t i = 0; i < this->w * this->h; i++)
			this->data[i] = a.data[i];
	}

	template <typename T>
	Array2<T>& Array2<T>::operator= (const Array2& a)
	{
		if (this != &a)
		{
			delete this->data;

			this->w = a.w;
			this->h = a.h;
			this->data = new T[this->w * this->h];

			for (size_t i = 0; i < this->w * this->h; i++)
				this->data[i] = a.data[i];
		}

		return *this;
	}

	template <typename T>
	Array2<T>::~Array2()
	{
		delete this->data;
	}

	template <typename T>
	T& Array2<T>::get(size_t x, size_t y) const
	{
		return this->data[y * this->w + x];
	}

	template <typename T>
	void Array2<T>::set(size_t x, size_t y, const T& value)
	{
		this->data[y * this->w + x] = value;
	}

	template <typename T>
	size_t Array2<T>::getWidth() const
	{
		return this->w;
	}

	template <typename T>
	size_t Array2<T>::getHeight() const
	{
		return this->h;
	}

} // namespace Goblin


#endif /* ARRAY2_H_ */
