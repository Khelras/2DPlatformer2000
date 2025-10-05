/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cActor.h
 Description :   Defines the cActor Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cActor.h"
#include "cPlayer.h"
#include "cJumpPad.h"

cActor::cActor(ActorType _actorType) : m_ActorSprite(m_TileMap.GetTileMapTexture()) {
	this->SetActorType(_actorType);
	this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(0));
}

cActor::~cActor() {

}

void cActor::DrawActor(sf::RenderWindow& _window) {
	_window.draw(this->m_ActorSprite);
}

void cActor::UpdateActor(float _deltaTime, std::vector<cActor*> _actors) {
	// Check if Actor is Dynamic because Static Actors do not move
	if (this->m_IsDynamic == false) return;

	// Apply Gravity
	if (this->m_HasGravity == true && this->m_Velocity.y < 100) {
		// Get the Bounds under Actor
		sf::FloatRect BoundsUnderActor(this->m_ActorSprite.getGlobalBounds()); // Bounds
		BoundsUnderActor.position.y++; // Under Actor

		// Collision Actor
		cActor* CollisionActor = this->CheckCollision(BoundsUnderActor, _actors);

		// Now check if Actor is NOT the ground
		if (CollisionActor == nullptr) {
			this->m_Velocity.y += this->m_Gravity * _deltaTime; // Gravity
		}
	}

	// Apply Acceleration
	this->m_Velocity += this->m_Acceleration * _deltaTime;

	// Apply Movement
	this->MoveX(_deltaTime, _actors);
	this->MoveY(_deltaTime, _actors);

	// Set Sprite Position
	this->m_ActorSprite.setPosition(this->m_ActorPosition);
}

void cActor::MoveX(float _deltaTime, std::vector<cActor*> _actors) {
	// Floating-point Movement amount for x-axis
	float fMoveX = this->m_Velocity.x * this->m_SpeedScalar * _deltaTime;
	
	// Converting to precise-point Movement for x-axis
	this->m_MoveRemainder.x += fMoveX; // First add to MoveRemainder x-axis
	int iMoveX = static_cast<int>(std::round(this->m_MoveRemainder.x)); // Rounds to the nearest Integer
	
	// Process Movement only IF Movement is NOT 0
	if (iMoveX == 0) return;

	// Remove from MoveRemainer x-axis (leaves the decimal behind)
	this->m_MoveRemainder.x -= static_cast<float>(iMoveX);

	// Getting direction of Movement (Positive is RIGHT and Negative is LEFT)
	int iDirectionX = (iMoveX > 0) ? 1 : -1;

	// Now process Movement and check for collisions at EVERY pixel
	int iSafetyLimit = 1000;
	while (iMoveX != 0) {
		// Safety Limit
		iSafetyLimit--;
		if (iSafetyLimit == 0) std::cout << "MoveX Safety-Limit reached!" << std::endl;

		// Simulate Movement using Actor position
		sf::FloatRect SelfBounds(
			// Position of Bounds
			sf::Vector2f(
				this->m_ActorPosition.x + iDirectionX, // Simulate x-axis Movement towards direction
				this->m_ActorPosition.y 
			),
			// Size of Bounds
			this->m_ActorSprite.getGlobalBounds().size
		);

		// Collision Actor
		cActor* CollisionActor = this->CheckCollision(SelfBounds, _actors);

		// There is NO collision
		if (CollisionActor == nullptr) {
			// Proceed with Movement
			this->m_ActorPosition.x += static_cast<float>(iDirectionX);;
			iMoveX -= iDirectionX;
		}
		// There IS a collision
		else if (CollisionActor != nullptr) {
			// Stop Movement
			this->m_Velocity.x = 0.0f; // Stops any Horizontal Movement
			return;
		}
	}
}

void cActor::MoveY(float _deltaTime, std::vector<cActor*> _actors) {
	// Floating-point Movement amount for y-axis
	float fMoveY = this->m_Velocity.y * this->m_SpeedScalar * _deltaTime;
	
	// Converting to precise-point Movement for y-axis
	this->m_MoveRemainder.y += fMoveY; // First add to MoveRemainder y-axis
	int iMoveY = static_cast<int>(std::round(this->m_MoveRemainder.y)); // Rounds down to the nearest Integer

	// Process Movement only IF Movement is NOT 0
	if (iMoveY == 0) return;

	// Remove from MoveRemainer y-axis (leaves the decimal behind)
	this->m_MoveRemainder.y -= static_cast<float>(iMoveY);

	// Getting direction of Movement (Positive is DOWN and Negative is UP)
	int iDirectionY = (iMoveY > 0) ? 1 : -1;

	// Now process Movement every pixel and check for collisions
	int iSafetyLimit = 1000;
	while (iMoveY != 0 && iSafetyLimit > 0) {
		// Safety Limit
		iSafetyLimit--;
		if (iSafetyLimit == 0) std::cout << "MoveY Safety-Limit reached!" << std::endl;

		// Simulate Movement using Actor position
		sf::FloatRect SelfBounds(
			// Position of Bounds
			sf::Vector2f(
				this->m_ActorPosition.x,
				this->m_ActorPosition.y + iDirectionY // Simulate y-axis Movement towards direction
			),
			// Size of Bounds
			this->m_ActorSprite.getGlobalBounds().size
		);

		// Collision Actor
		cActor* CollisionActor = this->CheckCollision(SelfBounds, _actors);

		// There is NO collision
		if (CollisionActor == nullptr) {
			// Proceed with Movement
			this->m_ActorPosition.y += static_cast<float>(iDirectionY);
			iMoveY -= iDirectionY;
		}
		// There IS a collision
		else if (CollisionActor != nullptr) {
			// Stop Falling
			if (iDirectionY > 0) this->m_Velocity.y = 0;
			else this->m_Velocity.y = 0.25f;
			return;
		}
	}
}

cActor* cActor::CheckCollision(sf::FloatRect _bounds, std::vector<cActor*> _actors) {
	// Loop through all Actors
	for (cActor* Actor : _actors) {
		// Skip Self as well as Actors with no Collision
		if (Actor == this || Actor->m_CollisionType == CollisionType::NONE) continue;

		// If Actor is Player
		if (Actor->m_ActorType == ActorType::PLAYER) {
			// Dynamic Cast cActor to cPlayer
			cPlayer* Player = dynamic_cast<cPlayer*>(Actor);

			// Use Player Bounds
			if (_bounds.findIntersection(Player->GetPlayerBounds())) {
				// Return the Actor
				return Actor;
			}

			continue;
		}

		// If Actor is Jump Pad
		if (Actor->m_ActorType == ActorType::JUMP_PAD) {
			// Dynamic Cast cActor to cJumpPad
			cJumpPad* JumpPad = dynamic_cast<cJumpPad*>(Actor);

			// Use Jump Pad Bounds
			if (_bounds.findIntersection(JumpPad->GetJumpPadBounds())) {
				// Return the Actor
				return Actor;
			}

			continue;
		}

		// Check the Intersection of the FloatRect bounds
		if (_bounds.findIntersection(Actor->m_ActorSprite.getGlobalBounds())) {
			// Return the Actor
			return Actor;
		}
	}

	// Returns nullptr otherwise (No Collision found)
	return nullptr;
}

void cActor::SetActorType(ActorType _type) {
	this->m_ActorType = _type;

	// Updates Dynamic and Collision
	switch (_type) {
		case (ActorType::NONE): {
			this->m_IsDynamic = false;
			this->m_CollisionType = CollisionType::NONE;
		} break;

		case (ActorType::SOLID): {
			this->m_IsDynamic = false;
			this->m_CollisionType = CollisionType::FULL;
		} break;

		case (ActorType::SOLID_THROUGH): {
			this->m_IsDynamic = false;
			this->m_CollisionType = CollisionType::THROUGH;
			this->m_HasGravity = false;
		} break;

		case (ActorType::SOLID_THROUGH_MOVING): {
			this->m_IsDynamic = true;
			this->m_CollisionType = CollisionType::THROUGH;
			this->m_HasGravity = false;
		} break;

		case (ActorType::JUMP_PAD): {
			this->m_IsDynamic = false;
			this->m_CollisionType = CollisionType::FULL;
			this->m_HasGravity = false;
		} break;

		case (ActorType::PLAYER): {
			this->m_IsDynamic = true;
			this->m_CollisionType = CollisionType::FULL;
			this->m_HasGravity = true;
		} break;

		case (ActorType::SOLID_PUSHABLE): {
			this->m_IsDynamic = true;
			this->m_CollisionType = CollisionType::FULL;
			this->m_HasGravity = true;
		} break;
	}
}

void cActor::SetActorSprite(unsigned int _x, unsigned int _y) {
	this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(_x, _y));
}

void cActor::SetActorSprite(unsigned int _n) {
	this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(_n));
}

void cActor::SetActorPosition(sf::Vector2f _position) {
	this->m_ActorPosition = _position;
	this->m_ActorSprite.setPosition(_position);
}

void cActor::SetActorCollision(CollisionType _collisionType) {
	this->m_CollisionType = _collisionType;
}

void cActor::SetActorDynamic(bool _isDynamic) {
	this->m_IsDynamic = _isDynamic;
}

void cActor::SetActorVelocity(sf::Vector2f _velocity) {
	this->m_Velocity = _velocity;
}

void cActor::SetActorAcceleration(sf::Vector2f _acceleration) {
	this->m_Acceleration = _acceleration;
}

ActorType cActor::GetActorType() const {
	return this->m_ActorType;
}

sf::Sprite cActor::GetActorSprite() const {
	return this->m_ActorSprite;
}

sf::Vector2f cActor::GetActorPosition() const {
	return this->m_ActorPosition;
}
CollisionType cActor::GetActorCollision() const {
	return this->m_CollisionType;
}

bool cActor::GetActorDynamic() const {
	return this->m_IsDynamic;
}

bool cActor::GetActorHasGravity() const {
	return this->m_HasGravity;
}

const float cActor::GetActorGravity() const {
	return this->m_Gravity;
}

const float cActor::GetActorSpeedScalar() const {
	return this->m_SpeedScalar;
}

sf::Vector2f cActor::GetActorVelocity() const {
	return this->m_Velocity;
}

sf::Vector2f cActor::GetActorAcceleration() const {
	return this->m_Acceleration;
}
