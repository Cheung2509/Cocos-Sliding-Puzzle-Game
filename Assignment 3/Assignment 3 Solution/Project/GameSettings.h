#pragma once

class GameSetting
{
	//Variables
	static int difficulty;
	int numTiles;
	int numRowsCols;

	//Functions
	void setDifficulty(int i);
	GameSetting();
	~GameSetting();
};