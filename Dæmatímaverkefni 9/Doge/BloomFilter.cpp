#include "BloomFilter.h"

BloomFilter::BloomFilter(int size, int hashes)
{
	this->hash_collection = new HashCollection(hashes);
	this->size = size;
	this->filter = new bool[size];
	for (int i = 0; i < size; ++i)
	{
		filter[i] = false;
	}
}

BloomFilter::~BloomFilter()
{
	delete[] filter;
	delete hash_collection;
}

void BloomFilter::add(string s)
{
	for (int i = 0; i < hash_collection->size(); ++i)
	{
		int hashKey = hash_collection->get_hash(i, s) % size;
		filter[hashKey] = true;
	}
}

bool BloomFilter::contains(string s)
{
	for (int i = 0; i < hash_collection->size(); ++i)
	{
		int hashKey = hash_collection->get_hash(i, s) % size;
		if (!filter[hashKey])
		{
			return false;
		}
	}
	return true;
}
