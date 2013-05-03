#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "GameObject.h"



class Tile : public GameObject
{

public:

	Tile(sf::Vector2f Position, std::string & TextureName, sf::IntRect TextureArea);
	~Tile();

	void SetMovementCost(float Cost);
	float GetMovementCost();

private:

	float Cost; //Used for AI path finding

};