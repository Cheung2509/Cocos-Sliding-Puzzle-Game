#pragma once
#include "cocos2d.h"

class TilePiece :public cocos2d::Sprite
{
public:
	//Variables
	bool empty;
	int tileNumber;
	int posX;
	int posY;

	//Functions
	TilePiece() = default;
	~TilePiece() = default;

	static TilePiece* create(std::string fileName, int i);//Function to create the sprite
	void initOptions(int i);//Function to set the initial position and set variables for the class
	//setters
	void setPosX(int x);
	void setPosY(int y);
	void setPos();
private:

};