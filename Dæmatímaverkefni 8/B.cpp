#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void forwrd(int dir, int &x, int &y);
void trip(string instruction, vector <int>& xaxis, vector <int>& yaxis);
void circularTest(vector <int> x, vector <int> y);
int main()
{
    // Direction: 1 = upp, 2 = hægri, 3 = niður, 4 = vinstri
    int n;
    string inputString;

    vector <int> xaxis;
    vector <int> yaxis;

    cin >> n;
    cin.ignore ();
    for (int i = 0; i < n; i++)
    {
        xaxis.push_back(0);
        yaxis.push_back(0);
        getline(cin, inputString);
        trip(inputString, xaxis, yaxis);
        circularTest(xaxis, yaxis);
        xaxis.clear();
        yaxis.clear();
    }
    return 0;
}
void trip(string instruction, vector <int>& xaxis, vector <int>& yaxis)
{
	int direction = 1, x = 0, y = 0;
	char c;
	for(unsigned int j = 0; j < instruction.length(); j++)
        {
            c = instruction[j];
            if (c == 'F')
            {
                forwrd(direction, x, y);
                xaxis.push_back(x);
                yaxis.push_back(y);
            }
            else if (c == 'H')
            {
                direction++;
                if(direction == 5)
                {
                    direction = 1;
                }
            }
            else if (c == 'V')
            {
                direction--;
                if(direction == 0)
                {
                    direction = 4;
                }
            }
            else
            {
                cout << "Unexpected error";
                exit(0);
            }

        }
}
void forwrd(int dir, int &x, int &y)
{
    if(dir == 1)
    {
        y++;
    }
    else if(dir == 2)
    {
        x++;
    }
    else if(dir == 3)
    {
        y--;
    }
    else if(dir == 4)
    {
        x--;
    }
    else
    {
        cout << "Unexpected error";
        exit(0);
    }
}
void circularTest(vector <int> x, vector <int> y)
{
	bool circular = false;
	int n = x.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{

			}
			else if(x[i] == x[j] && y[i] == y[j])
			{

				circular = true;
			}
		}
	}
	if (circular == true)
	{
		cout << "Circular" << endl;
	}
	else
	{
		cout << "OK" << endl;
	}
}
