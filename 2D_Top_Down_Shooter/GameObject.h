

#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

// All game objects will inherit from this class
// which will allow managing objects much easier


class GameObject
{


public:

	GameObject();
	~GameObject();

private:

	sf::Vector2f Position;

};