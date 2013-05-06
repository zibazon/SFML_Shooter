

#include "Level.h"


Level::Level(int Width, int Height, int TileSize)
{
	this->setDimensions(Width, Height);

	this->TileSize = TileSize;

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


	//Check to see if we have a level loaded already and unload it


	//Load Level Layout
	Tile * tile;

	//Open our level settings file
	std::ifstream Settings;
	Settings.open(DataFile, std::ios::in);

	Settings.close();



	//Load Tileset for level
	sf::Image FullSet;

	if(!FullSet.loadFromFile("Images/Level1.png"))
		return 0;
	

	//Split tileset by tilesize for the image manager

	int imgWidth = FullSet.getSize().x;
	int imgHeight = FullSet.getSize().y;

	for(int x = 0; x < imgWidth / this->TileSize; x++)
	{
		for(int y = 0; y < imgHeight / this->TileSize; y++)
		{
			sf::Texture * t = new sf::Texture();

			t->loadFromImage(FullSet, sf::IntRect(x * this->TileSize, y * this->TileSize, this->TileSize, this->TileSize));

			this->TileSet->AddTexture(t);
		}
	}



	for(int y = 0; y < this->Height; y++)
	{
		for(int x = 0; x < Width; x++)
		{

			//How about we actually load the tile map, hmm?
			if(y % 4 == 0)
				tile = new Tile(sf::Vector2f(x * this->TileSize, y * TileSize), 2);
			else
				tile = new Tile(sf::Vector2f(x * this->TileSize, y * TileSize), 3);

			addTile(x, y, tile);
		}
	}
	

	return 1;
}

int Level::getWidth()
{
	return this->Width;
}

int Level::getHeight()
{
	return this->Height;
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