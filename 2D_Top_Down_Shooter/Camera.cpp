

#include "Camera.h"


Camera::Camera(sf::Vector2f CenterCoords, sf::RenderWindow * RenderWindow)
{
	this->RenderWindow = RenderWindow;

	//Setup the camera CHANGE THIS
	this->CameraView = new sf::View( 
		CenterCoords, /* This will be the coords of object that the view will center around */
		sf::Vector2f(this->RenderWindow->getSize()));
}

Camera::~Camera()
{
	delete this->CameraView;
}

void Camera::Activate()
{
	//Activate the camera view
	this->RenderWindow->setView(*this->CameraView);
}

sf::View * Camera::getView()
{
	return this->CameraView;
}

void Camera::Pan(sf::Vector2f Coords)
{
	//TODO
}

void Camera::Move(sf::Vector2f Coords)
{
	this->CameraView->setCenter(Coords);
}

sf::Vector2f Camera::getCenter()
{

	//not right....
	return sf::Vector2f(this->CameraView->getCenter().x, this->CameraView->getCenter().y);
}


sf::IntRect Camera::getTileBounds(int tileSize)
{
	int x = (int)((this->CameraView->getCenter().x - (this->CameraView->getSize().x / 2)) / tileSize);
	int y = (int)((this->CameraView->getCenter().y - (this->CameraView->getSize().y / 2)) / tileSize);

	//+1 in case camera size isn't divisible by tileSize
	//And +1 again because these values start at 0, and
	//we want them to start at one
	int w = (int)(this->CameraView->getSize().x / tileSize + 2);
	int h = (int)(this->CameraView->getSize().y / tileSize + 2);

	//And +1 again if we're offset from the tile
	if(x % tileSize != 0)
		w++;
	if(y % tileSize != 0)
		h++;

	return sf::IntRect(x, y, w, h);
}
