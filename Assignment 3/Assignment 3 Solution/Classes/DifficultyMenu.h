#pragma once
#include "cocos2d.h"

class DifficultyMenu :public cocos2d::Layer
{
public:
	//Functions
	static cocos2d::Scene* createScene();
	virtual bool init();
	void initDifficulty();
	void easyDifficulty();
	void mediumDifficulty();
	void hardDifficulty();


	CREATE_FUNC(DifficultyMenu);

private:
};