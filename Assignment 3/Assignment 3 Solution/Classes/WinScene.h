#pragma once
#include "cocos2d.h"

class WinScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void initMenuItems();
	void toGameScene(cocos2d::Ref* sender);
	void closeCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(WinScene);
};