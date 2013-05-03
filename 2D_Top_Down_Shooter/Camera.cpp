

#include "Camera.h"


Camera::Camera(sf::Vector2f CenterCoords, sf::RenderWindow * RenderWindow)
{
	//Setup the camera CHANGE THIS
	this->CameraView = new sf::View( 
		CenterCoords, /* This will be the coords of object that the view will center around */
		sf::Vector2f(this->RenderWindow->getSize()));

	this->RenderWindow = RenderWindow;

	//Activate the camera view
	this->RenderWindow->setView(*this->CameraView);

}

Camera::~Camera()
{
	delete this->CameraView;
}

void Camera::Pan(sf::Vector2f Coords)
{
	//TODO
}


void Camera::Move(sf::Vector2f Coords)
{
	this->CameraView->setCenter(Coords);
}