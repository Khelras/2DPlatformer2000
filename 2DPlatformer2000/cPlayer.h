/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cPlayer.h
 Description :   Declares the cPlayer Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cActor.h"
#include "cAnimation.h"

enum class MovementDirection {
	LEFT,
	RIGHT
};

class cPlayer : public cActor {
private:
	// Player Tiles
	int m_IdleTile; // Tile 260
	int m_JumpTile; // Tile 265
	int m_MovementTileStart; // Tile 261
	int m_MovementTileEnd; // Tile 264

	// Animations
	cAnimation m_MovementAnimation;

	// Player Attributes
	int m_Lives; // Player Lives
	const int m_MaxLives = 3; // Max Player Lives
	float m_MoveSpeed; // Player Movement Speed
	float m_JumpHeight; // Player Jump Height
	bool m_HasDoubleJumped; // Player Double Jump
	bool m_HasPhasedThrough; // Player Phase Through
	bool m_HasMovedByPlatform; // Player Movement with a Moving Platform

public:
	cPlayer(); // Constructor
	~cPlayer(); // Destructor

	// Overridden Functions
	void UpdateActor(float _deltaTime, std::vector<cActor*> _actors) override;
	void MoveX(float _deltaTime, std::vector<cActor*> _actors) override;
	void MoveY(float _deltaTime, std::vector<cActor*> _actors) override;

	// Player Functions
	sf::FloatRect GetPlayerBounds(); // Returns the Customer Bounds of Player
	void MovePlayer(MovementDirection _direction); // Player Movement
	void IdlePlayer(); // Player Idle
	void Jump(); // Player Jump
	
	// Setters
	void SetPlayerPhaseThrough(bool _phase); // Set the Player Phase Through
	void SetPlayerLives(int _lives); // Set the Lives of the Player
	void SetPlayerMovedByPlatform(bool _hasMoved); // Sets the Player Moved By Platform

	// Getters
	const bool GetPlayerPhaseThrough() const; // Return the Player Phase Through
	const int GetPlayerLives() const; // Returns the Lives of the Player
	const int GetPlayerMaxLives() const; // Returns the Max Lives of the Player
	const bool GetPlayerMovedByPlatform() const; // Returns the Player Moved By Platform
};

