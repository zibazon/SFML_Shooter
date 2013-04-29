
#include "Main.h"


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{


	Game::Init();


	while (Game::MainWindow->isOpen())
    {
        sf::Event event;
        while (Game::MainWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Game::MainWindow->close();
        }

        Game::MainWindow->clear();

        Game::MainWindow->display();
    }



    return 0;
}