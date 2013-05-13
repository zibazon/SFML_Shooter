

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

	Engine(sf::RenderWindow * RenderWindow);
	~Engine();

	void Init();

	void Render();
	void Update(float deltaTime);

	void DebugOutput();

	void ToggleGrid();
	void ToggleEditor();

	void SetLevel(std::string & FileName);

	std::string NumberToString(int Number);
	std::string FloatToString(float Number);

	void mouseWheelInc(int Num);


private:

	sf::RenderWindow * RenderWindow;

	sf::Image * TileImageSet;

	Cycles * FPSCounter;

	Level * CurrentLevel;

	Camera * CameraView;

	sf::Font * Font;

	sf::Text * DebugText;

	bool isInit;

	bool ShowGrid;

	bool isEditing;

	int DrawCalls;

	int MouseSpriteID;

	DWORD KeyPressDelay[3];

};