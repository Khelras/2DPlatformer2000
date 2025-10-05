/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cJumpPad.h
 Description :   Declares the cJumpPad Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cActor.h"
#include "cAnimation.h"

class cJumpPad : public cActor {
private:
	// Jump Pad Tiles
	int m_IdleTile; // Tile 163
	int m_ActivationTileStart; // Tile 163 
	int m_ActivationTileEnd; // Tile 165

	// Jump Pad Animation
	cAnimation m_JumpPadAnimation;

	// Jump Pad Attributes
	int m_JumpPadHeight;

public:
	cJumpPad(); // Constructor
	~cJumpPad(); // Destructor
	
	// Overridden Functions
	void UpdateActor(float _deltaTime, std::vector<cActor*> _actors) override; // Override

	// Jump Pad Functions
	sf::FloatRect GetJumpPadBounds(); // Return the Size of the the Jump Pad
	void PlayJumpPadAnimation(); // Plays the Jump Pad Animation
	int GetJumpPadHeight(); // Returns the Height at which the Jump Pad launches
};