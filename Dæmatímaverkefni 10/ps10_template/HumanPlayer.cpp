#include "HumanPlayer.h"
#include <string>

HumanPlayer::HumanPlayer(string name) : Player(name)
{}

int HumanPlayer::getGuess()
{
	int guess;
	cout << "Enter your guess [0 - 99]: ";
	cin >> guess;
	return guess;
}
