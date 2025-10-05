/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cUserInterface.h
 Description :   Declares the cUserInterface Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cTileMap.h"

class cUserInterface {
private:
	cTileMap* m_TileMap;
	sf::Sprite m_UISprite;
	sf::Vector2f m_UIPosition;

public:
	cUserInterface(cTileMap* _tileMap);
	~cUserInterface();

	// Getters
	const sf::Sprite& GetUISprite() const; // Returns the Sprite of the User Interface

	// Setters
	void SetUISprite(unsigned int _x, unsigned int _y); // Sets the UI Sprite given X and Y of Tile Map
	void SetUISprite(unsigned int _n); // Sets the UI Sprite given the n'th Tile in the Tile Map
	void SetUIPosition(sf::Vector2f _position); // Sets the Position
	void SetUIOpacity(unsigned int _alpha); // Sets the Opacity of the User Interface
};

