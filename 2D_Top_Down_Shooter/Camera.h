

#pragma once

#include <Windows.h>

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class Camera
{

public:

	Camera(sf::Vector2f CenterCoords, sf::RenderWindow * RenderWindow);
	~Camera();

	//Scroll center view to coordinates
	void Pan(sf::Vector2f Coords);

	//Center view immediatly on coordinates
	void Move(sf::Vector2f Coords);

	//Updates the camera position
	void Update();

private:

	sf::View * CameraView;

	sf::RenderWindow * RenderWindow;

};