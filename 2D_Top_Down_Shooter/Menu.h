

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
	char * Text;				//Item Text
};



class Menu
{

public:

	Menu(char * Title, char * Font, sf::RenderWindow * RenderWindow);					//Initialize the font and all variables
	~Menu();

	void AddMenuItem(char * Text, Types Type);

	void DrawMenu();


private:

	char * MenuTitle;

	int ItemCount;
	
	Item ** Items;			//Our list of items

	sf::Font * Font;		//Display Font
	sf::RenderWindow * RenderWindow; //Copy of our main rendering window

};