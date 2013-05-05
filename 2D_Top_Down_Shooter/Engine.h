

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

	Engine(sf::RenderWindow * RenderWindow, int TileSize);
	~Engine();

	void Init();

	void Render();
	void Update();

	void DebugOutput();

	void ToggleGrid();
	void ToggleEditor();

	void SetLevel(std::string & FileName);


private:

	sf::RenderWindow * RenderWindow;

	sf::Image * TileImageSet;

	int TileSize;

	Level * CurrentLevel;

	Camera * CameraView;

	sf::Font * Font;

	bool isInit;

	bool ShowGrid;

	bool isEditing;

	DWORD KeyPressDelay;

};