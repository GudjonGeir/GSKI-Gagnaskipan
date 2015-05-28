#include <iostream>
#include <string>
#include "CharStack.h"

using namespace std;

bool safe_to_publish(string book);
int main()
{
    string myString;

    getline(cin, myString);

    if (safe_to_publish(myString))
    {
    	cout << "Publish!" << endl;
    }
    else
    {
    	cout << "Fix brackets" << endl;
    }
    return 0;
}
bool safe_to_publish(string book)
{
	CharStack myStack;
	char parenth, tempChar;
	for (unsigned int i = 0; i < book.length(); ++i)
	{
		parenth = book[i];
		if (isupper(parenth)) // Push opening brackets
		{
			myStack.push(parenth);
		}
		else if (islower(parenth))
		{
			if (myStack.empty())
			{
				return false; // To many closing brackets
			}
			else
			{
				tempChar = myStack.pop();
				if (tempChar != toupper(parenth)) // Opening and closing don't match
				{
					return false;
				}
			}
		}
		else // Not a bracket
		{
			return false;
		}
	}
	if (myStack.empty()) // Correctly nested
	{
		return true;
	}
	else // To many opening brackets
	{
		return false;
	}
}
