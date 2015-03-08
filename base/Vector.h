/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

/*
 * Templator Pattern
 * 2010.08.14 by alex
 */

#ifndef BASE_VECTOR_H_
#define BASE_VECTOR_H_
#pragma once 

#include "assert.h"

/* Default arrary size */
#define VECTOR_DEFAULT_SIZE 100

/**
 * Simple arrary template class.
 */
template <class T>
class Vector {
public:

	///* Iterator Declaration */
	//typedef VectorIterator<T> iterator;

	/**
	 * Class constructor.
	 * @param sz Maximum number of item this Vector can hold.
	 */
	Vector(int sz = VECTOR_DEFAULT_SIZE) : size(sz), count(0)
	{
		vec = new T [size];
		for (int i = 0; i <sz; i++)
			vec[i] = 0;
	}

	/**
	 * Class destructor.
	 */
	~Vector()
	{
		delete [] vec;
	}

	/**
	 * Insert an item in the first empty position.
	 * @param t Item to insert.
	 * @return Index of the item on success or -1 otherwise.
	 */
	int insert(T t)
	{
		for (int i = 0; i < size; i++)
		{
			if (vec[i] == 0)
			{
				vec[i] = t;
				count++;
				return i;
			}
		}
		return -1;
	}

	/**
	 * Insert an item in the Vector.
	 * @param pos Position in the Vector.
	 * @param t Data item to te inserted.
	 */
	void insert(int pos, T t)
	{
		if (pos < size)
		{
			vec[pos] = t;
		}
	}

	/**
	 * Remove an item from the list.
	 * @param pos Position of the item in the Vector.
	 */
	void remove(int pos)
	{
		if (pos < size)
		{
			vec[pos] = 0;
			for (int index = pos; index < size; index++)
			{
				if (index == (size -1))
				{
					vec[index] = 0;
				}
				vec[index] = vec[index + 1];
			}
			count--;
		}
	}

	/**
	 * Get an item from the Vector.
	 * @param pos Position in the Vector of the requested item.
	 * @return Item from the Vector.
	 */
	T get(int pos)
	{
	    if (pos < size)
		{
		    return vec[pos];
	    }
	    return 0;
	}

	/**
	 * Retrieve the size of the Vector.
	 * @return Size of the internal array.
	 */
	int get_size() const
	{
	    return size;
	}

	/**
	 * Change the size of the Vector.
	 * @param Size of the internal array.
	 */
	void change_size(const int size)
	{
		delete [] vec;

		this->size = size;
		vec = new T [size];
		for (int i = 0; i <size; i++)
		{
			vec[i] = 0;
		}
	}

	/**
	 * Retrieve the amount of items in the Vector.
	 * @return The amount of items in the Vector.
	 */
	int get_count() const
	{
	    return count;
	}

	/**
	 * Returns a shallow clone of this Vector
	 * @return A shallow clone of this Vector
	 */
	Vector<T> clone()
	{
	    Vector<T> clone;
	    
	    for(int index = 0; index < size; index++)
	    {
		    clone.insert(index, vec[index]);
	    }
	    return clone;
	}

	
     /**
	 * Lookup an item in the Vector.
	 * @param Index of the item to find.
	 * @return Reference to the associated item.
	 */
	T &operator [](int i)
	{
		assert(i >= 0 && i < size);
		return vec[i];
	}
	const T &operator [](int i) const
	{
	    assert (i >= 0 && i < size);
		return vec[i];
	}

    /**
	 * Overload the assignment in the Vector.
	 * @param right_value right value of the assignment operator.
	 * @return Reference to *this.
	 */
	Vector<T> &operator =(const Vector<T> &right_value) 
	{
		/* Do not execute in cases of self-reference */
		if (this != &right_value) 

		{
			(*this).change_size(right_value.get_size());

			
			for(int index = 0; index < right_value.get_size(); index++)
	        {
				(*this).insert(index, right_value[index]);
	        }
		}
		return (*this);
	}

	/**
	 *  Object visit member,use .* , ->
	 */
	Vector<T> &operator *()
	{
		return *this;
	}
	Vector<T> *operator ->()
	{
		return this;
	}


private:

	/* Arrary of item pointers */
	T *vec;

	/* Size of the arrary */
	int size;

	/* The amount of items in the arrary */
	int count;

};

#endif /* BASE_VECTOR_H_ */