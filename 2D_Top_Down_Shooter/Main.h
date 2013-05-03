
#pragma once

#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Menu.h"
#include "Engine.h"


//This is the main namespace, it handles all "Globals"
//GameState, window messages rendering and manages all subsequent classes



namespace Game
{

	enum GameStates
	{
		MAIN_MENU,
		OPTIONS_MENU,
		IN_GAME,
		PAUSED,
		EXITING
	};

	//Global Variables

	GameStates CurGameState; //What menu are we in? What should be rendered/not rendered

	sf::RenderWindow * MainWindow; //Our main render window

	Menu_Main * MainMenu;

	void UpdateThread();

	void Init()
	{
		//Create preferred settings loading before opening the window so we get the resolution right

		//Initialize our render window
		MainWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");

		MainMenu = new Menu_Main("Menu Title", "Arial.ttf");

		CurGameState = GameStates::MAIN_MENU;

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)UpdateThread, NULL, NULL, NULL);
	}

	


};

