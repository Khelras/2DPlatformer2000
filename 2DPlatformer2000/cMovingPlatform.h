/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cMovingPlatform.h
 Description :   Declares the cMovingPlatform Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cActor.h"

class cMovingPlatform : public cActor {
private:
	// Movement Attributes
	sf::Vector2f m_StartPosition; // Start Position
	sf::Vector2f m_EndPosition; // End Position
	const float m_InitialOffset = 64.0f; // Start and End Offset from Initial Position
	float m_MoveSpeed; // Platform Movement Speed
	bool m_IsMovingLeft; // If the Platform is moving towards the Left

	// Lerp Attributes
	const float m_Duration = 5.0f; // Total Duration to Move from Start to End
	float m_TimeAccumulator; // Accumulates Delta Time for Elapsed Time

	// Easing In Out Lerp Functions
	float EaseInOutSine(float _start, float _end, float _alpha);
	float EaseInOutCubic(float _start, float _end, float _alpha);

public:
	cMovingPlatform(); // Constructor
	~cMovingPlatform(); // Destructor

	// Overridden Functions
	void UpdateActor(float _deltaTime, std::vector<cActor*> _actors) override; // Update Actor
	void MoveX(float _deltaTime, std::vector<cActor*> _actors) override; // Move X
	void MoveY(float _deltaTime, std::vector<cActor*> _actors) override; // Move Y
	cActor* CheckCollision(sf::FloatRect _bounds, std::vector<cActor*> _actors) override; // Check Collision
	void SetActorPosition(sf::Vector2f _position) override; // Set Actor Position
};

