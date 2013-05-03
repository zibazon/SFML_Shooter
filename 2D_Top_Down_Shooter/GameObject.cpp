
#include "GameObject.h"


GameObject::GameObject(sf::Vector2f Position, std::string & TextureName, sf::IntRect TextureArea)
{
	this->Texture = new sf::Texture();
	this->Texture->loadFromFile(TextureName, TextureArea);

	this->Sprite = new sf::Sprite(*this->Texture);

	this->Sprite->setPosition(Position);
}

GameObject::~GameObject()
{
	delete this->Sprite;
	delete this->Texture;
}

void GameObject::Draw(sf::RenderWindow * RenderWindow)
{
	RenderWindow->draw(*this->Sprite);
}

void GameObject::SetPosition(sf::Vector2f Position)
{
	this->Sprite->setPosition(Position);
}

sf::Vector2f GameObject::GetPosition()
{
	return this->Sprite->getPosition();
}