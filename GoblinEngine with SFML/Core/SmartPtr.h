#pragma once

namespace Goblin
{
	/// <summary>Smart pointer class.</summary>
	/// <typeparam name="T">Generic type parameter.</typeparam>
	template <class T>
	class SmartPtr {

	private:
		T* _obj;				// Pointer
		unsigned* _refs;		// Reference count

	public:
		
		/// <summary>Creates an instance of NULL smart pointer.</summary>
		SmartPtr() {
			this->_refs = new unsigned(1);
			this->_obj = NULL;
		}

		/// <summary>Copy constructor.</summary>
		/// <param name="p">The smart pointer to copy.</param>
		SmartPtr(const SmartPtr& p) {
			(*p._refs) ++;
			this->_refs = p._refs;
			this->_obj = p._obj;
		}

		/// <summary>Creates new instance of smart pointer using existing object.</summary>
		/// <param name="_obj">Pointer.</param>
		SmartPtr(T* _obj) {
			this->_refs = new unsigned(1);
			this->_obj = _obj;
		}

		/// <summary>Destroys current instance.</summary>
		virtual ~SmartPtr() {
			(*this->_refs) --;
			if ((*this->_refs) == 0)
			{
				delete this->_obj;
				delete this->_refs;
			}
		}

		/// <summary>Gets pointer address.</summary>
		T* operator() ()
		{
			return this->_obj;
		}

		/// <summary>Gets pointer address.</summary>
		T* ptr ()
		{
			return this->_obj;
		}

		/// <summary>Gets pointer address.</summary>
		T* operator-> () const
		{
			return this->_obj;
		}

		/// <summary>Gets dereferenced pointer.</summary>
		/// <returns>The result of the operation.</returns>
		T& operator* () const
		{
			return *this->_obj;
		}

		/// <summary>Gets reference count.</summary>
		unsigned refs() const {
			return *this->_refs;
		}

		/// <summary>Assignment operator.</summary>
		/// <param name="p">The smart pointer to assign.</param>
		SmartPtr& operator= (const SmartPtr& p) {

			if (this != &p)
			{
				// Destroy current _object
				(*this->_refs) --;
				if ((*this->_refs) == 0)
				{
					delete this->_obj;
					delete this->_refs;
				}

				// Assign new stuff
				(*p._refs) ++;
				this->_refs = p._refs;
				this->_obj = p._obj;
			}
			return *this;
		}

		/// <summary>Equality operator.</summary>
		/// <param name="other">The smart pointer to compare with.</param>
		/// <returns>True if the pointers point to the same thing.</returns>
		bool operator== (const SmartPtr& other)
		{
			return this->_obj == other._obj;
		}

		/// <summary>Inequality operator.</summary>
		/// <param name="other">The smart pointer to compare with.</param>
		/// <returns>True if the pointers don't point to the same thing.</returns>
		bool operator!= (const SmartPtr& other)
		{
			return this->_obj != other._obj;
		}
	};

	/// <summary>Smart array pointer.</summary>
	/// <typeparam name="T">Generic array type parameter.</typeparam>
	template <class T>
	class SmartPtr <T[]> {

	private:
		T* _obj;
		unsigned* _refs;
		unsigned _size;

	public:

		/// <summary>Creates new instance of NULL array smart pointer.</summary>
		/// <param name="p">The const smart pointer to copy.</param>
		SmartPtr() {
			this->_refs = new unsigned(1);
			this->_obj = NULL;
			this->_size = 0;
		}

		/// <summary>Copy constructor.</summary>
		/// <param name="p">The const smart pointer to copy.</param>
		SmartPtr(const SmartPtr& p) {
			(*p._refs) ++;
			this->_refs = p._refs;
			this->_obj = p._obj;
			this->_size = p._size;
		}

		/// <summary>Creates new instance of array smart pointer, and allocates 'size' objects.</summary>
		/// <param name="_size">The number of elements to allocate.</param>
		SmartPtr(unsigned _size) {
			this->_refs = new unsigned(1);
			this->_obj = new T[_size];
			this->_size = _size;
		}

		/// <summary>Creates new instance of array pointer using existing array.</summary>
		/// <param name="_obj">The array.</param>
		SmartPtr(T* _obj) {
			this->_refs = new unsigned(1);
			this->_obj = _obj;
			this->_size = (unsigned) -1;
		}

		/// <summary>Creates new instance of array pointer with specified size.</summary>
		/// <param name="_obj">The array.</param>
		/// <param name="_size">The number of array elements.</param>
		SmartPtr(T* _obj, unsigned _size) {
			this->_refs = new unsigned(1);
			this->_obj = _obj;
			this->_size = _size;
		}

		/// <summary>Destroys current instance of array pointer.</summary>
		virtual ~SmartPtr() {
			(*this->_refs) --;
			if ((*this->_refs) == 0)
			{
				delete[] this->_obj;
				delete this->_refs;
			}
		}

		/// <summary>Gets pointer address.</summary>
		T* operator() ()
		{
			return this->_obj;
		}

		/// <summary>Gets pointer address.</summary>
		T* ptr ()
		{
			return this->_obj;
		}

		/// <summary>Gets element at index.</summary>
		/// <param name="index">Zero-based index of the array.</param>
		/// <returns>The indexed value.</returns>
		T& operator[] (unsigned index) const
		{
			return this->_obj[index];
		}

		/// <summary>Gets references count.</summary>
		unsigned refs() const {
			return *this->_refs;
		}

		/// <summary>Gets size of array.</summary>
		unsigned size() const {
			return this->_size;
		}

		/// <summary>Assignment operator.</summary>
		/// <param name="p">The smart pointer to assign.</param>
		SmartPtr& operator= (const SmartPtr& p) {

			if (this != &p)
			{
				// Destroy current _object
				(*this->_refs) --;
				if ((*this->_refs) == 0)
				{
					delete[] this->_obj;
					delete this->_refs;
				}

				// Assign new stuff
				(*p._refs) ++;
				this->_refs = p._refs;
				this->_obj = p._obj;
				this->_size = p._size;
			}
			return *this;
		}

		/// <summary>Equality operator.</summary>
		/// <param name="other">The smart pointer to compare with.</param>
		/// <returns>True if the pointers point to the same thing.</returns>
		bool operator== (const SmartPtr& other)
		{
			return this->_obj == other._obj;
		}

		/// <summary>Inequality operator.</summary>
		/// <param name="other">The smart pointer to compare with.</param>
		/// <returns>True if the pointers don't point to the same thing.</returns>
		bool operator!= (const SmartPtr& other)
		{
			return this->_obj != other._obj;
		}
	};
}