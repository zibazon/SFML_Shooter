

#include "Tile.h"


Tile::Tile(sf::Vector2f Position, int SpriteID)
{
	this->Position = Position;
	this->SpriteID = SpriteID;
}

Tile::~Tile()
{

}

int Tile::getSpriteID()
{
	return this->SpriteID;
}

void Tile::setSpriteID(int SpriteID)
{
	this->SpriteID = SpriteID;
}

sf::Vector2f Tile::getPosition()
{
	return this->Position;
}

void Tile::setMovementCost(float Cost)
{
	this->Cost = Cost;
}

float Tile::getMovementCost()
{
	return this->Cost;
}