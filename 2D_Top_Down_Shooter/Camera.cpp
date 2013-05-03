

#include "Camera.h"


Camera::Camera()
{
		//Setup the camera CHANGE THIS
	this->CameraView = new sf::View( 
		sf::Vector2f(10, 10), /* This will be the coords of object that the view will center around */
		sf::Vector2f(this->RenderWindow->getSize()));


	//Activate the camera view
	this->RenderWindow->setView(*this->CameraView);

}

Camera::~Camera()
{


}