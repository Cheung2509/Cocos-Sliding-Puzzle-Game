#include "GameScene.h"
#include "MainMenu.h"
#include "WinScene.h"
USING_NS_CC;

cocos2d::Scene* WinScene::createScene()
{
	cocos2d::Scene* scene = Scene::create();
	auto layer = WinScene::create();

	scene->addChild(layer);

	return scene;
}

bool WinScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	cocos2d::Label* label = Label::createWithTTF("You Win!", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(512, 500));
	this->addChild(label, 1);
	initMenuItems();

	return true;
}

void WinScene::initMenuItems()
{
	//Creating menu itemm to play the game
	MenuItemFont* playAgain = MenuItemFont::create(
		"Play Again",
		CC_CALLBACK_1(WinScene::toGameScene, this));
	//Creating menu item to exit the application
	MenuItemFont* mainMenuExit = MenuItemFont::create(
		"Exit Game",
		CC_CALLBACK_1(WinScene::closeCallBack, this));

	cocos2d::Menu* menu = Menu::create(playAgain, mainMenuExit, nullptr);
	menu->alignItemsVertically();
	this->addChild(menu, 1);
}

void WinScene::toGameScene(cocos2d::Ref* sender)
{
	Director::getInstance()->replaceScene(
		TransitionFlipY::create(2, GameScene::createScene()));
}

void WinScene::closeCallBack(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}