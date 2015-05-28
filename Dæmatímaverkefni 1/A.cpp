#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

void forwrd(int dir, int &x, int &y);
int main()
{
    // Direction: 1 = upp, 2 = hægri, 3 = niður, 4 = vinstri
    int n, direction = 1, x = 0, y = 0;
    string inputString;
    char c;

    cin >> n;
    cin.ignore ();
    for (int i = 0; i < n; i++)
    {
        getline(cin, inputString);
        for(unsigned int j = 0; j < inputString.length(); j++)
        {
            c = inputString[j];
            if (c == 'F')
            {
                forwrd(direction, x, y);
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
        cout << x << " " << y << endl;

        x = 0;
        y = 0;
        direction = 1;
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
