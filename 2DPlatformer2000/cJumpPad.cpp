/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cJumpPad.cpp
 Description :   Defines the cJumpPad Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cJumpPad.h"

cJumpPad::cJumpPad() : cActor(ActorType::JUMP_PAD),
	m_JumpPadAnimation(PlaybackType::REVERSE_ONCE, this->m_TileMap, this->m_ActorSprite, 163, 165) {
	// Jump Pad Sprite
	this->m_ActorSprite.setTextureRect(this->m_TileMap.GetTile(163));

	// Jump Pad Tiles
	this->m_IdleTile = 163;
	this->m_ActivationTileStart = 163;
	this->m_ActivationTileEnd = 165;

	// Jump Pad Attributes
	this->m_JumpPadHeight = -30.0f;
}

cJumpPad::~cJumpPad() {
	
}

void cJumpPad::UpdateActor(float _deltaTime, std::vector<cActor*> _actors) {
	// Calls the UpdateActor() Function from the cActor Base Class
	cActor::UpdateActor(_deltaTime, _actors);

	// Extend Functionality
	this->m_JumpPadAnimation.UpdateAnimation(_deltaTime);
}

sf::FloatRect cJumpPad::GetJumpPadBounds() {
	// Custom Player Bounds
	sf::FloatRect JumpPandBounds(
		sf::Vector2f(
			this->m_ActorPosition.x,
			this->m_ActorPosition.y + 8.0f
		),
		sf::Vector2f( // 16 x 8
			this->m_ActorSprite.getGlobalBounds().size.x,
			this->m_ActorSprite.getGlobalBounds().size.y - 8.0f
		)
	);
	return JumpPandBounds;
}

void cJumpPad::PlayJumpPadAnimation() {
	this->m_JumpPadAnimation.PlayAnimation();
}

int cJumpPad::GetJumpPadHeight() {
	return this->m_JumpPadHeight;
}
