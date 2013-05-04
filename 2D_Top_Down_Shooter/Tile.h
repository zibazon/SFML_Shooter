#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "GameObject.h"



class Tile : public GameObject
{

public:

	Tile(sf::Vector2f Position, sf::Texture * Texture);
	~Tile();

	void Draw(sf::Vector2f Position, sf::RenderWindow * RenderWindow);

	void SetMovementCost(float Cost);
	float GetMovementCost();


private:

	float Cost; //Used for AI path finding

};