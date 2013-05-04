
#pragma once

#include <Windows.h>

#include <SFML\Graphics.hpp>

#include "Tile.h"
#include "ImageManager.h"

class Level
{

public:
	Level(int Width, int Height, int TileSize);
	~Level();
	
	void addTile(int x, int y, Tile * tile);
	Tile * getTile(int x, int y);

	int LoadLevel(std::string & TileSet, std::string & FileName);

	int getWidth();
	int getHeight();

private:

	//Map Dimensions

	int Width;
	int Height;

	int TileSize;

	std::vector<std::vector<Tile*>> Map;

	void setDimensions(int Width, int Height);

	ImageManager * TileSet;

};