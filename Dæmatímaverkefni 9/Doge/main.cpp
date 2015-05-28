#include <iostream>
#include "BloomFilter.h"
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	BloomFilter bloomfilter(30000, 15);
	int inputNumber;
	string inputString;
	//freopen("input", "r", stdin);	

	cin >> inputNumber;
	cin.ignore();
	for (int i = 0; i < inputNumber; ++i)
	{
		getline(cin, inputString);
		bloomfilter.add(inputString);	
	}

	cin >> inputNumber;
	cin.ignore();
	for (int i = 0; i < inputNumber; ++i)
	{
		getline(cin, inputString);
		if (bloomfilter.contains(inputString))
		{
			cout << "Possibly bad" << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
	}

	return 0;
}
