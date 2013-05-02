
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

		case Game::GameStates::IN_GAME:

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

        Game::MainWindow->clear();		//Clear the frame buffer

		switch(Game::CurGameState)
		{
		case Game::GameStates::MAIN_MENU:
				Game::MainMenu->DrawMenu();
			break;

		case Game::GameStates::IN_GAME:

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