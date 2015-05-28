#include "ComputerPlayer.h"
#include <cstdlib>
#include <string>

ComputerPlayer::ComputerPlayer(string name) : Player(name)
{}

int ComputerPlayer::getGuess()
{
	return rand() % 100;
}
