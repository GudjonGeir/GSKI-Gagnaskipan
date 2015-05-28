#include "player.h"


Player::Player(string name)
{
	this->name = name;
	this->wins = 0;
}

int Player::getGuess()
{
	return 0;
}

int Player::getWins()
{
	return wins;
}

string Player::getName()
{
	return name;
}

void Player::setName(string newName)
{
	name = newName;
}

void Player::setWins(int newWin)
{
	wins = newWin;	
}

