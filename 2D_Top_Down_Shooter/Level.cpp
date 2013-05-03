

#include "Level.h"


Level::Level(int Width, int Height)
{
	this->Width = Width;
	this->Height = Height;

	//Load our first level maybe?
}

Level::~Level()
{

}
	
void Level::AddTile(int x, int y, Tile * tile)
{

}

Tile * Level::GetTile(int x, int y)
{
	return Map[x][y];
}

void Level::LoadLevel(std::string & FileName)
{
	//This will be fun to solve...


}


int Level::getWidth()
{
	return this->Width;
}

int Level::getHeight()
{
	return this->Height;
}