#include "DifficultyMenu.h"
#include "MainMenu.h"
USING_NS_CC;

//Function to create a scene
cocos2d::Scene*DifficultyMenu::createScene()
{

	cocos2d::Scene*scene = Scene::create();
	auto layer = DifficultyMenu::create();

	scene->addChild(layer);

	return scene;
}
//Function to initialise the difficulty menu
bool DifficultyMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	cocos2d::Label* title = Label::createWithTTF("Difficulty", "fonts/Marker Felt.ttf", 24);
	title->setPosition(Vec2(320, 400));
	this->addChild(title, 1);
	initDifficulty();

	return true;
}

void DifficultyMenu::initDifficulty()
{
	//Creating menu item to set the difficulty to easy
	MenuItemFont* easy = MenuItemFont::create(
		"Easy",
		CC_CALLBACK_0(DifficultyMenu::easyDifficulty, this));
	//Creating menu item to set the difficulty to medium
	MenuItemFont* medium = MenuItemFont::create(
		"Medium",
		CC_CALLBACK_0(DifficultyMenu::mediumDifficulty, this));
	//Creating menu item to set the difficulty to hard
	MenuItem* hard = MenuItemFont::create(
		"Hard",
		CC_CALLBACK_0(DifficultyMenu::hardDifficulty, this));
	cocos2d::Menu* menuDifficulty = Menu::create(easy, medium, hard, nullptr);
	menuDifficulty->alignItemsVertically();
	this->addChild(menuDifficulty, 1);
}

void DifficultyMenu::easyDifficulty()
{
	Director::getInstance()->pushScene(
		TransitionFlipY::create(2, MainMenu::createScene()));
}

void DifficultyMenu::mediumDifficulty()
{
	Director::getInstance()->pushScene(
		TransitionFlipY::create(2, MainMenu::createScene()));
}

void DifficultyMenu::hardDifficulty()
{
	Director::getInstance()->pushScene(
		TransitionFlipY::create(2, MainMenu::createScene()));
}