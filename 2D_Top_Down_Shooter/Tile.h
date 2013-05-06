#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "GameObject.h"



class Tile
{

public:

	Tile(sf::Vector2f Position, int SpriteID);
	~Tile();

	int getSpriteID();
	void setSpriteID(int SpriteID);

	sf::Vector2f getPosition();

	void setMovementCost(float Cost);
	float getMovementCost();


private:

	int SpriteID; //Defines the texture used to draw this tile

	sf::Vector2f Position;
	
	float Cost; //Used for AI path finding

};