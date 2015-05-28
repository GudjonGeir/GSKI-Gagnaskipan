#include <iostream>
#include "StringSet.h"

using namespace std;

int main()
{
	StringSet myList;
	string myString;
	while(getline(cin, myString))
	{
		if (myString == "#")
		{
			break;
		}
		myList.insert(myString);
	}
	cout << myList.size() << endl;

	cout << myList;

    return 0;
}
