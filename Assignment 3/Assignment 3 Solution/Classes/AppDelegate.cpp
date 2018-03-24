#include "AppDelegate.h"
#include "MainMenu.h"
USING_NS_CC;

bool AppDelegate::applicationDidFinishLaunching() 
{
	//Setting up all the parameters of the GL Window

	cocos2d::Director* director = Director::getInstance();
	cocos2d::GLView* glview = director->getOpenGLView();
	if (!glview)
	{
		glview = GLViewImpl::create("Puzzle Game"); //Setting the Window name
		glview->setFrameSize(1024, 600); //Setting the resolution of the game
		director->setOpenGLView(glview);
	}
	auto scene = MainMenu::createScene();
	director->runWithScene(scene);
	return true;
}

void AppDelegate::applicationDidEnterBackground() 
{

}

void AppDelegate::applicationWillEnterForeground() 
{

}