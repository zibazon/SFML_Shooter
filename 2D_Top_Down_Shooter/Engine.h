

#pragma once

#include <Windows.h>
#include <sstream>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Tile.h"
#include "Level.h"
#include "Camera.h"
#include "Cycles.h"

class Engine
{

public:

	Engine(sf::RenderWindow * RenderWindow, int TileSize);
	~Engine();

	void Init();

	void Render();
	void Update();

	void DebugOutput(sf::IntRect tb);

	void ToggleGrid();
	void ToggleEditor();

	void SetLevel(std::string & FileName);

	std::string NumberToString(int Number);


private:

	sf::RenderWindow * RenderWindow;

	sf::Image * TileImageSet;

	Cycles * FPSCounter;

	int TileSize;

	Level * CurrentLevel;

	Camera * CameraView;

	sf::Font * Font;

	bool isInit;

	bool ShowGrid;

	bool isEditing;

	DWORD KeyPressDelay;

};