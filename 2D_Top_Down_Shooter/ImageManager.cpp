
#include "ImageManager.h"


ImageManager::ImageManager()
{

}

ImageManager::~ImageManager()
{

}

void ImageManager::AddTexture(sf::Texture * texture)
{
	this->Images.push_back(texture);
}

sf::Texture * ImageManager::GetTexture(int index)
{
	return this->Images[index];
}