

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Tile.h"
#include "Engine.h"


TilingEngine::TilingEngine(sf::RenderWindow * RenderWindow)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;

}

TilingEngine::~TilingEngine()
{

}