

#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Level.h"

class Engine
{

public:

	Engine(sf::RenderWindow * RenderWindow, sf::Vector2i TileSize);
	~Engine();


	void DrawTiles();
	void Update();


private:

	sf::View * Camera;

	sf::RenderWindow * RenderWindow;

	sf::Image * TileImageSet;

	sf::Vector2i TileSize;

};