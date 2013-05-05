




#include "Engine.h"


Engine::Engine(sf::RenderWindow * RenderWindow, int TileSize)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;

	//Setup camera and viewport
	this->CameraView = new Camera(sf::Vector2f(this->RenderWindow->getSize().x /2 - 100, this->RenderWindow->getSize().y /2 - 100), RenderWindow);

	this->TileSize = TileSize;

	this->CurrentLevel = new Level(30, 15, TileSize);

	this->ShowGrid = false;
	this->isEditing = false;
	this->isInit = false;

}

Engine::~Engine()
{

}

void Engine::Init()
{

	if (this->isInit)
		return;

	this->Font = new sf::Font();
	this->Font->loadFromFile("Arial.ttf");


	this->CameraView->Activate();

	this->KeyPressDelay = GetTickCount();

	this->isInit = true;
}

//All of the rendering is done in this function
//Do not Draw from anywhere else!
void Engine::Render()
{

	sf::VertexArray Line(sf::Lines, 2);

	Line[0].color = sf::Color(200, 200, 200, 255);
	Line[1].color = sf::Color(200, 200, 200, 255);

	for(int x = 0; x <= this->CurrentLevel->getWidth(); x++) //Width
	{
		for(int y = 0; y <= this->CurrentLevel->getHeight(); y++) //Height
		{

			//Doesn't cover the last row!
			Line[0].position = sf::Vector2f(0, y * this->TileSize);

			Line[1].position = sf::Vector2f((this->TileSize * this->CurrentLevel->getWidth()), y * this->TileSize);//End point

			if(this->ShowGrid) this->RenderWindow->draw(Line);


			Line[0].position = sf::Vector2f(x * this->TileSize, 0);

			Line[1].position = sf::Vector2f(x * this->TileSize, (this->TileSize * this->CurrentLevel->getHeight()));//End point

			if(this->ShowGrid) this->RenderWindow->draw(Line);


			//Draw tiles here
			Tile * curTile = this->CurrentLevel->getTile(x,y);

			if(curTile != NULL)
				curTile->Draw(sf::Vector2f(x * this->TileSize, y * this->TileSize), this->RenderWindow);

		}

	}


	if(this->isEditing)
	{
		this->DebugOutput();
	}



}


void Engine::DebugOutput()
{


	//Mouse coordinates
	//Hovering Tile
	//Change tiles? thats for the editor to do....
	//Frames Per Second

	sf::Text Txt;
	Txt.setFont(*this->Font);

	Txt.setString("Hello World");

	Txt.setColor(sf::Color::White);

	Txt.setCharacterSize(12);

	Txt.setPosition(this->CameraView->getPosition());


	this->RenderWindow->draw(Txt);



}



void Engine::Update()
{


	//Toggle edit mode
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && this->KeyPressDelay < GetTickCount())
	{
		this->isEditing = !this->isEditing;
		this->KeyPressDelay = GetTickCount() + 200;
	}


	if(this->isEditing)
	{
		//Editing mode!

		//allow dynamic changing of tiles

		//toggle grid

		//view of tileset

	}else{

		//Normal game play

	}



}

void Engine::ToggleGrid()
{
	this->ShowGrid = !this->ShowGrid;
}

void Engine::SetLevel(std::string & FileName)
{
	this->CurrentLevel->LoadLevel(FileName);
}