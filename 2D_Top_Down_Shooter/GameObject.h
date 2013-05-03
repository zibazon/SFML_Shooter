

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
	GameObject(sf::Vector2f Position, std::string & TextureName, sf::IntRect TextureArea);
	~GameObject();

	void Draw(sf::RenderWindow * RenderWindow);

	void SetPosition(sf::Vector2f Position);
	sf::Vector2f GetPosition();

	bool SetTexture(std::string & TextureName, sf::IntRect TextureArea);


protected:

	sf::Texture * Texture;
	sf::Sprite * Sprite;

};