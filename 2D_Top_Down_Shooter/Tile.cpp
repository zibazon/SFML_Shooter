

#include "Tile.h"


Tile::Tile(sf::Vector2f Position) : GameObject(Position)
{
	this->Sprite = new sf::Sprite();
	this->Sprite->setPosition(Position);
}


Tile::~Tile()
{
	delete this->Sprite;
}

void Tile::Draw(sf::Vector2f Position, sf::RenderWindow * RenderWindow)
{
	this->Sprite->setPosition(Position);
	RenderWindow->draw(*this->Sprite);
}

void Tile::SetMovementCost(float Cost)
{
	this->Cost = Cost;
}

float Tile::GetMovementCost()
{
	return this->Cost;
}