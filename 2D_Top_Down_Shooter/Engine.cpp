




#include "Engine.h"


Engine::Engine(sf::RenderWindow * RenderWindow, int TileSize)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;

	//Setup camera and viewport
	this->CameraView = new Camera(sf::Vector2f(this->RenderWindow->getSize().x /2, this->RenderWindow->getSize().y /2), RenderWindow);

	this->TileSize = TileSize;

	this->CurrentLevel = new Level(30, 15, TileSize);

	this->ShowGrid = false;
	this->isEditing = false;

}

Engine::~Engine()
{

}

void Engine::DrawTiles()
{

	sf::VertexArray Line(sf::Lines, 2);

	Line[0].color = sf::Color(140, 140, 140, 255);
	Line[1].color = sf::Color(140, 140, 140, 255);

	for(int x = 0; x < this->CurrentLevel->getWidth(); x++) //Width
	{

		for( int y = 0; y < this->CurrentLevel->getHeight(); y++) //Height
		{

			//Doesn't cover the last row!
			Line[0].position = sf::Vector2f(x * this->TileSize, y * this->TileSize);
			Line[1].position = sf::Vector2f(x, y * this->TileSize);
			if(this->ShowGrid) this->RenderWindow->draw(Line);

			Line[0].position = sf::Vector2f(x * this->TileSize, y);
			Line[1].position = sf::Vector2f(x * this->TileSize, y * this->TileSize);
			if(this->ShowGrid) this->RenderWindow->draw(Line);


			//Draw tiles here
			Tile * curTile = this->CurrentLevel->getTile(x,y);

			if(curTile != NULL)
				curTile->Draw(sf::Vector2f(x * this->TileSize, y * this->TileSize), this->RenderWindow);

		}

	}

}

void Engine::Update()
{

	//Toggle edit mode
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		this->isEditing = !this->isEditing;
	}


	if(this->isEditing)
	{
		//Editing mode!

		//output debug info

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

void Engine::SetLevel(std::string & TileSet, std::string & FileName)
{
	this->CurrentLevel->LoadLevel(TileSet, FileName);
}