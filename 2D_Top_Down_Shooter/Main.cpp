
#include "Main.h"


void Game::UpdateThread()
{
	sf::Clock Ticks;
	sf::Time TickTime;

	while(true)
	{
		Ticks.restart();


		//Menu controller if were in the main menu

		switch(Game::CurGameState)
		{
		case Game::GameStates::MAIN_MENU:

			//Menu Response
			switch(Game::MainMenu->MenuController())
			{
			case 0:
				Game::CurGameState = Game::GameStates::IN_GAME;
				break;

			case 1:
				Game::CurGameState = Game::GameStates::OPTIONS_MENU;
				break;

			case 2:
				Game::CurGameState = Game::GameStates::EXITING;
				break;

			default:
				break;

			}

			break;




			//Are we in game?
		case Game::GameStates::IN_GAME:

			
			//Update the game engine
			Game::GameEngine->Update();

			break;

		}


		
		do{			// We only want 60 updates every second
			TickTime = Ticks.getElapsedTime();
		}while(TickTime.asMilliseconds() < 16.5);

	}

}


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{

	Game::Init(); //Initialize the window

	while(Game::MainWindow->isOpen())
    {
        sf::Event event;
        while (Game::MainWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Game::MainWindow->close();
        }

        Game::MainWindow->clear(sf::Color(130, 130, 130, 255));		//Clear the frame buffer

		switch(Game::CurGameState)
		{
		case Game::GameStates::MAIN_MENU:
				Game::MainMenu->DrawMenu(Game::MainWindow);
			break;

		case Game::GameStates::IN_GAME:

			Game::GameEngine->Init(); //Should only run once though I should do this a different way
			//Draw the tiles

			Game::GameEngine->Render();

			break;

		case Game::GameStates::EXITING:
			return 0;
			break;

		default:
			return 0;
			break;
			
		}


        Game::MainWindow->display();	//Draw the buffer to the screen
    }

    return 0;
}