#include "GameScene.h"
#include "MainMenu.h"
#include "WinScene.h"
USING_NS_CC;

cocos2d::Scene* GameScene::createScene()
{
	cocos2d::Scene*scene = Scene::create();
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}
//Function to initialise layer
bool GameScene::init()
{	
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("SpriteSheet.plist");

	initBackToMainMenu();
	initShuffleButton();
	initTiles();
	auto listener = cocos2d::EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(GameScene::onMouseDown, this);
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, -1);
	return true;
}
//initialise button to get back to the main menu
void GameScene::initBackToMainMenu()
{
	MenuItemFont* backToMainMenu = MenuItemFont::create(
		"Back to Main Menu",
		CC_CALLBACK_1(GameScene::backToMainMenu, this));
	cocos2d::Menu* menu = Menu::create(backToMainMenu, nullptr);
	menu->setPosition(800, 550);
	this->addChild(menu, 1);
}
//Initialise the shuffle button
void GameScene::initShuffleButton()
{
	shuffleButton = ShuffleButton::create();
	shuffleButton->setPosition(800, 500);
	this->addChild(shuffleButton);
}
//Initialising the tiles
void GameScene::initTiles()
{
	win = false;
	//Creating sprites for the tiles
	int i = 0;//Tile number
	//For loop to assign sprite on to t.
	for (int i = 0; i < 16; i++)
	{
			//String of sprite name
			std::string fileName = "Tile" + std::to_string(i + 1) + ".png";
			//initialising sprite
			tilePiece[i] = TilePiece::create(fileName, i + 1);
			//Adding sprite to scene
			addChild(tilePiece[i], 1);
	}
	//Assign tilesNumber to an array
	i = 0;
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			//get tile number
			int t = tilePiece[i]->tileNumber;
			//setting tile number to array
			tilePos[c][r] = t;
			//Setting the correct positions of the grid to compare to tiles current positions.
			correctPos[c][r] = t;
			//Setting position of the tiles relative to array
			tilePiece[i]->setPosX(c);
			tilePiece[i]->setPosY(r);
			tilePiece[i]->setPos();
			i++;
		}
	}


}
//Initiliase button to go back to the main menu
void GameScene::backToMainMenu(cocos2d::Ref* sender)
{
	//removing event listener
	_eventDispatcher->removeAllEventListeners();
	//changing scene to the main menu
	Director::getInstance()->replaceScene(
		TransitionFlipY::create(2, MainMenu::createScene()));
}
//Function to shuffle the board
void GameScene::shuffleBoard()
{
	//Creating boolean array to check if a coordinat in the array is occupied
	bool spaceOccupied[4][4];
	//for loop to set all of the array to false whenever the board needs to be shuffled
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			spaceOccupied[c][r] = false;
		}
	}
	//creating seed for random number generator
	srand(time(NULL));
	//for loop to to assign tiles to the grid
	for (int i = 0; i < 16; i++)
	{
		//Generat random number for coordinates
		int y = rand() % 4;
		int x = rand() % 4;
		//if that space is not occupied
		if (spaceOccupied[x][y] != true)
		{
			//set tile positions
			tilePiece[i]->setPosX(x);
			tilePiece[i]->setPosY(y);
			tilePiece[i]->setPos();
			//Assign tile ID to grid
			tilePos[x][y] = tilePiece[i]->tileNumber;
			//set coordinate to true
			spaceOccupied[x][y] = true;
		}
		else
		{
			i--;//decrement i to generat a random number until it finds an unoccupied space
		}
	}
}
//When the mouse button is pressed
void GameScene::onMouseDown(cocos2d::EventMouse* mouse)
{
	//Assign loocation of mouse
	cocos2d::Vec2 p = mouse->getLocation();
	//Assigning bounding box of shuffle button
	cocos2d::Rect shuffleButtonLoc = shuffleButton->getBoundingBox();
	//Assigning bounding box of tiles
	cocos2d::Rect tile[16];
	for (int i = 0; i < 16; i++)
	{
		tile[i] = tilePiece[i]->boundingBox();
	}

	//if the mouse clicks the button
	if (shuffleButtonLoc.containsPoint(p))
	{
		shuffleBoard();//call shuffle function
	}

	for (int i = 0; i < 16; i++)
	{
		if (tile[i].containsPoint(p))
		{
			checkMove(i);
		}
	}
}
//Function to move tile if it can
void GameScene::checkMove(int i )
{

	int x = tilePiece[i]->posX;
	int y = tilePiece[i]->posY;
	//if the square clicked is not tile 16(blank tile)
	if (tilePos[x][y] != 16)
	{
		//Checking if an empty square is next to the select tile
		if (tilePos[x][y + 1] == 16 && y + 1 <= 4)
		{
			tilePos[x][y + 1] = tilePiece[i]->tileNumber;
			tilePiece[i]->setPosY(y + 1);
			tilePiece[i]->setPos();

			tilePos[x][y] = 16;

		}
		else if (tilePos[x][y - 1] == 16 && y - 1 >= 0)
		{
			tilePos[x][y - 1] = tilePiece[i]->tileNumber;
			tilePiece[i]->setPosY(y - 1);
			tilePiece[i]->setPos();

			tilePos[x][y] = 16;
		}
		else if (tilePos[x+1][y] == 16 && x+1 <= 4)
		{
			tilePos[x + 1][y] = tilePiece[i]->tileNumber;
			tilePiece[i]->setPosX(x + 1);
			tilePiece[i]->setPos();

			tilePos[x][y] = 16;
		}
		else if (tilePos[x - 1][y] == 16 && x - 1 >= 0)
		{
			tilePos[x - 1][y] = tilePiece[i]->tileNumber;
			tilePiece[i]->setPosX(x - 1);
			tilePiece[i]->setPos();

			tilePos[x][y] = 16;
		}
		//call function to check if player has won
		checkWin();
	}
}
//Function to check if the the game has won
void GameScene::checkWin()
{
	int correctTiles = 0; //number of correct tiles
	//for loop to check how many tile are in the correct position
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			//if the tile is in the correct place
			if (tilePos[c][r] == correctPos[c][r])
			{
				correctTiles++; // increment number of correct tiles
			}
		}
	}

	//if the there are 16 correct tiles
	if (correctTiles == 16)
	{
		win = true; //set the win = true
		//removing event listener
		_eventDispatcher->removeAllEventListeners();

		Director::getInstance()->replaceScene(
			TransitionFlipY::create(2, WinScene::createScene()));
	}
}