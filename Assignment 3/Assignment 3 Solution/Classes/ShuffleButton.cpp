#include "ShuffleButton.h"
USING_NS_CC;

ShuffleButton* ShuffleButton::create()
{
	ShuffleButton* sprite = new ShuffleButton();

	if (sprite->initWithSpriteFrameName("Shuffle Button.png"))
	{
		sprite->autorelease();

		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return NULL;
}