/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cPlayer.h
 Description :   Defines the cPlayer Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cPlayer.h"
#include "cJumpPad.h"

cPlayer::cPlayer() : cActor(ActorType::PLAYER),
	m_MovementAnimation(PlaybackType::NORMAL_LOOP, this->m_TileMap, this->m_ActorSprite, 261, 264) {
	// Player Sprite
	this->SetActorSprite(0, 13);

	// Player Tiles
	this->m_IdleTile = 260;
	this->m_JumpTile = 265;
	this->m_MovementTileStart = 261;
	this->m_MovementTileEnd = 264;

	// Player Attributes
	this->m_Lives = this->m_MaxLives; // Start with Max Lives
	this->m_MoveSpeed = 8.0f;
	this->m_JumpHeight = -20.0f;
	this->m_HasDoubleJumped = false;
	this->m_HasPhasedThrough = false;
}

cPlayer::~cPlayer() {
}

void cPlayer::UpdateActor(float _deltaTime, std::vector<cActor*> _actors) {
	// Check if Actor is Dynamic because Static Actors do not move
	if (this->m_IsDynamic == false) return;

	// Apply Gravity
	if (this->m_HasGravity == true && this->m_Velocity.y < 100) {
		// Custom Player Bounds
		sf::FloatRect PlayerBounds(this->GetPlayerBounds());
		PlayerBounds.position.y++; // Check for something underneath

		// Collision Actor
		cActor* CollisionActor = this->CheckCollision(PlayerBounds, _actors);

		// Now check if Actor is NOT the ground
		if (CollisionActor == nullptr) {
			this->m_Velocity.y += this->m_Gravity * _deltaTime; // Gravity
		}
		else {
			// If the Collision Actor is an Actor Type of Solid Through
			if (CollisionActor->GetActorType() == ActorType::SOLID_THROUGH
				|| CollisionActor->GetActorType() == ActorType::SOLID_THROUGH_MOVING) {
				// Going Upwards
				if (this->m_Velocity.y < 0) {
					this->m_Velocity.y += this->m_Gravity * _deltaTime; // Gravity
				}
				// Going Downwards
				else {
					sf::FloatRect SelfBounds = this->m_ActorSprite.getGlobalBounds();
					sf::FloatRect CollisionBounds = CollisionActor->GetActorSprite().getGlobalBounds();

					// If the Feet of Self is colliding the Top of the Solid Through Platform
					if (SelfBounds.position.y + SelfBounds.size.y == CollisionBounds.position.y) {
						// Check Phase Through
						if (this->m_HasPhasedThrough == true) {
							this->m_Velocity.y += this->m_Gravity * _deltaTime; // Gravity
						}
						else {
							// Back to Idle
							if (this->m_Velocity.x == 0) {
								this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(this->m_IdleTile));
							}
						}

						// Reset Double Jump
						this->m_HasDoubleJumped = false;
					}
					else {
						this->m_Velocity.y += this->m_Gravity * _deltaTime; // Gravity
					}
				}
			}
			else {
				// Reset Double Jump
				this->m_HasDoubleJumped = false; 

				// Back to Idle
				if (this->m_Velocity.x == 0) {
					this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(this->m_IdleTile));
				}
			}
		}
	}

	// Allow Movement by Moving Platforms at this Frame
	this->m_HasMovedByPlatform = false;

	// Apply Acceleration
	this->m_Velocity += this->m_Acceleration * _deltaTime;

	// Apply Movement
	this->MoveX(_deltaTime, _actors);
	this->MoveY(_deltaTime, _actors);

	// Set Sprite Position
	this->m_ActorSprite.setPosition(this->m_ActorPosition);

	// Animations
	this->m_MovementAnimation.UpdateAnimation(_deltaTime);
}

void cPlayer::MoveX(float _deltaTime, std::vector<cActor*> _actors) {
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

		// Custom Player Bounds
		sf::FloatRect PlayerBounds(this->GetPlayerBounds());
		PlayerBounds.position.x += iDirectionX; // Simulate Movement towards Direction

		// Collision Actor
		cActor* CollisionActor = this->CheckCollision(PlayerBounds, _actors);

		// There is NO collision
		if (CollisionActor == nullptr) {
			// Proceed with Movement
			this->m_ActorPosition.x += static_cast<float>(iDirectionX);
			iMoveX -= iDirectionX;
		}
		// There IS a collision
		else if (CollisionActor != nullptr) {
			// If the Collision Actor is an Actor Type of Solid Through
			if (CollisionActor->GetActorType() == ActorType::SOLID_THROUGH
				|| CollisionActor->GetActorType() == ActorType::SOLID_THROUGH_MOVING) {
				// Proceed with Movement
				this->m_ActorPosition.x += static_cast<float>(iDirectionX);
				iMoveX -= iDirectionX;
				continue;
			}

			// The Collision Actor is Dynamic
			if (CollisionActor->GetActorDynamic() == true) {
				// Check if Player can Push this Object
				if (CollisionActor->GetActorType() == ActorType::SOLID_PUSHABLE) {
					// Check if the Collision Actor can be Pushed
					sf::FloatRect PushBounds(
						sf::Vector2f(
							CollisionActor->GetActorPosition().x + iDirectionX, // Push towards Direction
							CollisionActor->GetActorPosition().y
						),
						CollisionActor->GetActorSprite().getGlobalBounds().size
					);

					// Check for Collisions in scope of the Collision Actor
					if (CollisionActor->CheckCollision(PushBounds, _actors) == nullptr) {
						// Push the Collision Actor
						sf::Vector2f PushPosition = CollisionActor->GetActorPosition();
						PushPosition.x += static_cast<float>(iDirectionX);
						CollisionActor->SetActorPosition(PushPosition);

						// Proceed with Movement
						this->m_ActorPosition.x += static_cast<float>(iDirectionX);
						iMoveX -= iDirectionX;

						// Returning now will cuts this movement off
						// This will make the player appear slower when pushing something
						return;
					}
				}

				// Otherwise, Stop Movement
				this->m_Velocity.x = 0.0f; // Stops any Horizontal Movement
				return;
			}
			// The Collision Actor is Static
			else if (CollisionActor->GetActorDynamic() == false) {
				// If Player walks onto a Jump Pad
				if (CollisionActor->GetActorType() == ActorType::JUMP_PAD) {
					// Dynamic Cast cActor to cPlayer
					cJumpPad* JumpPad = dynamic_cast<cJumpPad*>(CollisionActor);

					// Stand on the Jump Pad
					this->m_ActorPosition.y -= JumpPad->GetJumpPadBounds().size.y;

					// Proceed with Movement
					this->m_ActorPosition.x += static_cast<float>(iDirectionX);
					iMoveX -= iDirectionX;
					continue;
				}

				// Stop Movement
				this->m_Velocity.x = 0.0f; // Stops any Horizontal Movement
				return; // Collision Resolved
			}
		}
	}
}

void cPlayer::MoveY(float _deltaTime, std::vector<cActor*> _actors) {
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

		// Set Sprite Tile to Jump Tile
		if (this->m_Velocity.x == 0) {
			this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(this->m_JumpTile));
		}
		else if (this->m_Velocity.x < 0) { // Player is Moving Left
			this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(this->m_MovementTileEnd));
		}
		else if (this->m_Velocity.x > 0) { // Player is Moving Right
			this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(this->m_MovementTileEnd));
		}

		// Custom Player Bounds
		sf::FloatRect PlayerBounds(this->GetPlayerBounds());
		PlayerBounds.position.y += iDirectionY; // Simulate Movement towards Direction

		// Collision Actor
		cActor* CollisionActor = this->CheckCollision(PlayerBounds, _actors);

		// There is NO collision
		if (CollisionActor == nullptr) {
			// Proceed with Movement
			this->m_ActorPosition.y += static_cast<float>(iDirectionY);
			iMoveY -= iDirectionY;
		}
		// There IS a collision
		else if (CollisionActor != nullptr) {
			// Going Upwards
			if (iDirectionY < 0) {
				// If the Collision Actor is an Actor Type of Solid Through
				if (CollisionActor->GetActorType() == ActorType::SOLID_THROUGH
					|| CollisionActor->GetActorType() == ActorType::SOLID_THROUGH_MOVING) {
					// Proceed with Movement
					this->m_ActorPosition.y += static_cast<float>(iDirectionY);
					iMoveY -= iDirectionY;
					continue;
				}

				// Start falling early when bumping head
				this->m_Velocity.y = 0.25f;
				return;
			}
			// Going Downwards
			else if (iDirectionY > 0) {
				// If the Collision Actor is an Actor Type of Solid Through
				if (CollisionActor->GetActorType() == ActorType::SOLID_THROUGH
					|| CollisionActor->GetActorType() == ActorType::SOLID_THROUGH_MOVING) {
					// If the Feet of Self is colliding the Top of the Solid Through Platform
					if ((PlayerBounds.position.y + PlayerBounds.size.y) - 1.0f
						== CollisionActor->GetActorSprite().getGlobalBounds().position.y) {
						if (this->m_HasPhasedThrough == true) {
							this->m_ActorPosition.y += static_cast<float>(iDirectionY);
							iMoveY -= iDirectionY;
							this->m_HasPhasedThrough == false;
							continue;
						}

						// Stop Falling
						this->m_Velocity.y = 0;
						return;
					}

					// Otherwise, Keep Falling
					this->m_ActorPosition.y += static_cast<float>(iDirectionY);
					iMoveY -= iDirectionY;
					continue;
				}
				// If the Collision Actor is an Actor Type of Jump Pad
				else if (CollisionActor->GetActorType() == ActorType::JUMP_PAD) {
					// Dynamic Cast cActor to cJumpPad
					cJumpPad* JumpPad = dynamic_cast<cJumpPad*>(CollisionActor);

					// Play Animation
					JumpPad->PlayJumpPadAnimation();

					// Launch Player
					this->m_Velocity.y = JumpPad->GetJumpPadHeight();
					return;
				}
				// Other Collision Actor Types
				else {
					// Stop Falling
					this->m_Velocity.y = 0;
					return;
				}
			}
		}
	}
}

sf::FloatRect cPlayer::GetPlayerBounds() {
	// Custom Player Bounds
	sf::FloatRect PlayerBounds(
		sf::Vector2f(
			this->m_ActorPosition.x + 2.0f,
			this->m_ActorPosition.y + 2.0f
		),
		sf::Vector2f( // 12 x 14
			this->m_ActorSprite.getGlobalBounds().size.x - 4.0f,
			this->m_ActorSprite.getGlobalBounds().size.y - 2.0f
		)
	);
	return PlayerBounds;
}

void cPlayer::MovePlayer(MovementDirection _direction) {
	// Play Movement Animation
	if (this->m_Velocity.y == 0) {
		this->m_MovementAnimation.PlayAnimation();
	}
	else {
		this->m_MovementAnimation.ResetAnimation();
	}

	// Left
	if (_direction == MovementDirection::LEFT) {
		this->m_ActorSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
		this->m_ActorSprite.setOrigin(sf::Vector2f(this->m_ActorSprite.getGlobalBounds().size.x, 0.0f));
		this->m_Velocity.x = -m_MoveSpeed;
	}

	// Right
	if (_direction == MovementDirection::RIGHT) {
		this->m_ActorSprite.setScale(sf::Vector2f(1.0f, 1.0f));
		this->m_ActorSprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
		this->m_Velocity.x = m_MoveSpeed;
	}
}

void cPlayer::IdlePlayer() {
	this->m_MovementAnimation.ResetAnimation(); // Reset Animation
	this->m_Velocity.x = 0.0f; // Stop Horizontal Movement
	this->m_ActorSprite.setScale(sf::Vector2f(1.0f, 1.0f)); // Reset Scale
	this->m_ActorSprite.setOrigin(sf::Vector2f(0.0f, 0.0f)); // Reset Origin
	this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(this->m_IdleTile)); // Idle Tile
}

void cPlayer::Jump() {
	// Player is touching the ground
	if (this->m_Velocity.y == 0) {
		this->m_HasDoubleJumped = false; // Reset Double Jump
		this->m_Velocity.y = this->m_JumpHeight; // Jump
	}
	// Player is airborne
	else {
		// Double Jump
		if (this->m_HasDoubleJumped == false) {
			this->m_HasDoubleJumped = true; // Prevent extra Double Jumps
			this->m_Velocity.y = this->m_JumpHeight; // Jump
		}
	}
}

void cPlayer::SetPlayerPhaseThrough(bool _phase) {
	this->m_HasPhasedThrough = _phase;
}

void cPlayer::SetPlayerLives(int _lives) {
	this->m_Lives = _lives;
}

void cPlayer::SetPlayerMovedByPlatform(bool _hasMoved) {
	this->m_HasMovedByPlatform = _hasMoved;
}

const bool cPlayer::GetPlayerPhaseThrough() const {
	return this->m_HasPhasedThrough;
}

const int cPlayer::GetPlayerLives() const {
	return this->m_Lives;
}

const int cPlayer::GetPlayerMaxLives() const {
	return this->m_MaxLives;
}

const bool cPlayer::GetPlayerMovedByPlatform() const {
	return this->m_HasMovedByPlatform;
}