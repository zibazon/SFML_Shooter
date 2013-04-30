#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Menu.h"
#include "MenuControllers.h" //Contains Predefined Menus


//This is the main namespace, it handles all "Globals"
//GameState, window messages rendering and manages all subsequent classes



namespace Game {

	enum GameStates
	{
		MAIN_MENU,
		IN_GAME,
		PAUSED
	};


	//Global Variables

	GameStates CurGameState; //What menu are we in? What should be rendered/not rendered
	sf::RenderWindow * MainWindow; //Our main render window

	Menu * MainMenu;



	//Initialize startup variables, Create the window, start rendering, initiate the game/menus etc.
	void Init()
	{
		//Create preferred settings loading before opening the window so we get the resolution right

		//Initialize our render window
		MainWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");

		MainMenu = new Menu("Menu Title", "Arial.ttf", MainWindow);
		PredefinedMenus::MainMenuSetup(MainMenu);

	}

	

	//Store information on screen resolution and other simple settings like that

};

