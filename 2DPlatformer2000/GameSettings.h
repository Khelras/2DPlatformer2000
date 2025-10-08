/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   GameSettings.h
 Description :   Holds most of the game settings and is created/owned in the cGameManager class.
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once

struct GameSettings {
private:
	// Default Actor Settings
	const float m_DefaultActorGravity = 60.0f; // Default Actor Gravity
	const float m_DefaultActorSpeedScalar = 10.0f; // Default Actor Speed Scalar

	// Default Player Settings
	const int m_DefaultPlayerLives = 3; // Default Player Lives
	const float m_DefaultPlayerMoveSpeed = 8.0f; // Default Player Movement Speed
	const float m_DefaultPlayerJumpHeight = -21.0f; // Default Player Jump Height
	const bool m_DefaultPlayerInfiniteDoubleJump = false; // Default Player Infinite Double Jump

	// Default Jump Pad Settings
	float m_DefaultJumpPadHeight = -30.0f; // Default Jump Pad Height

public:
	// Actor Settings
	float m_ActorGravity = 60.0f; // Actor Gravity
	float m_ActorSpeedScalar = 10.0f; // Actor Speed Scalar

	// Player Settings
	int m_PlayerLives = 3; // Player Lives
	float m_PlayerMoveSpeed = 8.0f; // Player Movement Speed
	float m_PlayerJumpHeight = -20.0f; // Player Jump Height
	bool m_PlayerInfiniteDoubleJump = false; // Player Infinite Double Jump

	// Jump Pad Settings
	float m_JumpPadHeight = -30.0f; // Jump Pad Height

	// Reset Player Lives
	void ResetPlayerLives() {
		this->m_PlayerLives = this->m_DefaultPlayerLives;
	}

	// Reset Function
	void ResetSettings() {
		// Reset Actor Settings to Default
		this->m_ActorGravity = this->m_DefaultActorGravity;
		this->m_ActorSpeedScalar = this->m_DefaultActorSpeedScalar;

		// Reset Player Settings to Default
		this->m_PlayerLives = m_DefaultPlayerLives;
		this->m_PlayerMoveSpeed = this->m_DefaultPlayerMoveSpeed;
		this->m_PlayerJumpHeight = this->m_DefaultPlayerJumpHeight;
		this->m_PlayerInfiniteDoubleJump = this->m_DefaultPlayerInfiniteDoubleJump;

		// Reset Jump Pad Settings to Default
		this->m_JumpPadHeight = this->m_DefaultJumpPadHeight;
	}
};