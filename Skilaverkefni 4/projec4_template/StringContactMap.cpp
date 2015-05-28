#include "StringContactMap.h"
#include "Hash.h"

#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
	this->capacity = initial_capacity;
	this->count = 0;
	this->map = new ContactList*[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		map[i] = NULL;
	}
}

StringContactMap::~StringContactMap()
{
	for (int i = 0; i < capacity; ++i)
	{
		if (map[i] != NULL)
		{
			delete map[i];
		}
	}
	delete[] map;
}

void StringContactMap::load_check()
{
	if ((count / capacity) > MAX_LOAD)
	{
		rebuild();
	}
}

void StringContactMap::rebuild()
{
	int oldCapacity = capacity;
	vector<StringContactPair> vec;

	ListPtr *oldMap = map;
	capacity *= 2;
	map = new ContactList*[capacity];
	
	for (int i = 0; i < capacity; ++i)
	{
		map[i] = NULL;
	}

	for (int i = 0; i < oldCapacity; ++i)
	{
		if (oldMap[i] == NULL)
		{
			continue;
		}
		vec = oldMap[i]->to_vector();
		for (unsigned int j = 0; j < vec.size(); ++j)
		{
			add(vec[j].key, vec[j].value);
		}
		//vector<StringContactPair>::iterator it = vec.begin();
		//vec.insert(vec.begin(), tmpVec.begin(), tmpVec.end());
	
	}
		
	
	for (int i = 0; i < oldCapacity; ++i)
	{
		if (oldMap[i] != NULL)
		{
			delete oldMap[i];
		}
	}

	delete[] oldMap;
}

int StringContactMap::size() const
{
	return count;
}

bool StringContactMap::empty() const
{
	return (count == 0);
}

vector<Contact> StringContactMap::all_contacts() const
{
	vector<Contact> returnVec;
	for (int i = 0; i < capacity; ++i)
	{
		if (map[i] != NULL)
		{
			map[i]->get_contacts(returnVec);
		}
	}
	return returnVec;
}

void StringContactMap::add(string key, Contact value)
{	
	load_check();
	unsigned int hashNumber = hashFunc(key) % capacity;
	if (map[hashNumber] == NULL)
	{
		map[hashNumber] = new ContactList();
	}
	if (map[hashNumber]->add(key, value))
	{
		count++;
	}
}

void StringContactMap::remove(string key)
{
	unsigned int hashNumber = hashFunc(key) % capacity;
	if (map[hashNumber] == NULL)
	{
		return;
	}
	if (map[hashNumber]->remove(key))
	{
		count--;
	}
}

bool StringContactMap::contains(string key) const
{
	unsigned int hashNumber = hashFunc(key) % capacity;
	if (map[hashNumber] == NULL)
	{
		return false;
	}
	return map[hashNumber]->contains(key);
}

Contact StringContactMap::get(string key) const
{
	unsigned int hashNumber = hashFunc(key) % capacity;
	if (map[hashNumber] == NULL)
	{
		map[hashNumber] = new ContactList();
	}

	return map[hashNumber]->get(key);
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
	vector<Contact> vec;
	for (int i = 0; i < capacity; ++i)
	{
		if (map[i] != NULL)
		{
			map[i]->get_contacts_by_prefix(prefix, vec);
		}

	}
	return vec;
}

// Optionally implement.
ostream& operator <<(ostream& out, const StringContactMap& map)
{
	vector<Contact> vec = map.all_contacts();
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		out << vec[i] << endl; 
	}
	return out;
}

