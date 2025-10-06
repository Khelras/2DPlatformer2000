/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cActor.h
 Description :   Declares the cActor Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "GameSettings.h"
#include "cTileMap.h"

// Type of Actor
enum class ActorType {
	NONE = 0, // None
	SOLID = 1, // Static Solid
	SOLID_THROUGH = 2, // Players can Jump or Fall through this Solid
	SOLID_THROUGH_MOVING = 3, // Horizontally Dynamic Solid with Jump/Fall through
	JUMP_PAD = 4, // The Jump Pad Actor
	SPIKE = 5, // The Spike Actor
	KEY = 6, // The Key Actor
	DOOR = 7, // The Door Actor
	PLAYER = 10, // The Player Actor
	SOLID_PUSHABLE = 11 // Fully Dynamic Solids, Has Gravity, and can be Pushed
};

// Type of Collision
enum class CollisionType {
	NONE, // No Collision
	THROUGH, // Players can Jump or Fall through
	FULL // Full Collision
};

class cActor {
protected:
	// Actor Attributes
	cTileMap m_TileMap; // Tile Map
	ActorType m_ActorType; // Type of Actor
	sf::Sprite m_ActorSprite; // The Actor Sprite
	sf::Vector2f m_ActorPosition; // The Position of Actor

	// Physics Attributes
	CollisionType m_CollisionType; // Type of Collision
	bool m_IsDynamic; // Static or Dynamic Actor?
	bool m_HasGravity; // Does Gravity apply to this Actor?
	//const float m_Gravity = 60.0f; // Gravity
	//const float m_SpeedScalar = 10.0f; // Speed Scalar
	sf::Vector2f m_MoveRemainder; // Accumulate Movement
	sf::Vector2f m_Velocity; // Velocity of Actor
	sf::Vector2f m_Acceleration; // Acceleration of Actor

public:
	cActor(ActorType _actorType); // Constructor
	virtual ~cActor(); // Virtual Destructor

	// Actor Functions (Can be Overridden by any Derived Classes)
	virtual void DrawActor(sf::RenderWindow& _window); // Draw Actor Sprite to the Window
	virtual void UpdateActor(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors); // Updates the Actor
	virtual void MoveX(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors); // Horizontal Movement
	virtual void MoveY(GameSettings& _settings, float _deltaTime, std::vector<cActor*> _actors); // Vertical Movement
	virtual cActor* CheckCollision(sf::FloatRect _bounds, std::vector<cActor*> _actors); // Checks Collision against all Actors

	// Setters for Actor Attributes
	virtual void SetActorType(ActorType _type); // Sets the Actor Type
	virtual void SetActorSprite(unsigned int _x, unsigned int _y); // Sets the Actor Sprite given X and Y of Tile Map
	virtual void SetActorSprite(unsigned int _n); // Sets the Actor Sprite given the n'th Tile in the Tile Map
	virtual void SetActorPosition(sf::Vector2f _position); // Sets the Position of the Actor

	// Setters for Physics Attributes
	virtual void SetActorCollision(CollisionType _collisionType); // Sets the Collision Type of the Actor
	virtual void SetActorDynamic(bool _isDynamic); // Sets the Dynamic of the Actor
	virtual void SetActorVelocity(sf::Vector2f _velocity); // Sets the Velocity of the Actor
	virtual void SetActorAcceleration(sf::Vector2f _acceleration); // Sets the Acceleration of the Actor

	// Getters for Actor Attributes
	virtual ActorType GetActorType() const; // Returns the Actor Type
	virtual sf::Sprite GetActorSprite() const; // Returns the Actor Sprite based on the Tile Index
	virtual sf::Vector2f GetActorPosition() const; // Returns the Position of the Actor

	// Getts for Physics Attributes
	virtual CollisionType GetActorCollision() const; // Returns the Collision Type of the Actor
	virtual bool GetActorDynamic() const; // Returns the Dynamic Boolean of the Actor
	virtual bool GetActorHasGravity() const; // Returns the Gravity Boolean of the Actor
	virtual sf::Vector2f GetActorVelocity() const; // Returns the Velocity of Actor
	virtual sf::Vector2f GetActorAcceleration() const; // Returns the Acceleration of Actor
};

