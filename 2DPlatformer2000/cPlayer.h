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
	cAnimation m_MovementAnimation; // Movement Animation

	// Player Attributes
	//int m_Lives; // Player Lives
	//const int m_MaxLives = 3; // Max Player Lives
	//float m_MoveSpeed; // Player Movement Speed
	//float m_JumpHeight; // Player Jump Height
	bool m_HasKey; // Level key
	bool m_HasDied; // Player Died
	bool m_HasCompletedLevel; // Player Completed Level
	bool m_HasDoubleJumped; // Player Double Jump
	bool m_HasPhasedThrough; // Player Phase Through
	bool m_HasMovedByPlatform; // Player Movement with a Moving Platform

public:
	cPlayer(cTileMap* _tileMap); // Constructor
	~cPlayer(); // Destructor

	// Overridden Functions
	void UpdateActor(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors) override;
	void ResetActor() override;
	void MoveX(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors) override;
	void MoveY(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors) override;

	// Player Functions
	bool CheckCollisionSolid(sf::FloatRect _bounds, std::vector<cActor*> _actors); // Check Collisions against Solids Only
	sf::FloatRect GetPlayerBounds(); // Returns the Custom Bounds of Player
	void MovePlayer(MovementDirection _direction, GameSettings& _settings); // Player Movement
	void IdlePlayer(); // Player Idle
	void Jump(GameSettings& _settings); // Player Jump
	
	// Setters
	void SetPlayerDied(bool _died); // Set the Has Player Died
	void SetPlayerCompletedLevel(bool _complete); // Set the Player Completed Level
	void SetPlayerPhaseThrough(bool _phase); // Set the Player Phase Through
	void SetPlayerMovedByPlatform(bool _hasMoved); // Sets the Player Moved By Platform

	// Getters
	const bool HasKey() const; // Returns if Player has Key or not 
	const bool GetPlayerDied() const; // Returns the Has Player Died
	const bool GetPlayerCompletedLevel() const; // Returns the Player Completed Level
	const bool GetPlayerPhaseThrough() const; // Returns the Player Phase Through
	const bool GetPlayerMovedByPlatform() const; // Returns the Player Moved By Platform
};

