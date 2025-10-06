/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cSpike.h
 Description :   Declares the cSpike Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cActor.h"

class cSpike : public cActor {
private:
	int m_SpikeTile; // Tile 183

public:
	cSpike(); // Constructor
	~cSpike(); // Destructor
	
	// Spike Functions
	sf::FloatRect GetSpikeBounds() const; // Returns the Custom Bounds of the Spike
};