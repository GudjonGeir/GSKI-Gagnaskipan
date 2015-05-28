#include <iostream>
#include "PrefixStringSet.h"
#include "string"

PrefixStringSet::PrefixStringSet()
{
    root = new TrieNode();
}

PrefixStringSet::~PrefixStringSet()
{
    remove_all(root);
}

bool PrefixStringSet::insert(string s)
{
	bool returnValue = false;

	NodePtr iter = root;
	for (unsigned int i = 0; i < s.length(); ++i)
	{
		int n = get_index(s[i]);
		
		if (iter->children[n] == NULL)
		{
			NodePtr nextNode = new TrieNode();
			iter->children[n] = nextNode;
			iter = nextNode;
		}
		else
		{
			iter = iter->children[n];
		}

		if (iter->present)
		{
			returnValue = true;
		}
	}
	iter->present = true;
	if (!iter->is_leaf())
	{
		returnValue = true;
	}
	return returnValue;
}

void PrefixStringSet::remove(string s)
{
    // OPTIONAL
    return;
}

bool PrefixStringSet::contains(string s)
{
    // OPTIONAL
    return true;
}

void PrefixStringSet::remove_all(NodePtr node)
{
    if (node->is_leaf())
    {
    	delete node;
    	return;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
    	if (node->children[i] != NULL)
    	{
    		remove_all(node->children[i]);
    	}
    }
    delete node;
}
