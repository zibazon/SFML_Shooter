
#pragma once

#include <vector>

#include <SFML\Graphics.hpp>

class ImageManager
{

public:
	ImageManager();
	~ImageManager();

	void AddTexture(sf::Texture * Texture);
	sf::Texture * GetTexture(int Index);

private:

	std::vector<sf::Texture*> Images;

};