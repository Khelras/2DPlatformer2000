/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cEventManager.cpp
 Description :   Defines the cEventManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cEventManager.h"

cEventManager::cEventManager() {
	this->m_MainWindow = nullptr;
	this->m_DebugWindow = nullptr;
}

cEventManager::~cEventManager() {
}

void cEventManager::Intialise(sf::RenderWindow& _mainWindow, sf::RenderWindow& _debugWindow) {
	this->m_MainWindow = &_mainWindow;
	this->m_DebugWindow = &_debugWindow;
}

void cEventManager::Process(cPlayer* _player) {
	// Events for the Main Window
	while (const std::optional event = this->m_MainWindow->pollEvent()) {
		// Close Event
		if (event->is<sf::Event::Closed>()) {
			this->m_MainWindow->close(); // Close Window
		}

		// Key Pressed Event
		if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
			// Jump
			if (key->scancode == sf::Keyboard::Scancode::Up) {
				_player->Jump();
			}

			// Down
			if (key->scancode == sf::Keyboard::Scancode::Down) {
				_player->SetPlayerPhaseThrough(true);
			}
		}

		// Key Released Event
		if (const auto* key = event->getIf<sf::Event::KeyReleased>()) {
			// Down
			if (key->scancode == sf::Keyboard::Scancode::Down) {
				_player->SetPlayerPhaseThrough(false);
			}

			// Left
			if (key->scancode == sf::Keyboard::Scancode::Left) {
				_player->IdlePlayer();
			}

			// Right
			if (key->scancode == sf::Keyboard::Scancode::Right) {
				_player->IdlePlayer();
			}
		}
	}
}
