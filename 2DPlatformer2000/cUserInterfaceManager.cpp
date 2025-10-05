/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cUserInterfaceManager.cpp
 Description :   Defines the cUserInterfaceManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cUserInterfaceManager.h"

cUserInterfaceManager::cUserInterfaceManager() {
	this->m_TileMap = nullptr;
}

cUserInterfaceManager::~cUserInterfaceManager() {
}

void cUserInterfaceManager::Initialise(cTileMap* _tileMap) {
	// Tile Map
	this->m_TileMap = _tileMap;

	// Player Lives UI
	this->m_PlayerLivesUI.reserve(3);
	this->m_PlayerLivesUI.push_back(cUserInterface(this->m_TileMap)); // First Heart
	this->m_PlayerLivesUI[0].SetUISprite(2, 2);
	this->m_PlayerLivesUI[0].SetUIPosition(sf::Vector2f(-142.0f, -120.0f));

	this->m_PlayerLivesUI.push_back(cUserInterface(this->m_TileMap)); // First Heart
	this->m_PlayerLivesUI[1].SetUISprite(2, 2);
	this->m_PlayerLivesUI[1].SetUIPosition(sf::Vector2f(-126.0f, -120.0f));

	this->m_PlayerLivesUI.push_back(cUserInterface(this->m_TileMap)); // First Heart
	this->m_PlayerLivesUI[2].SetUISprite(2, 2);
	this->m_PlayerLivesUI[2].SetUIPosition(sf::Vector2f(-110.0f, -120.0f));
}

void cUserInterfaceManager::Process(cPlayer* _player) {
	// Player Lives Update Process
	for (int i = _player->GetPlayerLives(); i < 3; i++) {
		// Update the Player Lives
		this->m_PlayerLivesUI[i].SetUIOpacity(100);
	}
}

void cUserInterfaceManager::DrawUI(sf::RenderWindow& _window) {
	for (cUserInterface UI : this->m_PlayerLivesUI) {
		_window.draw(UI.GetUISprite());
	}
}
