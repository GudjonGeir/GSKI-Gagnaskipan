#include "Vector.h"

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
    if (out_of_bounds(index))
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
