




#include "Engine.h"


Engine::Engine(sf::RenderWindow * RenderWindow, sf::Vector2i TileSize)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;

	//Setup camera and viewport
	this->CameraView = new Camera(sf::Vector2f(this->RenderWindow->getSize().x /2, this->RenderWindow->getSize().y /2), RenderWindow);

	this->TileSize = TileSize;

	this->ShowGrid = false;

}

Engine::~Engine()
{

}

void Engine::DrawTiles()
{


	if(this->ShowGrid)
	{

		sf::VertexArray Line(sf::Lines, 2);

		for(int x = 0; x < 20; x++) //Width
		{

			for( int y = 0; y < 5; y++) //Height
			{
				Line[0].position = sf::Vector2f(x * 32, y * 32);
				Line[1].position = sf::Vector2f(x, y * 32);
				this->RenderWindow->draw(Line);

				Line[0].position = sf::Vector2f(x * 32, y);
				Line[1].position = sf::Vector2f(x * 32, y * 32);
				this->RenderWindow->draw(Line);
			}
		}
		

		

	}

	//Draw tiles after the grid or before?


}

void Engine::Update()
{


}

void Engine::ToggleGrid()
{
	this->ShowGrid = !this->ShowGrid;
}