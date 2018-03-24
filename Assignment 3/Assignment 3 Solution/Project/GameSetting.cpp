#include "GameSettings.h"

GameSetting::GameSetting()
{
	difficulty = 1;
	numRowsCols = 3;
	numTiles = numRowsCols*numRowsCols;
}

void GameSetting::setDifficulty(int i)
{
	difficulty = i;

	//Changing difficulty according to what the user has selected
	switch (difficulty)
	{
	case 1:
		numRowsCols = 3;
		numTiles = numRowsCols*numRowsCols;
		break;
	case 2:
		numRowsCols = 4;
		numTiles = numRowsCols*numRowsCols;
	case 3:
		numRowsCols = 5;
		numTiles = numRowsCols*numRowsCols;
	default:
		break;
	}
}

GameSetting::~GameSetting()
{

}