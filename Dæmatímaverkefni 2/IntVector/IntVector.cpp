#include <cmath>
#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector()
{
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    count = 0;
    for(int i = 0; i < capacity; i++)
    {
        array[i] = 0;
    }
}

IntVector::IntVector(int size, int value)
{
    if (size < 0)
    {
        array = new int[INITIAL_CAPACITY];
        capacity = INITIAL_CAPACITY;
    }
    else
    {
        array = new int[size];
        capacity = size;
        count = size;
        for (int i = 0; i < size; ++i)
        {
            array[i] = value;
        }
    }

}

IntVector::IntVector(const IntVector& vec)
    : count(vec.count), capacity(vec.capacity)
{
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}

IntVector::~IntVector()
{
    delete []array;
}

int* IntVector::resize()
{
        capacity *= 2;
        int* tempArray = new int[capacity];
         for (int i = 0; i < count; ++i)
         {
             tempArray[i] = array[i];
         }
         delete []array;
        return tempArray;
}


// Public member functions

void IntVector::push_back(int elem)
{
    if (count + 1 >= capacity)
    {
        array = resize();
    }
    array[count] = elem;
    count++;
}

void IntVector::insert(int index, int elem)
{
    if (index > count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        if (count + 1 >= capacity)
        {
            array = resize();
        }
        for (int i = count; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = elem;
        count++;
    }
}

int IntVector::at(int index) const
{
    if (index >= count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return array[index];
    }
}

void IntVector::set_value_at(int index, int elem) const
{
    if (index >= count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        array[index] = elem;
    }
}

int IntVector::size() const
{
    return count;
}

bool IntVector::empty() const
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IntVector::remove_at(int index)
{
    if (index >= count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        for (int i = index; i < count - 1; i++)
        {
            array[i] = array[i + 1];
        }
        array[count] = 0;
        count--;
    }
}

int IntVector::pop_back()
{
    if (count == 0)
    {
        throw EmptyException();
    }
    else
    {
        int tempInt = array[count - 1];
        //array[count] = 0;
        count--;
        return tempInt;
    }
}

void IntVector::clear()
{
    for (int i = 0; i < count; ++i)
    {
        array[i] = 0;
    }
    count = 0;
}

// Overloaded operators

void IntVector::operator=(const IntVector& vec)
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

int& IntVector::operator[] (int index) const
{
    if (index >= count || index < 0)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return array[index];
    }
}

ostream& operator<< (ostream& out, const IntVector& rhs)
{
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs[i];
    }
    return out;
}
