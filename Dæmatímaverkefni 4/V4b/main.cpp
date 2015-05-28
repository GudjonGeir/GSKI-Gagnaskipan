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
    
}
bool safe_to_publish(string book)
{
	CharStack myStack;
	char parenth, tempChar;
	for (unsigned int i = 0; i < book.length(); ++i)
	{
		parenth = book[i];
		if (parenth == '(' || parenth == '{' || parenth == '[') // Push opening brackets
		{
			myStack.push(parenth);
		}
		else if (parenth == ')')
		{
			if (myStack.empty())
			{
				return false; // To many closing brackets
			}
			else
			{
				tempChar = myStack.pop();
				if (tempChar != '(') // Opening and closing don't match
				{
					return false;
				}
			}
		}
		else if (parenth == '}')
		{
			if (myStack.empty())
			{
				return false;
			}
			else
			{
				tempChar = myStack.pop();
				if (tempChar != '{')
				{
					return false;
				}
			}
		}
		else if (parenth == ']')
		{
			if (myStack.empty())
			{
				return false;
			}
			else
			{
				tempChar = myStack.pop();
				if (tempChar != '[')
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
