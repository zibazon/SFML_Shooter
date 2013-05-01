
#include "Main.h"


void ObjectUpdateThread()
{
	sf::Clock Ticks;
	sf::Time TickTime;

	while(true)
	{
		Ticks.restart();


		//Menu controller if were in the main menu

		if(Game::CurGameState == Game::GameStates::MAIN_MENU)
		{

			Game::MainMenu->MenuController();

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

		if(Game::CurGameState == Game::GameStates::MAIN_MENU)
		{

			//Draw to the window buffer here
			Game::MainMenu->DrawMenu();

		}


        Game::MainWindow->display();	//Draw the buffer to the screen
    }



    return 0;
}