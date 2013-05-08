

#include "Level.h"


Level::Level()
{
	this->TileSet = new ImageManager();
}

Level::~Level()
{
	delete this->TileSet;

	//Delete the map blahhh who cares...
}
	
void Level::addTile(int x, int y, Tile * tile)
{
	if(x < Map.capacity())
		if(y < Map[x].capacity())
			Map[x][y] = tile;
}

Tile * Level::getTile(int x, int y)
{
	if(x < Map.capacity())
		if(y < Map[x].capacity())
			return Map[x][y];
		else
			return NULL;
	else
		return NULL;
}

int Level::LoadLevel(std::string & DataFile)
{
	char tmp[256];
	int curTileID;

	//Check to see if we have a level loaded already and unload it


	//Load Level Layout
	Tile * tile;

	//Open our level settings file
	std::ifstream Settings;
	Settings.open(DataFile, std::ios::in);

	//Line 1, Width
	Settings.getline(tmp, 256);
	this->Width = atoi(tmp);
	ZeroMemory(tmp, sizeof(tmp));

	//Line 2, Height
	Settings.getline(tmp, 256);
	this->Height = atoi(tmp);
	ZeroMemory(tmp, sizeof(tmp));

	//Set the level dimensions
	this->setDimensions(Width, Height);

	//Line 3, TileSize
	Settings.getline(tmp, 256);
	this->TileSize = atoi(tmp);
	ZeroMemory(tmp, sizeof(tmp));

	//Line 4, Tile set image file relative location
	Settings.getline(this->tileSetImage, 256);

	//Load Tileset for level
	sf::Image FullSet;

	if(!FullSet.loadFromFile(this->tileSetImage))
		return 0;
	
	//Split tileset by tilesize for the image manager

	int imgWidth = FullSet.getSize().x;
	int imgHeight = FullSet.getSize().y;

	for(int y = 0; y < imgHeight / this->TileSize; y++)
	{
		for(int x = 0; x < imgWidth / this->TileSize; x++)
		{
			sf::Texture * t = new sf::Texture();

			t->loadFromImage(FullSet, sf::IntRect(x * this->TileSize, y * this->TileSize, this->TileSize, this->TileSize));

			this->TileSet->AddTexture(t);
		}
	}



	for(int y = 0; y < this->Height; y++)
	{
		for(int x = 0; x < this->Width; x++)
		{

			//How about we actually load the tile map, hmm?
			/* //Random Generation for testing
			if(y % 4 == 0)
				tile = new Tile(sf::Vector2f(x * this->TileSize, y * TileSize), 2);
			else
				tile = new Tile(sf::Vector2f(x * this->TileSize, y * TileSize), 3);
				*/

			//Load from file
			ZeroMemory(tmp, sizeof(tmp));
			Settings.getline(tmp, 256, ',');
			curTileID = atoi(tmp);


			tile = new Tile(sf::Vector2f(x * this->TileSize, y * this->TileSize), curTileID);


			addTile(x, y, tile);
		}
	}
	
	Settings.close(); //Close our settings file


	return 1;
}

void Level::SaveLevel() 
{
	//Save the current level to the disk



}

int Level::getWidth()
{
	return this->Width;
}

int Level::getHeight()
{
	return this->Height;
}

int Level::getTileSize()
{
	return this->TileSize;
}

void Level::setDimensions(int Width, int Height)
{
	this->Width = Width;
	this->Height = Height;

	Map.resize(Width);


	for(int i = 0; i < Width; i++)
	{
		Map.at(i).resize(Height, 0);
	}

}

ImageManager * Level::getImageManager()
{
	return this->TileSet;
}