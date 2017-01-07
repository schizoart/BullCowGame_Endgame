/* This is the console executable, that makes use of the BullCow class.
It's responsible for all user interaction. For game logic see the FBullCowGame class*/

/* After several hours trying to get the random word picker to work (srand, vector...) I found a solution
that Zaptruder used, so thanks for getting me in the right direction. Zaptruders game is packed with even more options.
I'm quite please with getting this to work. Might add more later on, but for now... on to the next challenge!*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

//function prototypes as outside a class
void PrintInfo();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //instantiate a new game, which we re-use across plays

//the entry point for the application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintInfo();
		PlayGame();
		bPlayAgain = AskToPlayAgain(); 
	} 
	while (bPlayAgain);

	return 0; //exit the application
}

void PrintInfo() 
{
	std::cout << "  _____________________________________________________________\n";
	std::cout << "  ||_________________________________________________________||\n";
	std::cout << "  ||   //                                               \\\\   ||\n";
	std::cout << "  ||  //             Welcome to Bulls & Cows             \\\\  ||\n";
	std::cout << "  ||_//___________________________________________________\\\\_||\n";
	std::cout << "  ||                                                         ||\n";
	std::cout << "  ||      /\\____////___   /\\              ___----___         ||\n";
	std::cout << "  || __///\\ `-         \\-ด /           /\\/          \\/\\      ||\n";
	std::cout << "  ||   _/__`-           \\-ด__        __`-`          ด-ด___   ||\n";
	std::cout << "  ||   \\__@_  _~___\\/_~__)@_/        \\_|จจจ     จจจ   _ค_/-- ||\n";
	std::cout << "  || |       _(o      o)_/             \\(O      O)           ||\n";
	std::cout << "  || \\__          ____\\ )              ( /____          |    ||\n";
	std::cout << "  ||   \         \\@__@/ /               \\ \\@__@/       /      ||\n";
	std::cout << "  ||    \ ด\\__    ___  /                 \\  __     _/---      ||\n";
	std::cout << "  ||      ---\\_______/                   \\_______/--         ||\n";
	std::cout << "  ||_________________________________________________________||\n";
	std::cout << "  ||_________________________________________________________||\n\n";
	std::cout << "  In this game there will be a random isogram with 3-6 letters.\n\n";

	return;
}

//plays a single game to completion
void PlayGame() 
{
	BCGame.Reset();	
	
	std::cout << "       Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	
	int32 MaxTries = BCGame.GetMaxTries();
	FBullCowCount BullCowCount;
	// Loop guesses
		while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{	
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//submit valid Bulls and Cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
		PrintGameSummary();
	return;
}

FText GetValidGuess() 
{	
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invalid_Status;
	do
	{
		int32 GetCurrent = BCGame.GetCurrentTry();
		// guess from player
		
		std::cout << "Try " << GetCurrent << " of " << BCGame.GetMaxTries() ;
		std::cout << ". Please write the word: ";
		std::getline(std::cin, Guess);
	
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::OK:
			return Guess;
		case EWordStatus::Not_Isogram:
			std::cout << "Please write a word.\n\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please use ONLY lowercase letters when writing.\n\n";
			break;
		case EWordStatus::Word_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		default:
			break;
		}
	} while (Status != EWordStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with a random word? (y/n) \n\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return(Response[0] == 'y') || (Response[0] == 'Y');
}
	
void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{ 
		std::cout << "Well done - you figured it out!\n";
	}
		
	else
	{
		std::cout << "Better luck next time. \n";
	}

		
}
