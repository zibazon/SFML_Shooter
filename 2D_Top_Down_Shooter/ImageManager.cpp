
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
	//Prevent walking off the end of the vector
	if(index < this->Images.size() && index >= 0)
		return this->Images[index];
	else
		return NULL;
}

int ImageManager::getImagesCount()
{
	return this->Images.size();
}