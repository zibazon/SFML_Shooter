
#pragma once


#define MAX_ITEMS 32		//Self explanitory


enum Types					//Menu item Types
{
	STATIC_TEXT,			//Unclickable text
	OPTION,					//Clickable item
	FOLDER					//Folder that contains other items
};


struct Item
{
	Types Type;				//Item Type
	sf::Text * Text;		//Item Text
};



class Menu
{

public:

	Menu(const std::string & Title, const std::string & Font, sf::RenderWindow * RenderWindow);					//Initialize the font and all variables
	~Menu();

	void AddMenuItem(const std::string & Text, Types Type);

	void DrawMenu();

	void MenuSetup();
	void MenuController();


protected:

	sf::Text * MenuTitle;

	int ItemCount;
	
	Item ** Items;			//Our list of items

	sf::Font * Font;		//Display Font
	sf::RenderWindow * RenderWindow; //Copy of our main rendering window

};


class Menu_Main : public Menu
{

public:

	Menu_Main(const std::string & Title, const std::string & Font, sf::RenderWindow * RenderWindow);	//Initialize the font and all variables


	void MenuSetup();
	void MenuController();


};