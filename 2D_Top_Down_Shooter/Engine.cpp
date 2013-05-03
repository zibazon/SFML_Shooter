




#include "Engine.h"


Engine::Engine(sf::RenderWindow * RenderWindow, sf::Vector2i TileSize)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;

	//Setup camera and viewport
	this->CameraView = new Camera(sf::Vector2f(10, 10), RenderWindow);

	this->TileSize = TileSize;

}

Engine::~Engine()
{

}

void Engine::DrawTiles()
{


}

void Engine::Update()
{


}