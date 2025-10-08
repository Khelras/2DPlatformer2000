/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cDoor.cpp
 Description :   Defines the cDoor Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cDoor.h"

cDoor::cDoor(cTileMap* _tileMap) : cActor(_tileMap, ActorType::DOOR) {
	// Door Sprite
	this->SetActorSprite(56);

	// Door Tile
	this->m_DoorTile = 56;
}

cDoor::~cDoor() {
}

sf::FloatRect cDoor::GetDoorBounds() {
	return sf::FloatRect(
		sf::Vector2f(
			this->m_ActorPosition.x + 7.0f,
			this->m_ActorPosition.y + 14.0f
		),
		sf::Vector2f( // 2 x 2
			2.0f,
			2.0f
		)
	);
}
