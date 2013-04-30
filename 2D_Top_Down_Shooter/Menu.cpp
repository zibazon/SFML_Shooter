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

void Menu::AddMenuItem(char * Text, Types ItemType)
{
	this->Items[ItemCount] = new Item;					//Init
	this->Items[ItemCount]->ItemType = Types::STATIC_TEXT;	//Set Type
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

		//Ignoring Types for now, just drawing text

		//TODO!
		//Learn how to use sfml and draw colored text....

		Text.setString(sf::String(this->Items[CurrentItem]->Text));
		Text.setPosition(100, 350 + (CurrentItem * 50));
	
		this->RenderWindow->draw( Text );

	}
}


