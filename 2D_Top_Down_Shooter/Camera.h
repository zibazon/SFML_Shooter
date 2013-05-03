

#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


class Camera
{

public:

	Camera();
	~Camera();



private:

	sf::View * CameraView;

	sf::RenderWindow * RenderWindow;

};