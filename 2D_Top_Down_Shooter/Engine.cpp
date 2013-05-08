




#include "Engine.h"


Engine::Engine(sf::RenderWindow * RenderWindow)
{

	//Copy of our render window, maybe we shouldn't be copying? eh who cares...
	this->RenderWindow = RenderWindow;

	//Setup camera and viewport
	this->CameraView = new Camera(sf::Vector2f(this->RenderWindow->getSize().x /2 - 100, this->RenderWindow->getSize().y /2 - 100), RenderWindow);

	this->CurrentLevel = new Level();

	this->FPSCounter = new Cycles();

	this->ShowGrid = false;
	this->isEditing = false;
	this->isInit = false;

}

Engine::~Engine()
{

}

void Engine::Init()
{

	if (this->isInit)
		return;

	this->Font = new sf::Font();
	this->Font->loadFromFile("Arial.ttf");


	this->CameraView->Activate();

	this->KeyPressDelay = GetTickCount();

	this->isInit = true;
}

//All of the rendering is done in this function
//Do not Draw from anywhere else!
void Engine::Render()
{
	
	FPSCounter->Count();

	//Change the view back to the game camera view
	this->CameraView->Activate();

	/*sf::VertexArray Line(sf::Lines, 2);

	Line[0].color = sf::Color(200, 200, 200, 255);
	Line[1].color = sf::Color(200, 200, 200, 255);*/

	sf::Sprite curSprite;

	sf::IntRect tileBounds = this->CameraView->getTileBounds(this->CurrentLevel->getTileSize());

	for(int x = 0, TileX = tileBounds.left; x <= tileBounds.width; x++, TileX++) //Width
	{
		for(int y = 0, TileY = tileBounds.top; y <= tileBounds.height; y++, TileY++) //Height
		{
			/*
			Line[0].position = sf::Vector2f(TileX * this->TileSize, y * this->TileSize);
			Line[1].position = sf::Vector2f((this->TileSize * tileBounds.width), y * this->TileSize);//End point

			if(this->ShowGrid) 
				this->RenderWindow->draw(Line);


			Line[0].position = sf::Vector2f(x * this->TileSize, TileY * this->TileSize);
			Line[1].position = sf::Vector2f(x * this->TileSize, (this->TileSize * tileBounds.height));//End point

			if(this->ShowGrid) 
				this->RenderWindow->draw(Line);*/

			Tile * curTile = this->CurrentLevel->getTile(TileX, TileY);

			if(curTile != NULL)
			{
				curSprite.setTexture(*this->CurrentLevel->getImageManager()->GetTexture(curTile->getSpriteID()));
				curSprite.setPosition(curTile->getPosition());

				//Why should we draw if there is no texture?
				if(curSprite.getTexture() != NULL)
					this->RenderWindow->draw(curSprite);
			}


		}

	}


	if(this->isEditing)
	{
		this->DebugOutput(tileBounds);
	}



}


void Engine::DebugOutput(sf::IntRect tb)
{

	this->RenderWindow->setView(this->RenderWindow->getDefaultView());

	//All debug text will use this variable
	sf::Text Txt;
	Txt.setFont(*this->Font);
	Txt.setColor(sf::Color::White);
	Txt.setCharacterSize(12);
	Txt.setPosition(10, 10);

	//Mouse coordinates
	//Hovering Tile
	//Change tiles? thats for the editor to do....
	//Frames Per Second

	

	Txt.setString(std::string("FPS: ") + NumberToString(FPSCounter->GetCount()));

	


	//Change the view for the GUI
	
	this->RenderWindow->draw(Txt);


	Txt.setPosition(10, 30);
	Txt.setString(std::string("Left: ") + NumberToString(tb.left) + std::string("\n") + std::string("Top: ") + NumberToString(tb.top) + std::string("\n") +
		std::string("Width: ") + NumberToString(tb.width) + std::string("\n") + std::string("Height: ") + NumberToString(tb.height));
	this->RenderWindow->draw(Txt);
}



void Engine::Update()
{


	//Toggle edit mode
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && this->KeyPressDelay < GetTickCount())
	{
		this->isEditing = !this->isEditing;
		this->KeyPressDelay = GetTickCount() + 200;
	}


	if(this->isEditing)
	{
		//Editing mode!

		//allow dynamic changing of tiles

		//toggle grid

		//view of tileset

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x, this->CameraView->getCenter().y - 10) );
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x, this->CameraView->getCenter().y + 10) );
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x - 10, this->CameraView->getCenter().y) );
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x + 10, this->CameraView->getCenter().y) );
		}


	}else{

		//Normal game play

	}



}

void Engine::ToggleGrid()
{
	this->ShowGrid = !this->ShowGrid;
}

void Engine::SetLevel(std::string & FileName)
{
	this->CurrentLevel->LoadLevel(FileName);
}

std::string Engine::NumberToString(int Number)
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}