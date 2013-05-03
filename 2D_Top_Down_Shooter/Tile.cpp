

#include "Tile.h"


Tile::Tile(sf::Vector2f Position, std::string & TextureName, sf::IntRect TextureArea) : GameObject(Position, TextureName, TextureArea)
{
	this->Texture = new sf::Texture();
	this->Texture->loadFromFile(TextureName, TextureArea);

	this->Sprite = new sf::Sprite(*this->Texture);

	this->Sprite->setPosition(Position);
}


Tile::~Tile()
{
	delete this->Sprite;
	delete this->Texture;
}

void Tile::SetMovementCost(float Cost)
{
	this->Cost = Cost;
}

float Tile::GetMovementCost()
{
	return this->Cost;
}