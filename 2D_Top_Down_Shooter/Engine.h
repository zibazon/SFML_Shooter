

#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Tile.h"
#include "Level.h"
#include "Camera.h"

class Engine
{

public:

	Engine(sf::RenderWindow * RenderWindow, sf::Vector2i TileSize);
	~Engine();


	void DrawTiles();
	void Update();

	void ToggleGrid();


private:

	sf::RenderWindow * RenderWindow;

	sf::Image * TileImageSet;

	sf::Vector2i TileSize;

	Camera * CameraView;

	bool ShowGrid;

};