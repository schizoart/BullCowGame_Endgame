#pragma once

#include "FBullCowGame.h"
#include <string>
#include <time.h>
#include <map>
//to make the syntax Unreal friendly
#define TMap std::map 
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const //How hard will it be?
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,5}, {4,7}, {5,9}, {6,13}, {7,19} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyHiddenWord = IsogramPicker();
	bGameIsWon = false;
	return;	

}

FString FBullCowGame::IsogramPicker()
{
	srand(time(0));
	//48 3-letter, 50 4-letter, 49 5-letter, 48 6-letter
/*	FString HIDDEN_WORD;
	FString IsoPick[195] = {
		"act", "art", "bat", "box", "cow", "cup", "dry", "dip", "ear", "emu", "few", "fox", "gun", "gin", "hit", "hag", "ink", "ice", "job", "jar", "key", "kid", "low", "lie", "map", "mix", "nag", "nut", "owl", "orb", "pen", "pig", "rip", "run", "sex", "spy", "tea", "toy", "urn", "use", "vow", "war", "why", "wet", "you", "yes", "zap", "zip",
		"acid", "arch", "body", "brim", "cage", "club", "deny", "dish", "evil", "echo", "flat", "foil", "glow", "game", "haze", "hurt", "itch", "idea", "jerk", "joke", "king", "knot", "lamb", "lost", "myth", "mind", "neat", "node", "open", "over", "pink", "poet", "quit", "quiz", "rose", "race", "scar", "shop", "town", "tube", "ugly", "unit", "vibe", "vast", "warp", "wipe", "yarn", "yoga", "zero", "zone",
		"adore", "alien", "banjo", "buyer", "curse", "crazy", "death", "demon", "entry", "exact", "filth", "force", "ghoul", "gecko", "hyper", "house", "image", "ivory", "juice", "judge", "knife", "laced", "libra", "lucky", "magic", "morph", "nurse", "naive", "ocean", "opera", "paint", "piano", "quick", "quiet", "route", "rival", "scare", "short", "tiger", "topic", "ultra", "unify", "virus", "venom", "water", "wrath", "yacht", "young", "zebra",
		"agency", "answer", "brutal", "bleach", "corpse", "cinema", "deploy", "devour", "egoist", "export", "fabric", "flaunt", "genial", "gnomes", "hornet", "hunter", "ignore", "inhale", "jumper", "jockey", "keypad", "kidney", "lizard", "locker", "master", "morale", "novice", "nickel", "obtain", "oracle", "peanut", "plague", "remain", "runway", "sacred", "sample", "serial", "silent", "tongue", "travel", "unfair", "upload", "vanish", "vector", "wrench", "wealth", "zenith", "zodiac"

	};*/
	int32 number = (rand() % 195);
	
	return IsoPick[number];
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EWordStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EWordStatus::Word_length;
	}
	else
	{
		return EWordStatus::OK;
	}
}
// recieves a valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();

	for (int32 i = 0; i < WordLength; i++)
	{
		for (int32 j = 0; j < WordLength; j++)
		{
			if (Guess[j] == MyHiddenWord[i]) 
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}

		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false; 
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) {return true;}

	TMap <char, bool> LetterSeen;

	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		
		if (LetterSeen[Letter]) 
		{ 
			return false; 
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{ 
		if(!islower(Letter))
		{
			return false; 
		}

	}
	return true;
}
