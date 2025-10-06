/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cKey.h
 Description :   Declares the cKey Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cActor.h"

class cKey : public cActor {
private:
	int m_KeyTile; // Tile 97

public:
	cKey(); // Constructor
	~cKey(); // Destructor

	// Key Functions
	sf::FloatRect GetKeyBounds(); // Returns the Custom Bounds of the Key
};

