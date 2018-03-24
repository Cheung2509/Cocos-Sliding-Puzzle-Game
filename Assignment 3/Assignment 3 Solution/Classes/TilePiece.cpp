#include "TilePiece.h"
USING_NS_CC;


TilePiece* TilePiece::create(std::string fileName, int i)
{
	TilePiece* sprite = new TilePiece();

	if (sprite->initWithSpriteFrameName(fileName))		
	{
		sprite->autorelease();

		sprite->initOptions(i);

		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return NULL;
}

void TilePiece::initOptions(int i)
{
	tileNumber = i;
	if (i == 16)
	{
		empty = true;
	}
	else
	{
		empty = false;
	}
}

void TilePiece::setPosX(int x)
{
	posX = x;
}

void TilePiece::setPosY(int y)
{
	posY = y;
}

void TilePiece::setPos()
{
	setPosition((posY * 130) + 70, (posX * -130) + 530);
}

