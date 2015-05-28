#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"

#include <iostream>
#include <string>

class HumanPlayer : public Player
{
	public:
		int getGuess();
		HumanPlayer(string name);
};

#endif
