/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cKey.cpp
 Description :   Defines the cKey Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cKey.h"

cKey::cKey(cTileMap* _tileMap) : cActor(_tileMap, ActorType::KEY) {
	// Key Sprite
	this->SetActorSprite(96);

	// Key Tile
	this->m_KeyTile = 96;
}

cKey::~cKey() {
}

sf::FloatRect cKey::GetKeyBounds() {
	return sf::FloatRect(
		sf::Vector2f(
			this->m_ActorPosition.x + 7.0f,
			this->m_ActorPosition.y + 7.0f
		),
		sf::Vector2f( // 2 x 2
			2.0f,
			2.0f
		)
	);
}
