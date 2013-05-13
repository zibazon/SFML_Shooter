




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
	this->MouseSpriteID = 0;
	this->DrawCalls = 0;

	this->DebugText = new sf::Text;

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

	this->DebugText->setCharacterSize(12);
	this->DebugText->setFont(*this->Font);
	this->DebugText->setColor(sf::Color::White);

	this->CameraView->Activate();

	this->KeyPressDelay[0] = this->KeyPressDelay[1] = GetTickCount();

	this->isInit = true;

}

//All of the rendering is done in this function
//Do not Draw from anywhere else!
void Engine::Render()
{
	this->DrawCalls = 0;
	FPSCounter->Count();

	//Change the view back to the game camera view
	this->CameraView->Activate();

	/*sf::VertexArray Line(sf::Lines, 2);

	Line[0].color = sf::Color(200, 200, 200, 255);
	Line[1].color = sf::Color(200, 200, 200, 255);*/

	sf::Sprite curSprite;

	int numOfImages = this->CurrentLevel->getImageManager()->getImagesCount();

	int tSize = this->CurrentLevel->getTileSize(); //Store out tile size for quick reference

	sf::IntRect tileBounds = this->CameraView->getTileBounds(this->CurrentLevel->getTileSize());

	sf::Vector2f MousePos = this->RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->RenderWindow));


	for(int x = 0, TileX = tileBounds.left; x <= tileBounds.width; x++, TileX++) //Width
	{
		for(int y = 0, TileY = tileBounds.top; y <= tileBounds.height; y++, TileY++) //Height
		{

			Tile * curTile = this->CurrentLevel->getTile(TileX, TileY);

			if(curTile != NULL)
			{
				if(curTile->getSpriteID() < this->CurrentLevel->getImageManager()->getImagesCount()) 
				{
					curSprite.setTexture(*this->CurrentLevel->getImageManager()->GetTexture(curTile->getSpriteID())); //Works here no problemo
				
					curSprite.setPosition(curTile->getPosition());

					//Why should we draw if there is no texture?
					if(curSprite.getTexture() != NULL)
					{
						this->RenderWindow->draw(curSprite);
						this->DrawCalls++;
					}
				}
			}


		}
	}


	if(this->isEditing)
	{
		//Draw our editing tile on mouse position

		if(this->MouseSpriteID < numOfImages)
		{
			curSprite.setTexture(*this->CurrentLevel->getImageManager()->GetTexture(this->MouseSpriteID));
					
			curSprite.setPosition(sf::Vector2f(MousePos.x - (tSize/2), MousePos.y - (tSize/2)));

			if(curSprite.getTexture() != NULL)
			{
				this->RenderWindow->draw(curSprite);
				this->DrawCalls++;
			}
		}

		this->DebugOutput();
	}

	this->RenderWindow->setView(this->RenderWindow->getDefaultView());

	this->DebugText->setPosition(10, 10);
	this->DebugText->setString(std::string("FPS: ") + NumberToString(FPSCounter->GetCount()) +  std::string("   Draw Calls: ") + NumberToString(this->DrawCalls));
	this->RenderWindow->draw(*DebugText);


}


void Engine::DebugOutput()
{
	//Change to the default view
	this->RenderWindow->setView(this->RenderWindow->getDefaultView());

	//All debug text will use this variable


	//Mouse coordinates and Current Tile coords
	
	//Change tiles? thats for the editor to do....

	
	//FPS
	//Txt.setString(std::string("FPS: ") + NumberToString(FPSCounter->GetCount()));
	//this->RenderWindow->draw(Txt);

	sf::Vector2f MousePos = this->RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->RenderWindow), *this->CameraView->getView());

	this->DebugText->setPosition(10, 30);
	this->DebugText->setString(std::string("MouseX: ") + NumberToString(MousePos.x) + std::string("\n") + std::string("MouseY: ") + NumberToString(MousePos.y) + std::string("\n"));
	this->RenderWindow->draw(*this->DebugText);

	this->DebugText->setPosition(10, 70);
	this->DebugText->setString(std::string("HoverX: ") + NumberToString(MousePos.x/32) + std::string("\n") + std::string("HoverY: ") + NumberToString(MousePos.y/32) + std::string("\n"));
	this->RenderWindow->draw(*this->DebugText);

	this->DebugText->setPosition(10, 100);
	this->DebugText->setString(std::string("Mouse Wheel ID: ") + NumberToString(this->MouseSpriteID));
	this->RenderWindow->draw(*this->DebugText);

}



void Engine::Update(float deltaTime)
{
	sf::Vector2f MousePos = this->RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->RenderWindow), *this->CameraView->getView());

	//Toggle edit mode
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1) && this->KeyPressDelay[0] < GetTickCount())
	{
		this->isEditing = !this->isEditing;
		this->KeyPressDelay[0] = GetTickCount() + 200;
	}


	

	if(this->isEditing)
	{

		//Save Current Tile Map with the F2 Key
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F2) && this->KeyPressDelay[1] < GetTickCount())
		{
			this->CurrentLevel->SaveLevel();
			this->KeyPressDelay[1] = GetTickCount() + 500;
		}

		//Editing mode!

		//allow dynamic changing of tiles

		//toggle grid

		//view of tileset

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x, this->CameraView->getCenter().y - (10 * deltaTime)) );
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x, this->CameraView->getCenter().y + (10 * deltaTime)) );
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x - (10 * deltaTime), this->CameraView->getCenter().y) );
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->CameraView->Move( sf::Vector2f(this->CameraView->getCenter().x + (10 * deltaTime), this->CameraView->getCenter().y) );
		}


		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Tile * curTile = this->CurrentLevel->getTile(MousePos.x / 32, MousePos.y / 32);

			if(curTile)
			{
				curTile->setSpriteID(this->MouseSpriteID);
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			Tile * curTile = this->CurrentLevel->getTile(MousePos.x / 32, MousePos.y / 32);

			if(curTile)
			{
				this->MouseSpriteID = curTile->getSpriteID();
			}
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

std::string Engine::FloatToString(float Number)
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

void Engine::mouseWheelInc(int Num)
{
	int MaxImages = this->CurrentLevel->getImageManager()->getImagesCount();

	this->MouseSpriteID += Num;

	if(this->MouseSpriteID < 0)
		this->MouseSpriteID = MaxImages;

	if(this->MouseSpriteID > MaxImages)
		this->MouseSpriteID = 0;
}