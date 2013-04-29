#include <Windows.h>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>





//This is the main Class, it handles all "Globals"
//GameState, window messages rendering and manages all subsequent classes



class Game {

public:

	//Construct, Create the window, start rendering, initiate the game/menus etc.
	Game();

	//Deconstruct, Game Exit
	~Game();

	
private:
	int GameState; //What menu are we in? What should be rendered/not rendered

	sf::RenderWindow * MainWindow; //Our main render window
	

};

