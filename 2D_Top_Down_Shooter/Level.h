
#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>

#include <SFML\Graphics.hpp>

#include "Tile.h"
#include "ImageManager.h"


class Level
{

public:
	Level();
	//Level(std::string &FileName); //Add later
	~Level();
	
	void addTile(int x, int y, Tile * tile);
	Tile * getTile(int x, int y);

	int LoadLevel(std::string & FileName);
	void SaveLevel();

	int getWidth();
	int getHeight();
	int getTileSize();

	ImageManager * getImageManager();

private:

	//Map Dimensions

	int Width;
	int Height;

	int TileSize;

	//Location on disk of tile set image file, relative to game exe file
	char tileSetImage[256];

	std::string levelDataFile;

	std::vector<std::vector<Tile*>> Map;

	void setDimensions(int Width, int Height);

	ImageManager * TileSet;

};