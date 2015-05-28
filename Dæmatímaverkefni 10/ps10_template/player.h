#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
	public:
		Player(string name);
		virtual int getGuess();
		int getWins();
		string getName();
		void setName(string newName);
		void setWins(int newWin);
	private:
		string name;
		int wins;
};

#endif

