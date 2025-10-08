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

cUserInterfaceManager::cUserInterfaceManager() : m_PlayerKey(&this->m_TileMap) {
	// Player Lives UI
	this->m_PlayerLivesUI.reserve(3);
	this->m_PlayerLivesUI.push_back(cUserInterface(&(this->m_TileMap))); // First Heart
	this->m_PlayerLivesUI[0].SetUISprite(2, 2);
	this->m_PlayerLivesUI[0].SetUIPosition(sf::Vector2f(4.0f, 4.0f));

	this->m_PlayerLivesUI.push_back(cUserInterface(&(this->m_TileMap))); // Second Heart
	this->m_PlayerLivesUI[1].SetUISprite(2, 2);
	this->m_PlayerLivesUI[1].SetUIPosition(sf::Vector2f(20.0f, 4.0f));

	this->m_PlayerLivesUI.push_back(cUserInterface(&(this->m_TileMap))); // Third Heart
	this->m_PlayerLivesUI[2].SetUISprite(2, 2);
	this->m_PlayerLivesUI[2].SetUIPosition(sf::Vector2f(36.0f, 4.0f));

	// Player Key
	this->m_PlayerKey.SetUISprite(96);
	this->m_PlayerKey.SetUIPosition(sf::Vector2f(4.0f, 20.0f));
}

cUserInterfaceManager::~cUserInterfaceManager() {
}

void cUserInterfaceManager::Process(GameSettings& _settings, cPlayer* _player) {
	// Player Exists
	if (_player != nullptr) {
		// Player Lives Update Process
		for (int i = 0; i < 3; i++) {
			// Update the Player Lives
			this->m_PlayerLivesUI[i].SetUIOpacity(255);
		}
		for (int i = _settings.m_PlayerLives; i < 3; i++) {
			// Update the Player Lives
			this->m_PlayerLivesUI[i].SetUIOpacity(100);
		}

		// Player Keys
		if (_player->HasKey() == true) { // Has Key
			this->m_PlayerKey.SetUIOpacity(255);
		}
		else { // No Key
			this->m_PlayerKey.SetUIOpacity(0);
		}
	}
	// Player does NOT Exists
	else {
		// Hide all UI
		this->m_PlayerLivesUI[0].SetUIOpacity(0);
		this->m_PlayerLivesUI[1].SetUIOpacity(0);
		this->m_PlayerLivesUI[2].SetUIOpacity(0);
		this->m_PlayerKey.SetUIOpacity(0);
	}
}

void cUserInterfaceManager::DrawUI(sf::RenderWindow& _window) {
	// Draw Lives
	for (cUserInterface UI : this->m_PlayerLivesUI) {
		_window.draw(UI.GetUISprite());
	}

	// Draw Key
	_window.draw(this->m_PlayerKey.GetUISprite());
}
