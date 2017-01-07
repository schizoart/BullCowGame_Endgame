/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind*/

#pragma once
#include <string>
#include <map>
#include <vector>
#define TMap std::map

//to make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Lowercase,
	Word_length
};


class FBullCowGame 
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const; 
	FString IsogramPicker();

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for init
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	FString HiddenIsogram; // not used?
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

 	TMap <int32, FString> IsoPick { 
			// 3-letter words
		{0, "act"},
		{1, "art"},
		{2, "bat"},
		{3, "box"},
		{4, "cow"},
		{5, "cup"},
		{6, "dry"},
		{7, "dip"},
		{8, "ear"},
		{9, "emu"},
		{10, "few"},
		{11, "fox"},
		{12, "gun"},
		{13, "gin"},
		{14, "hit"},
		{15, "hag"},
		{16, "ink"},
		{17, "ice"},
		{18, "job"},
		{19, "jar"},
		{20, "key"},
		{21, "kid"},
		{22, "low"},
		{23, "lie"},
		{24, "map"},
		{25, "mix"},
		{26, "nag"},
		{27, "nut"},
		{28, "owl"},
		{29, "orb"},
		{30, "pen"},
		{31, "pig"},
		{32, "rip"},
		{33, "run"},
		{34, "sex"},
		{35, "spy"},
		{36, "tea"},
		{37, "toy"},
		{38, "urn"},
		{39, "use"},
		{40, "vow"},
		{41, "war"},
		{42, "why"},
		{43, "wet"},
		{44, "you"},
		{45, "yes"},
		{46, "zap"},
		{47, "zip"},
			//4-letter words
		{48, "acid"},
		{49, "arch"},
		{50, "body"},
		{51, "brim"},
		{52, "cage"},
		{53, "club"},
		{54, "deny"},
		{55, "dish"},
		{56, "evil"},
		{57, "echo"},
		{58, "flat"},
		{59, "foil"},
		{60, "glow"},
		{61, "game"},
		{62, "haze"},
		{63, "hurt"},
		{64, "itch"},
		{65, "idea"},
		{66, "jerk"},
		{67, "joke"},
		{68, "king"},
		{69, "knot"},
		{70, "lamb"},
		{71, "lost"},
		{72, "myth"},
		{73, "mind"}, 
		{74, "neat"},
		{75, "node"},
		{76, "open"},
		{77, "over"},
		{78, "pink"},
		{79, "poet"},
		{80, "quit"},
		{81, "quiz"},
		{82, "rose"},
		{83, "race"},
		{84, "scar"},
		{85, "shop"},
		{86, "town"},
		{87, "tube"},
		{88, "ugly"},
		{89, "unit"},
		{90, "vibe"},
		{91, "vast"},
		{92, "warp"},
		{93, "wipe"},
		{94, "yarn"},
		{95, "yoga"},
		{96, "zero"},
		{97, "zone"},
			//5-letter words
		{ 98, "adore" },
		{ 99, "alien" },
		{ 100, "banjo" },
		{ 101, "buyer" },
		{ 102, "curse" },
		{ 103, "crazy" },
		{ 104, "death" },
		{ 105, "demon" },
		{ 106, "entry" },
		{ 107, "exact" },
		{ 108, "filth" },
		{ 109, "force" },
		{ 110, "ghoul" },
		{ 111, "gecko" },
		{ 112, "hyper" },
		{ 113, "house" },
		{ 114, "image" },
		{ 115, "ivory" },
		{ 116, "juice" },
		{ 117, "judge" },
		{ 118, "knife" },
		{ 119, "laced" },
		{ 120, "libra" },
		{ 121, "lucky" },
		{ 122, "magic" },
		{ 123, "morph" },
		{ 124, "nurse" },
		{ 125, "naive" },
		{ 126, "ocean" },
		{ 127, "opera" },
		{ 128, "paint" },
		{ 129, "piano" },
		{ 130, "quick" },
		{ 131, "quiet" },
		{ 132, "route" },
		{ 133, "rival" },
		{ 134, "scare" },
		{ 135, "short" },
		{ 136, "tiger" },
		{ 137, "topic" },
		{ 138, "ultra" },
		{ 139, "unify" },
		{ 140, "virus" },
		{ 141, "venom" },
		{ 142, "water" },
		{ 143, "wrath" },
		{ 144, "yacht" },
		{ 145, "young" },
		{ 146, "zebra" },
			//6-letter words
		{ 147, "agency" },
		{ 148, "answer" },
		{ 149, "brutal" },
		{ 150, "bleach" },
		{ 151, "corpse" },
		{ 152, "cinema" },
		{ 153, "deploy" },
		{ 154, "devour" },
		{ 155, "egoist" },
		{ 156, "export" },
		{ 157, "fabric" },
		{ 158, "flaunt" },
		{ 159, "genial" },
		{ 160, "gnomes" },
		{ 161, "hornet" },
		{ 162, "hunter" },
		{ 163, "ignore" },
		{ 164, "inhale" },
		{ 165, "jumper" },
		{ 166, "jockey" },
		{ 167, "keypad" },
		{ 168, "kidney" },
		{ 169, "lizard" },
		{ 170, "locker" },
		{ 171, "master" },
		{ 172, "morale" },
		{ 173, "novice" },
		{ 174, "nickel" },
		{ 175, "obtain" },
		{ 176, "oracle" },
		{ 177, "peanut" },
		{ 178, "plague" },
		{ 179, "remain" },
		{ 180, "runway" },
		{ 181, "sacred" },
		{ 182, "sample" },
		{ 183, "serial" },
		{ 184, "silent" },
		{ 185, "tongue" },
		{ 186, "travel" },
		{ 187, "unfair" },
		{ 188, "upload" },
		{ 189, "vanish" },
		{ 190, "vector" },
		{ 191, "wrench" },
		{ 192, "wealth" },
		{ 193, "zenith" },
		{ 194, "zodiac" },

};

};
