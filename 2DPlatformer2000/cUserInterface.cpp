/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cUserInterface.cpp
 Description :   Defines the cUserInterface Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cUserInterface.h"

cUserInterface::cUserInterface(cTileMap* _tileMap) : m_UISprite(_tileMap->GetTileMapTexture()) {
	this->m_TileMap = _tileMap;
	this->m_UISprite.setTextureRect(_tileMap->GetTile(0));
}

cUserInterface::~cUserInterface() {
}

const sf::Sprite& cUserInterface::GetUISprite() const {
	return this->m_UISprite;
}

void cUserInterface::SetUISprite(unsigned int _x, unsigned int _y) {
	this->m_UISprite.setTextureRect(this->m_TileMap->GetTile(_x, _y));
}

void cUserInterface::SetUISprite(unsigned int _n) {
	this->m_UISprite.setTextureRect(this->m_TileMap->GetTile(_n));
}

void cUserInterface::SetUIPosition(sf::Vector2f _position) {
	this->m_UIPosition = _position;
	this->m_UISprite.setPosition(_position);
}

void cUserInterface::SetUIOpacity(unsigned int _alpha) {
	int iAlpha = (_alpha <= 255) ? _alpha : 255; // Maxes to 255
	this->m_UISprite.setColor(sf::Color(255, 255, 255, iAlpha));
}
