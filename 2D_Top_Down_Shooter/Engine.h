

#pragma once


class TilingEngine
{

public:

	TilingEngine(sf::RenderWindow * RenderWindow);
	~TilingEngine();


	void DrawTiles();


private:

	sf::View * Camera;

	sf::RenderWindow * RenderWindow;

	sf::Image * TileImageSet;

};