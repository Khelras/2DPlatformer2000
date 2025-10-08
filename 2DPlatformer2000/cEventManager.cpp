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
#include <iostream>

cEventManager::cEventManager() {
	this->m_MainWindow = nullptr;
	this->m_IsShiftPressed = false;
}

cEventManager::~cEventManager() {
}

void cEventManager::Intialise(sf::RenderWindow& _mainWindow) {	
	this->m_MainWindow = &_mainWindow;
}

void cEventManager::Process(GameSettings& _settings, sf::RenderWindow* _debugWindow, cLevelManager& _levelManager) {
	// Player
	cPlayer* PlayerActor = _levelManager.GetPlayer();
	
	// Only Process Events when there is a Player
	if (PlayerActor == nullptr) {
		// Only allow Close Window Event
		while (const std::optional event = this->m_MainWindow->pollEvent()) {
			// Close Event
			if (event->is<sf::Event::Closed>()) {
				this->m_MainWindow->close(); // Close Window
			}
		}

		return;
	};
	
	// Only Process Main Window Events if Debug Window is Closed
	if (_debugWindow->isOpen() == false || _debugWindow == nullptr) {
		// Events for the Main Window
		while (const std::optional event = this->m_MainWindow->pollEvent()) {
			// Close Event
			if (event->is<sf::Event::Closed>()) {
				this->m_MainWindow->close(); // Close Window
			}

			// Key Pressed Event
			if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
				// Open Debug Window
				if (key->scancode == sf::Keyboard::Scancode::Escape) { // Escape Key
					// Open Debug Window
					_debugWindow->create(sf::VideoMode({ 600, 600 }), "Epic Debugger 2000!");
					_debugWindow->setFramerateLimit(30); // Framerate Limit to 30fps
					_debugWindow->setKeyRepeatEnabled(false); // Prevents Key Repeats

					// Move Debug Window to the Right of the Main Window
					sf::Vector2i DebugWindowPosition = this->m_MainWindow->getPosition();
					DebugWindowPosition.x += this->m_MainWindow->getSize().x;
					_debugWindow->setPosition(DebugWindowPosition);
				}

				// Jump
				if (key->scancode == sf::Keyboard::Scancode::Up) { // Up-Arrow Key
					PlayerActor->Jump(_settings);
				}

				// Down
				if (key->scancode == sf::Keyboard::Scancode::Down) { // Down-Arrow Key
					PlayerActor->SetPlayerPhaseThrough(true);
				}
			}

			// Key Released Event
			if (const auto* key = event->getIf<sf::Event::KeyReleased>()) {
				// Down
				if (key->scancode == sf::Keyboard::Scancode::Down) { // Down-Arrow Key
					PlayerActor->SetPlayerPhaseThrough(false);
				}

				// Left
				if (key->scancode == sf::Keyboard::Scancode::Left) { // Left-Arrow Key
					PlayerActor->IdlePlayer();
				}

				// Right
				if (key->scancode == sf::Keyboard::Scancode::Right) { // Right-Arrow Key
					PlayerActor->IdlePlayer();
				}
			}
		}
	}
	// Debug Window is Open
	else if (_debugWindow->isOpen() == true) {
		// Events for the Main Window (Only Close Event)
		while (const std::optional event = this->m_MainWindow->pollEvent()) {
			// Close Event
			if (event->is<sf::Event::Closed>()) {
				this->m_MainWindow->close(); // Close Window
			}
		}

		// Events for the Debug Window
		while (const std::optional event = _debugWindow->pollEvent()) {
			// Close Event
			if (event->is<sf::Event::Closed>()) {
				_debugWindow->close(); // Close Window
			}

			// Key Pressed Event
			if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
				// Close Debug Window
				if (key->scancode == sf::Keyboard::Scancode::Escape) { // Escape Key
					// Close Debug Window
					_debugWindow->close();
				}

				// Shift Key Pressed
				if (key->scancode == sf::Keyboard::Scancode::LShift) {
					this->m_IsShiftPressed = true;
				}

				// Actor Gravity
				if (key->scancode == sf::Keyboard::Scancode::G) {
					// Increase/Decrease Actor Gravity
					_settings.m_ActorGravity += (this->m_IsShiftPressed) ? -1.0f : 1.0f;

					// Output to Console
					std::cout << "Actor Gravity: ";
					std::cout << _settings.m_ActorGravity << std::endl;
				}
				// Actor Speed Scalar
				else if (key->scancode == sf::Keyboard::Scancode::S) {
					// Increase/Decrease Actor Speed Scalar
					_settings.m_ActorSpeedScalar += (this->m_IsShiftPressed) ? -1.0f : 1.0f;

					// Output to Console
					std::cout << "Actor Speed Scalar: ";
					std::cout << _settings.m_ActorSpeedScalar << std::endl;
				}
				// Player Lives
				else if (key->scancode == sf::Keyboard::Scancode::L) {
					// Increase/Decrease Player Lives
					_settings.m_PlayerLives += (this->m_IsShiftPressed) ? -1 : 1;

					// Output to Console
					std::cout << "Player Lives: ";
					std::cout << _settings.m_PlayerLives << std::endl;
				}
				// Player Movement Speed
				else if (key->scancode == sf::Keyboard::Scancode::M) {
					// Increase/Decrease Player Movement Speed
					_settings.m_PlayerMoveSpeed += (this->m_IsShiftPressed) ? -1.0f : 1.0f;

					// Output to Console
					std::cout << "Player Movement Speed: ";
					std::cout << _settings.m_PlayerMoveSpeed << std::endl;
				}
				// Player Jump Height
				else if (key->scancode == sf::Keyboard::Scancode::J) {
					// Increase/Decrease Player Jump Height
					_settings.m_PlayerJumpHeight += (this->m_IsShiftPressed) ? 1.0f : -1.0f;

					// Output to Console
					std::cout << "Player JumpHeight: ";
					std::cout << _settings.m_PlayerJumpHeight << std::endl;
				}
				// Player Infinite Double Jump
				else if (key->scancode == sf::Keyboard::Scancode::I) {
					// Toggle On/Off Player Infinite Doule Jump
					_settings.m_PlayerInfiniteDoubleJump = (this->m_IsShiftPressed) ? false : true;

					// Output to Console
					std::cout << "Player Infinite Double Jump: ";
					std::cout << ((_settings.m_PlayerInfiniteDoubleJump) ? "True" : "False") << std::endl;
				}
				// Jump Pad Height
				else if (key->scancode == sf::Keyboard::Scancode::P) {
					// Increase/Decrease Jump Pad Height 
					_settings.m_JumpPadHeight += (this->m_IsShiftPressed) ? 1.0f : -1.0f;

					// Output to Console
					std::cout << "Jump Pad Height : ";
					std::cout << _settings.m_JumpPadHeight << std::endl;
				}
				// Reset to Default
				else if (key->scancode == sf::Keyboard::Scancode::R) {
					// Reset all Settings to Default
					if (this->m_IsShiftPressed == false) {
						// Reset all Settings back to Default
						_settings.ResetSettings();

						// Output to Console
						std::cout << "Reset all Settings to Default!" << std::endl;
					}
					// Restarted the whole Game
					else if (this->m_IsShiftPressed == true) {
						// Restart Game
						_settings.ResetPlayerLives(); // Reset Player Lives
						_levelManager.RestartGame();

						// Output to Console
						std::cout << "Restarted the Whole Game!" << std::endl;
					}
					
				}
			}

			// Key Released Event
			if (const auto* key = event->getIf<sf::Event::KeyReleased>()) {
				// Shift Key Released
				if (key->scancode == sf::Keyboard::Scancode::LShift) {
					this->m_IsShiftPressed = false;
				}
			}
		}
	}
}

void cEventManager::ProcessTutorial(bool& _isTutorial) {
	// Events for the Main Window
	while (const std::optional event = this->m_MainWindow->pollEvent()) {
		// Close Event
		if (event->is<sf::Event::Closed>()) {
			this->m_MainWindow->close(); // Close Window
		}

		// Key Pressed Event
		if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
			// Press Enter
			if (key->scancode == sf::Keyboard::Scancode::Enter) {
				// Close Tutorial
				_isTutorial = false;
			}
		}
	}
}
