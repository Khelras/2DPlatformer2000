/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cSpike.cpp
 Description :   Defines the cSpike Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cSpike.h"

cSpike::cSpike(cTileMap* _tileMap) : cActor(_tileMap, ActorType::SPIKE) {
	// Spike Sprite
	this->SetActorSprite(183);

	// Spike Tile
	this->m_SpikeTile = 183;
}

cSpike::~cSpike() {
}

sf::FloatRect cSpike::GetSpikeBounds() const {
	return sf::FloatRect(
		sf::Vector2f(
			this->m_ActorPosition.x,
			this->m_ActorPosition.y + 8
		),
		sf::Vector2f( // 16 x 8
			this->m_ActorSprite.getGlobalBounds().size.x,
			this->m_ActorSprite.getGlobalBounds().size.y - 8
		)
	);
}
