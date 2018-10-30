#include <iostream>
#pragma once

class GameProfile
{
	char nameInit;
	int level = 0;
	int coins = 0;
	int hints = 3;
	bool isPremiumVersion = false;
	int watchedAdvertisements = 0;
public:
	GameProfile();
	GameProfile(char name_init, int l, int c, int h, bool is_prim, int watched_ads);
	void setNameInit(char ni);
	void setLevel(int l);
	void setCoins(int c);
	void setHints(int h);
	void setPrim(bool isprim);
	void setWatchedAds(int ads);
	char getNameInit();
	int getLevel();
	int getCoins();
	int getHints();
	bool getIsPrem();
	int getWatchedAds();
	bool buyHints(int h);
	int getRank();
	bool buyPremiumVersion();
	bool showAdvertise();
	bool transferCoins(int c, GameProfile av);
	~GameProfile();
};

