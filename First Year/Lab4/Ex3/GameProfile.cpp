#include "GameProfile.h"
using namespace std;

int main()
{
	GameProfile Avatar('A', 5, 5000, 50, false, 100);
	printf("Avatar %c started the game!\n", Avatar.getNameInit());
	printf("Level: %d  Coins: %d  Hints: %d  --> Rank: %d\n", Avatar.getLevel(), Avatar.getCoins(), Avatar.getHints(), Avatar.getRank());
	printf("A has %s premium version\n", Avatar.getIsPrem() ? "" : "not");
	printf("A watched %d Ads\n", Avatar.getWatchedAds());

	Avatar.buyHints(50);
	printf("Hints bought successfully .. Coins: %d  Hints: %d\n", Avatar.getCoins(), Avatar.getHints());
	
	Avatar.buyPremiumVersion();
	printf("A is %s Premium User ..Coins: %d\n", Avatar.getIsPrem() ? "" : "NOT", Avatar.getCoins());
	
	GameProfile Katara('K', 2, 2000, 2, true, 200);
	printf("Katara Started the game with %d coins\n", Katara.getCoins());
	bool transSuccess = Avatar.transferCoins(500, Katara);
	printf("Avatar transfered %s coins to Katara, now she has %d\n", transSuccess ? "" : "NO", Katara.getCoins());
	return 0;
}

//Utility fn. to determine if a char is alphabitical
bool isAlpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


GameProfile::GameProfile() {}

GameProfile::GameProfile(char name_init, int l, int c, int h, bool is_prim, int watched_ads)
{
	this->setNameInit(name_init);
	this->setLevel(l);
	this->setCoins(c);
	this->setHints(h);
	this->setPrim(is_prim);
	this->setWatchedAds(watched_ads);
}


void GameProfile::setNameInit(char ni)
{
	this->nameInit = isAlpha(ni) ? ni : '\0'; // \0 is called null character and means nothing
}

void GameProfile::setLevel(int l)
{
	this->level = (l >= 0) ? l : this->level; 
}

void GameProfile::setCoins(int c)
{
	this->coins = (c >= 0) ? c : this->coins;
}

void GameProfile::setHints(int h)
{
	this->hints = (h >= 0) ? h : this->hints;
}

void GameProfile::setPrim(bool isprim)
{
	this->isPremiumVersion = isprim;
}


void GameProfile::setWatchedAds(int ads)
{
	this->watchedAdvertisements = (ads >= 0) ? ads : this->watchedAdvertisements;
}

char GameProfile::getNameInit() 
{
	return this->nameInit;
}

int GameProfile::getLevel() 
{
	return this->level;
}

int GameProfile::getCoins() 
{
	return this->coins;
}

int GameProfile::getHints()
{
	return this->hints;
}

bool GameProfile::getIsPrem() 
{
	return this->isPremiumVersion;
}

int GameProfile::getWatchedAds() 
{
	return this->watchedAdvertisements;
}

bool GameProfile::buyHints(int h)
{
	if (this->coins / 100 < h) return false;
	else {
		this->hints += h;
		this->coins -= h * 100;
		return true;
	}
}

int GameProfile::getRank()
{
	return this->level / 1000;
}

bool  GameProfile::buyPremiumVersion()
{
	if (this->isPremiumVersion) return true;
	else if (this->coins >= 500) {
		this->isPremiumVersion = true;
		this->coins -= 500;
		return true;
	}
	else {
		return false;
	}
}

bool GameProfile::showAdvertise() 
{
	if (this->isPremiumVersion) return true;
	else {
		this->coins += 50;
		this->watchedAdvertisements++;
	}
}

bool GameProfile::transferCoins(int c, GameProfile av)
{
	if (this->coins < c) return false;
	else {
		this->coins -= c;
		av.setCoins(av.getCoins() + c);
	}
}

GameProfile Leader(GameProfile[] GP_Arr, int sz) 
{
	int max = 0;
	GameProfile CurrGP, Lead;
	for (int i = sz - 1; i >= 0; --i) {
		CurrGP = GP_Arr[i];
		if (CurrGP.getLevel > max) Lead = CurrGP;
	}
	return Lead;
}

GameProfile::~GameProfile() {}
