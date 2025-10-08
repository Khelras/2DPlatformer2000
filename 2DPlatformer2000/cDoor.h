/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cDoor.h
 Description :   Declares the cDoor Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cActor.h"

class cDoor : public cActor {
private:
	int m_DoorTile; // Tile 56

public:
	cDoor(cTileMap* _tileMap); // Constructor
	~cDoor(); // Destructor

	// Door Function
	sf::FloatRect GetDoorBounds(); // Returns the Custom Bounds of the Door
};
