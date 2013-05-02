
#include "Windows.h"

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Menu.h"


Menu::Menu(const std::string & Title, const std::string & Font, sf::RenderWindow * RenderWindow)
{
	//Initialize font pointer
	this->Font = new sf::Font;

	//Load up the font
	this->Font->loadFromFile(Font);

	//Menu title duh
	this->MenuTitle = new sf::Text(Title, *this->Font); 

	//Copy the pointer loacally for drawing
	this->RenderWindow = RenderWindow; 

	//Allocate List of Items up to MAX_ITEMS
	this->Items = new Item*[MAX_ITEMS];

	//There are 0 items in the list!
	ItemCount = 0;

	//Setup the menu options
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

void Menu::AddMenuItem(const std::string & Text, ItemTypes Type)
{
	this->Items[ItemCount] = new Item;					//Init
	this->Items[ItemCount]->Type = Type;				//Set Type
	this->Items[ItemCount]->Text = new sf::Text( Text, *this->Font );	//Set Text/Font;

	ItemCount++;	//Increment the item count to keep track
}


void Menu::DrawMenu()
{
	//Draw the title

	this->MenuTitle->setPosition(180, 80); //Set the position
	this->MenuTitle->setCharacterSize(60);

	this->RenderWindow->draw(*this->MenuTitle); //Draw the menu title

	this->SelectedItem = -1;

	for(int CurrentItem = 0; CurrentItem < this->ItemCount; CurrentItem++)
	{

		this->Items[CurrentItem]->Text->setCharacterSize(40);

		//switch through types and set specific color

		switch(this->Items[CurrentItem]->Type)
		{
		case ItemTypes::STATIC_TEXT:
			this->Items[CurrentItem]->Text->setColor(sf::Color(150, 150, 150)); //Gray
			break;

		case ItemTypes::OPTION:
			this->Items[CurrentItem]->Text->setColor(sf::Color::White);
			break;

		case ItemTypes::FOLDER:
			this->Items[CurrentItem]->Text->setColor(sf::Color::Blue);
			break;

		default:
			break;

		}

		//Check colision on text object at some point

		this->Items[CurrentItem]->Text->setPosition(100, 350 + (CurrentItem * 50));
		

		if(this->Items[CurrentItem]->Text->getGlobalBounds().contains( sf::Vector2f(sf::Mouse::getPosition(*this->RenderWindow)) ) )
		{
			this->SelectedItem = CurrentItem;
			this->Items[CurrentItem]->Text->setPosition(110, 350 + (CurrentItem * 50));

			//Maybe we can play a sound too!

		}
	
		this->RenderWindow->draw( *this->Items[CurrentItem]->Text );

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
Menu_Main::Menu_Main(const std::string & Title, const std::string & Font, sf::RenderWindow * RenderWindow) : Menu(Title, Font, RenderWindow)
{

	//Initialize font pointer
	this->Font = new sf::Font;

	//Load up the font
	this->Font->loadFromFile(Font);

	//Menu title duh
	this->MenuTitle = new sf::Text(Title, *this->Font); 

	//Copy the pointer loacally for drawing
	this->RenderWindow = RenderWindow; 

	//Allocate List of Items up to MAX_ITEMS
	this->Items = new Item*[MAX_ITEMS];

	ItemCount = 0;

	this->MenuSetup();

}

void Menu_Main::MenuSetup()
{
	this->AddMenuItem("Start Game", ItemTypes::OPTION);
	this->AddMenuItem("Options", ItemTypes::OPTION);
	this->AddMenuItem("Quit", ItemTypes::OPTION);
}

int Menu_Main::MenuController()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return this->SelectedItem;
	}

	return -1;
}