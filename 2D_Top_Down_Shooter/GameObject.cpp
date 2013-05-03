
#include "GameObject.h"


GameObject::GameObject(sf::Vector2f Position)
{
	this->Sprite = new sf::Sprite();

	this->Sprite->setPosition(Position);
}

GameObject::~GameObject()
{
	delete this->Sprite;
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

void GameObject::SetTexture(sf::Texture & Texture)
{
	this->Sprite->setTexture(Texture);
}