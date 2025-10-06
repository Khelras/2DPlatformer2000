/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cMovingPlatform.cpp
 Description :   Defines the cMovingPlatform Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cMovingPlatform.h"
#include "cPlayer.h"

float cMovingPlatform::EaseInOutSine(float _start, float _end, float _alpha) {
	// Formula was taken from https://easings.net/
	float fEase = -0.5f * (std::cosf(static_cast<float>(M_PI) * _alpha) - 1.0f); // Ease Value
	return _start + ((_end - _start) * fEase); // Lerp Result
}

float cMovingPlatform::EaseInOutCubic(float _start, float _end, float _alpha) {
	// Formula was taken from https://easings.net/
	float fEase = 0.0f;

	// Determining the Ease Value
	if (_alpha < 0.5f) { // Before Halfway Point
		float fCubed = _alpha * _alpha * _alpha;
		fEase = 4.0f * fCubed;
	}
	else { // After Halfway Point
		float fCubeValue = ((-2.0f) * _alpha) + 2.0f;
		float fCubed = fCubeValue * fCubeValue * fCubeValue;
		fEase = 1.0f - (fCubed / 2.0f);
	}

	// Lerp Result
	return _start + ((_end - _start) * fEase);
}

cMovingPlatform::cMovingPlatform() : cActor(ActorType::SOLID_THROUGH_MOVING) {
	this->m_MoveSpeed = 16.0f; // Default to 16.0 Move Speed
	this->m_IsMovingLeft = false; // Default to Right
	this->m_TimeAccumulator = 0.0f; // Start at 0.0f
}

cMovingPlatform::~cMovingPlatform() {
}

void cMovingPlatform::UpdateActor(float _deltaTime, std::vector<cActor*> _actors) {
	// Add Delta Time to the Time Accumulator
	this->m_TimeAccumulator += _deltaTime;

	// Calculating the Alpha value for the Lerp
	float fAlpha = this->m_TimeAccumulator / this->m_Duration;

	// End of Alpha
	if (fAlpha >= 1.0f) { // Reached the End
		// Reset Time Accumulator
		this->m_TimeAccumulator = 0.0f;

		// Update Alpha depending if going Left or Right
		fAlpha = (this->m_IsMovingLeft) ? 0.0f : 1.0f;

		// Update Movement Direction (Flip)
		this->m_IsMovingLeft = (this->m_IsMovingLeft) ? false : true;
	}
	else {
		// Update Alpha depending if going Left or Right
		fAlpha = (this->m_IsMovingLeft) ? (1.0f - fAlpha) : fAlpha;
	}

	// Lerp Value
	float fLerpX = this->EaseInOutCubic(this->m_StartPosition.x, this->m_EndPosition.x, fAlpha);
	
	// Bounds on top of Platform to check for Player
	sf::FloatRect OnPlatformBounds = this->m_ActorSprite.getGlobalBounds(); // Bounds on top of Moving Platform
	OnPlatformBounds.position.y--; // Shift bounds Upwards by 1px
	
	// Move the Player if they are on the Moving Platform
	cActor* CollisionActor = this->CheckCollision(OnPlatformBounds, _actors); // Collision Actor
	if (CollisionActor != nullptr) {
		// Double check that the Collision Actor is a Player
		if (CollisionActor->GetActorType() == ActorType::PLAYER) {
			// Dynamic Cast to cActor to cPlayer
			cPlayer* Player = dynamic_cast<cPlayer*>(CollisionActor);
			
			// Only Move the Player if they have not been moved by a connected Moving Platform tile
			if (Player->GetPlayerMovedByPlatform() == false) {
				// Set Played Moved By Platform
				Player->SetPlayerMovedByPlatform(true);

				// Only Move the Player if they are standing on the Moving Platform
				if (CollisionActor->GetActorVelocity().y == 0) {
					// Move offset based on the direction of the Moving Platform
					float fOffset = fLerpX - this->m_ActorPosition.x;

					// Move the Player
					sf::Vector2f PlayerPosition = CollisionActor->GetActorPosition();
					PlayerPosition.x += fOffset; // Applying Movement Offset
					Player->SetActorPosition(PlayerPosition);
				}
			}
			
		}
	}

	// Lerp the x-axis Position of the Moving Platform
	this->m_ActorPosition.x = fLerpX;

	// Set Sprite Position
	this->m_ActorSprite.setPosition(this->m_ActorPosition);
}

void cMovingPlatform::MoveX(float _deltaTime, std::vector<cActor*> _actors) {
	// Do Nothing
}

void cMovingPlatform::MoveY(float _deltaTime, std::vector<cActor*> _actors) {
	// Do Nothing
}

cActor* cMovingPlatform::CheckCollision(sf::FloatRect _bounds, std::vector<cActor*> _actors) {
	// Loop through all Actors
	for (cActor* Actor : _actors) {
		// Skip Actors that is NOT a Player
		if (Actor->GetActorType() != ActorType::PLAYER) continue;

		// If Actor is Player
		if (Actor->GetActorType() == ActorType::PLAYER) {
			// Dynamic Cast cActor to cPlayer
			cPlayer* Player = dynamic_cast<cPlayer*>(Actor);

			// Use Player Bounds to check for a Collision
			if (_bounds.findIntersection(Player->GetPlayerBounds())) {
				// Return the Actor
				return Actor;
			}

			// Otherwise, Keep Looping
			continue;
		}
	}

	// Returns nullptr otherwise (No Collision found)
	return nullptr;
}

void cMovingPlatform::SetActorPosition(sf::Vector2f _position) {
	// Calls the SetActorPosition() Function from the cActor Base Class
	cActor::SetActorPosition(_position);

	// Extend Functionality
	// Set the Start and End Positions
	this->m_StartPosition = _position;
	this->m_StartPosition.x -= m_InitialOffset;
	this->m_EndPosition = _position;
	this->m_EndPosition.x += m_InitialOffset;

	// Set the Moving Platform Position to Start Position
	this->m_ActorPosition = this->m_StartPosition;
	this->m_ActorSprite.setPosition(this->m_StartPosition);
}
