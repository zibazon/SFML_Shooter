




#include "Engine.h"


Engine::Engine(sf::RenderWindow * RenderWindow, sf::Vector2i TileSize)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;


	//Setup the camera CHANGE THIS
	this->Camera = new sf::View( 
		sf::Vector2f(10, 10), /* This will be the coords of object that the view will center around */
		sf::Vector2f(this->RenderWindow->getSize()));


	//Activate the camera view
	this->RenderWindow->setView(*this->Camera);

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