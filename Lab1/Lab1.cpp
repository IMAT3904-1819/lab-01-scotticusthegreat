// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int playerGuess;
int randomNumber;
int numberOfGuesses;
int guessCounter = 5;
char playAgain;
bool numberGuessed;

int main()
{
	//srand(time(NULL));

	//randomNumber = rand() % 100 + 1;

	std::cout << "----- RANDOM NUMBER GUESSING GAME -----\n" << std::endl;
	std::cout << "A random number between 1 - 100 will be generated. You will get 5 guesses. Enter your guess\n";
	std::cout << "and the computer will tell you if your guess is too high, too low or correct!\n" << std::endl;
	std::cout << "Enter your guess: ";
	std::cin >> playerGuess;
	numberOfGuesses++;
	guessCounter--;
	std::cout << "\nYou have " << guessCounter << " guess(es) remaining!" << std::endl;

	while (!numberGuessed)
	{
		srand(time(NULL));

		randomNumber = rand() % 100 + 1;

		while (numberOfGuesses < 5)
		{
			if (playerGuess > randomNumber)
			{
				guessCounter--;
				std::cout << "The number is lower than your guess. Try again!\n" << std::endl;
				std::cout << "Enter your guess: ";
				std::cin >> playerGuess;
				std::cout << "\nYou have " << guessCounter << " guess(es) remaining!" << std::endl;
				numberOfGuesses++;
				
			}

			else if (playerGuess < randomNumber)
			{
				guessCounter--;
				std::cout << "The number is higher than your guess. Try again!\n" << std::endl;
				std::cout << "Enter your guess: ";
				std::cin >> playerGuess;
				std::cout << "\nYou have " << guessCounter << " guess(es) remaining!" << std::endl;
				numberOfGuesses++;
			}
		}
		
		if (playerGuess == randomNumber)
		{
			std::cout << "Congratulations! You guessed the number in " << numberOfGuesses << " guesses!\n" << std::endl;
			std::cout << "Would you like to play again? (Y/N) ";
			std::cin >> playAgain;

			if (playAgain == 'Y' || playAgain == 'y')
			{
				numberGuessed = false;
			}

			if (playAgain == 'N' || playAgain == 'n')
			{
				numberGuessed = true;
			}
		}

		else if (numberOfGuesses >= 5)
		{
			std::cout << "You have used all five of your guesses. You lose!\n" << std::endl;
			std::cout << "The number you were looking for was: " << randomNumber << "\n" << std::endl;
			std::cout << "Would you like to play again? (Y/N) ";
			std::cin >> playAgain;

			if (playAgain == 'Y' || playAgain == 'y')
			{
				numberGuessed = false;
			}

			if (playAgain == 'N' || playAgain == 'n')
			{
				break;
			}
		}
	}

	system("PAUSE");
    return 0;
}

