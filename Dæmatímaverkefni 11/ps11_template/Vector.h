#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

const int INITIAL_CAPACITY = 50;

class IndexOutOfRangeException {};
class EmptyException {};

template<class T>
class Vector
{
	private:
		// A dynamic array of that stores items of type T.
		T*  array;
		// Contains the size of array (i.e. the maximum number of elements
		// that the vector can store using this array).
		int capacity;
		// The number of array positions currently holding values (i.e., the
		// number of elements in the vector).
		int count;

		void grow();
		bool out_of_bounds(int index) const;
		bool full() const;

	public:
		// Initializes an empty vector.
		Vector();
		// Initializes a vector with 'size' copies of the element 'value'.
		// If 'size' is less than 0, the initalized vector is empty.
		Vector(int size, T value = T());
		// A copy constructor.
		Vector(const Vector& vec);

		~Vector();

		// Returns the element at position 'index'.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		T at(int index) const;
		// Sets the value at position 'index' to 'elem'.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		void set_value_at(int index, T elem) const;

		// Returns the size of the array.
		int size() const;
		// Returns true if and only if the array contains no elements.
		bool empty() const;

		// Appends elem to the vector.
		void push_back(T elem);
		// Removes the last element of the vector and returns it.
		// If the vector is empty, the function throws
		// EmptyException.
		T pop_back();
		// Inserts 'elem' into the list at position 'index'. All elements to
		// the right of index are shifted one position to the right.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		void insert(int index, T elem);
		// Removes the element at position 'index'. All elements to the
		// right of index are shifted one position to the left.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		void remove_at(int index);
		// Removes all the elements from the list
		void clear();

		// Overloaded = operator.
		void operator=(const Vector& vec);
		// Returns a reference to the element at position 'index'.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		T& operator[] (int index) const;
};

// Outputs the elements of 'rhs' to the specified stream, separated by a single
// space.
template<class T>
ostream& operator<< (ostream& out, const Vector<T>& rhs);

#endif


template<class T>
Vector<T>::Vector()
{
	capacity = INITIAL_CAPACITY;
	array = new T[capacity];
	count = 0;
}

template<class T>
Vector<T>::Vector(int size, T value)
{
	if (size < 0)
	{
		array = new T[INITIAL_CAPACITY];
		capacity = INITIAL_CAPACITY;
		count = 0;
	}
	else
	{
		array = new T[size];
		capacity = size;
		count = size;
		for (int i = 0; i < size; ++i)
		{
			array[i] = value;
		}
	}
}

template<class T>
Vector<T>::Vector(const Vector& vec)
	: count(vec.count), capacity(vec.capacity)
{
	array = new T[capacity];
	for (int i = 0; i < count; ++i)
	{
		array[i] = vec.array[i];
	}
}

template<class T>
Vector<T>::~Vector()
{
	delete []array;
}

template<class T>
void Vector<T>::grow()
{
	capacity *= 2;
	T* tmpArray = new T[capacity];
	for (int i = 0; i < count; ++i)
	{
		tmpArray[i] = array[i];
	}
	delete[] array;
	array = tmpArray;
}

template<class T>
bool Vector<T>::out_of_bounds(int index) const
{
	return (index >= count || index < 0);
}

template<class T>
bool Vector<T>::full() const
{
	return (capacity == count);
}

template<class T>
T Vector<T>::at(int index) const
{
	if (out_of_bounds(index))
	{
		throw IndexOutOfRangeException();
	}
	else
	{
		return array[index];
	}
}

template<class T>
void Vector<T>::set_value_at(int index, T elem) const
{
	if (out_of_bounds(index))
	{
		throw IndexOutOfRangeException();
	}	
	else
	{
		array[index] = elem;
	}
}

template<class T>
int Vector<T>::size() const
{
	return count;
}

template<class T>
bool Vector<T>::empty() const
{
	return count == 0;
}

template<class T>
void Vector<T>::push_back(T elem)
{
	if(full()) 
	{
		grow();
	}
	array[count] = elem;
	count++;
}

template<class T>
T Vector<T>::pop_back()
{
    if (count == 0)
    {
        throw EmptyException();
    }
    else
    {
        count--;
	return array[count];
    }
}

template<class T>
void Vector<T>::insert(int index, T elem)
{
    if (index > count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        if (full())
        {
		grow();
        }
        for (int i = count; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = elem;
        count++;
    }
}

template<class T>
void Vector<T>::remove_at(int index)
{
    if (out_of_bounds(index))
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        for (int i = index; i < count - 1; i++)
        {
            array[i] = array[i + 1];
        }
        count--;
    }
}

template<class T>
void Vector<T>::clear()
{
	count = 0;
}

template<class T>
void Vector<T>::operator=(const Vector<T>& vec)
{
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

template<class T>
T& Vector<T>::operator[] (int index) const
{
    if (out_of_bounds(index))
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return array[index];
    }
}

template<class T>
ostream& operator<< (ostream& out, const Vector<T>& rhs)
{
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs[i];
    }
    return out;
}

