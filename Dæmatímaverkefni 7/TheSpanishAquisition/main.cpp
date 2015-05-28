#include <iostream>
#include "PrefixStringSet.h"
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	PrefixStringSet trie;
	bool consistency = true;
	//freopen("input3.txt", "r", stdin);
	int n = 0;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        string inputString;
        getline(cin, inputString);
		if(trie.insert(inputString))
		{
			consistency = false;
		}
    }
    if (consistency)
    {
    	cout << "YES" << endl;
    }
    else
    {
    	cout << "NO" << endl;
    }
    return 0;
}