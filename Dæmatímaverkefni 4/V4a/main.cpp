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
	char parenth;
	for (unsigned int i = 0; i < book.length(); ++i)
	{
		parenth = book[i];
		if (parenth == '(')
		{
			myStack.push(parenth);
		}
		else if (parenth == ')')
		{
			if (myStack.empty())
			{
				return false;
			}
			else
			{
				myStack.pop();
			}
		}
	}
	if (myStack.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
