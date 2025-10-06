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
	//int m_JumpPadHeight;

public:
	cJumpPad(); // Constructor
	~cJumpPad(); // Destructor
	
	// Overridden Functions
	void UpdateActor(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors) override; // Override

	// Jump Pad Functions
	sf::FloatRect GetJumpPadBounds(); // Returns the Custom Bounds of the Jump Pad
	void PlayJumpPadAnimation(); // Plays the Jump Pad Animation
};