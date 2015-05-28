#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
using namespace std;

bool checkForWin(int guess, int answer, int guessNumber) {
    cout << "Guess no. " << guessNumber << ", you guessed " << guess << ". ";
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess is too high." << endl;
    }
    else {
        cout << "Your guess is too low." << endl;
    }
    return false;
}

void play(Player& player1, Player& player2) {
    int answer = 0, guess = 0, guessNumber = 0;
    answer = rand() % 100;
    bool win = false;

    while (!win) {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        guessNumber++;
        win = checkForWin(guess, answer, guessNumber);
        if (win) {
            player1.setWins(player1.getWins() + 1);
            return;
        }
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess();
        guessNumber++;
        win = checkForWin(guess, answer, guessNumber);
        if (win) {
            player2.setWins(player2.getWins() + 1);
        }
    }
}

void printWelcome()
{
	cout << "Welcome to Grand Theft Guessing!" << endl;
}

void printMenu()
{
	cout << "****************************" << endl
	<< "Select the game type (1-3) from the menu, any other number to quit" << endl
	<< "1. Human vs. Human" << endl
	<< "2. Human vs. Computer" << endl
	<< "3. Computer vs. Computer" << endl
	<< "****************************" << endl;
}

int getSeed()
{
	cout << "Seed: ";
	int seed;
	cin >> seed;
	return seed;
}

int main()
{
	HumanPlayer hp1("Human player 1"), hp2("Human player 2");
	ComputerPlayer cp1("Computer player 1"), cp2("Computer player 2");

	printWelcome();
	srand(getSeed());
	printMenu();
	int input = 0;
	cin >> input;
	while(input < 4 && input > 0)
	{
		if (input == 1)
		{
			play(hp1, hp2);
		}
		else if (input == 2)
		{
			play(hp1, cp1);
		}
		else
		{
			play(cp1, cp2);
		}
		printMenu();
		cin >> input;
	}
	cout << "********** Results **********" << endl;
	cout << hp1.getName() << " won " << hp1.getWins() << " times." << endl;
	cout << hp2.getName() << " won " << hp2.getWins() << " times." << endl;
	cout << cp1.getName() << " won " << cp1.getWins() << " times." << endl;
	cout << cp2.getName() << " won " << cp2.getWins() << " times." << endl;

	return 0;
}
