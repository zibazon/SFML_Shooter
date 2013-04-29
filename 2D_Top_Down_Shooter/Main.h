#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>




void RenderWindow(sf::RenderWindow * RenderWindow)
{



}




//This is the main namespace, it handles all "Globals"
//GameState, window messages rendering and manages all subsequent classes



namespace Game {


	//Global Variables

	int GameState; //What menu are we in? What should be rendered/not rendered
	sf::RenderWindow * MainWindow; //Our main render window



	//Initialize startup variables, Create the window, start rendering, initiate the game/menus etc.
	void Init()
	{

		//Initialize our render window
		MainWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");

	}


	

	//Store information on screen resolution and other simple settings like that

};

