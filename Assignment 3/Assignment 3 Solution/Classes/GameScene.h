#pragma once
#include "cocos2d.h"
#include "TilePiece.h"
#include "ShuffleButton.h"
class GameScene :public cocos2d::Layer
{
public:
	TilePiece* tilePiece[16]; //array for tiles
	ShuffleButton* shuffleButton;
	int tilePos[4][4]; //array for tiles positions
	int correctPos[4][4]; //array of tiles in the correct position
	bool win;
	//Functions
	static cocos2d::Scene* createScene();//Function to create scene
	virtual bool init();//function to initialise scene
	void initTiles();//function to initialise tiles
	void initShuffleButton();//function to initialise shuffle button
	void shuffleBoard(); //function to shuffle the board
	void initBackToMainMenu(); // initialise menu items to go back to the main menu
	void backToMainMenu(cocos2d::Ref* sender); //function to go back to menu scene
	void onMouseDown(cocos2d::EventMouse* mouse);//function to called when the mouse button is pressed
	void checkMove(int i);//function called to check and move tile
	void checkWin();//function to check if the player has won
	CREATE_FUNC(GameScene);

private:

};