#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Menu.h"



Menu::Menu(char * Title, char * Font, sf::RenderWindow * RenderWindow)
{

	//Menu title duh
	this->MenuTitle = Title; 

	//Initialize font pointer
	this->Font = new sf::Font;

	//Load up the font
	this->Font->loadFromFile(Font);

	//Copy the pointer loacally for drawing
	this->RenderWindow = RenderWindow; 

	//Allocate List of Items up to MAX_ITEMS
	this->Items = new Item*[MAX_ITEMS];

	ItemCount = 0;

	this->MenuSetup();

}


Menu::~Menu()
{
	//RELEASE 

	delete this->MenuTitle;
	delete this->Font;

	for(int n = 0; n < MAX_ITEMS; n++)
		delete this->Items[n];

	delete this->Items;

	//ALL THE THINGS
}

void Menu::AddMenuItem(char * Text, Types Type)
{
	this->Items[ItemCount] = new Item;					//Init
	this->Items[ItemCount]->Type = Type;	//Set Type
	this->Items[ItemCount]->Text = Text;				//Set Text;

	ItemCount++;	//Increment the item count to keep track
}


void Menu::DrawMenu()
{
	//Draw the title

	sf::Text Text; //This will be the text object we use to draw all of our menus text
	Text.setFont(*this->Font); //Set the font

	Text.setPosition(180, 80); //Set the position
	Text.setCharacterSize(60);

	Text.setString(sf::String(this->MenuTitle));

	this->RenderWindow->draw(Text); //Draw the menu title


	Text.setCharacterSize(40);

	for(int CurrentItem = 0; CurrentItem < this->ItemCount; CurrentItem++)
	{

		//switch through types and set specific color

		switch(this->Items[CurrentItem]->Type)
		{
		case Types::STATIC_TEXT:
			Text.setColor(sf::Color(150, 150, 150)); //Gray
			break;

		case Types::OPTION:
			Text.setColor(sf::Color::White);
			break;

		case Types::FOLDER:
			Text.setColor(sf::Color::Blue);
			break;

		default:
			break;

		}

		//Check colision on text object at some point

		Text.setString(sf::String(this->Items[CurrentItem]->Text));
		Text.setPosition(100, 350 + (CurrentItem * 50));

		if(Text.getGlobalBounds().contains( sf::Vector2f(sf::Mouse::getPosition(*this->RenderWindow)) ) )
		{
			Text.setPosition(150, 350 + (CurrentItem * 50));

			Text.setColor(sf::Color::Blue);

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				
				
			}
		}
	
		this->RenderWindow->draw( Text );

	}
}


void Menu::MenuSetup()
{
	//Overwrite this method
}

void Menu::MenuController()
{
	//Overwrite this method
}




//MainMenu Inherits From Menu
Menu_Main::Menu_Main(char * Title, char * Font, sf::RenderWindow * RenderWindow) : Menu(Title, Font, RenderWindow)
{

	//Menu title duh
	this->MenuTitle = Title; 

	//Initialize font pointer
	this->Font = new sf::Font;

	//Load up the font
	this->Font->loadFromFile(Font);

	//Copy the pointer loacally for drawing
	this->RenderWindow = RenderWindow; 

	//Allocate List of Items up to MAX_ITEMS
	this->Items = new Item*[MAX_ITEMS];

	ItemCount = 0;

	this->MenuSetup();

}

void Menu_Main::MenuSetup()
{
	this->AddMenuItem("Start Game", Types::STATIC_TEXT);
	this->AddMenuItem("Options", Types::OPTION);
	this->AddMenuItem("Quit", Types::STATIC_TEXT);
}

void Menu_Main::MenuController()
{


}