
#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


#include "Tile.h"

class Level
{

public:
	Level(int Width, int Height);
	~Level();
	
	void AddTile(int x, int y, Tile * tile);
	Tile * GetTile(int x, int y);

	void LoadLevel(std::string & FileName);

	int getWidth();
	int getHeight();

private:

	//Map Dimensions

	int Width;
	int Height;

	std::vector<std::vector<Tile*>> Map;

};