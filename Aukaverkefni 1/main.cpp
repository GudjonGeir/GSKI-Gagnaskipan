#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int n = 0, numberOfInputs = 0;
	queue<int> deck;
	stack<int> outDeck;
	cin >> numberOfInputs;
	cin.ignore();
	for (int i = 0; i < numberOfInputs; ++i)
	{
		cin >> n;
		cin.ignore();
		do {
			deck.push(n);
			for (int i = 0; i < n; ++i)
			{
				int tmp = deck.front();
				deck.pop();
				deck.push(tmp);
			}
			n--;
		} while(n > 0);
		while (!deck.empty())
		{
			outDeck.push(deck.front());
			deck.pop();
		}
		while(!outDeck.empty())
		{
			cout << outDeck.top() << " ";
			outDeck.pop();
		}
		cout << endl;
	}
	return 0;
}
