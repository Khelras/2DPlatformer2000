/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cGameManager.cpp
 Description :   Defines the cGameManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cGameManager.h"

cGameManager::cGameManager() {
	// Managers
	this->m_EventManager.Intialise(this->m_WindowManager.GetMainWindow());
	this->m_CameraManager.Initialise(this->m_WindowManager.GetMainWindow());

	// Other
	this->m_DeltaTime = 0.0f;
	this->m_IsTutorial = true;
}

cGameManager::~cGameManager() {
}

void cGameManager::Process() {
	// Clock (for Delta Time)
	sf::Clock Clock;

	// Starts Window Manager (Main Game Loop)
	while (this->m_WindowManager.Process()) {
		// Tutorial Screen
		if (this->m_IsTutorial == true) {
			// Event Mananger Processing for Tutorial
			this->m_EventManager.ProcessTutorial(this->m_IsTutorial);

			// Window Manager Processing for Tutorial
			this->m_WindowManager.ProcessTutorial();

			continue;
		}

		// Delta Time
		this->m_DeltaTime = Clock.restart().asSeconds();

		// Event Processing
		this->m_EventManager.Process(this->m_GameSettings, this->m_WindowManager.GetDebugWindow(), this->m_LevelManager);

		// Clear
		this->m_WindowManager.Clear(this->m_WindowManager.GetDebugWindow()->isOpen());

		// If Debug Window is Closed
		if (this->m_WindowManager.GetDebugWindow()->isOpen() == false) {
			// User Interface Processing
			this->m_UserInterfaceManager.Process(this->m_GameSettings, this->m_LevelManager.GetPlayer());

			// Player
			this->PlayerControls(); // Player Controls

			// Level Manager Processing
			this->m_LevelManager.Process(this->m_GameSettings, this->m_DeltaTime, this->m_WindowManager.GetMainWindow());

			// Draw User Interfaces
			this->m_UserInterfaceManager.DrawUI(this->m_WindowManager.GetMainWindow());
		}

		// Draw
		this->m_WindowManager.Draw(this->m_WindowManager.GetDebugWindow()->isOpen());

		// Display
		this->m_WindowManager.Display(this->m_WindowManager.GetDebugWindow()->isOpen());
	}
}

void cGameManager::PlayerControls() {
	// Ensures a Player Exists
	if (this->m_LevelManager.GetPlayer() != nullptr) {
		// Left Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			this->m_LevelManager.GetPlayer()->MovePlayer(MovementDirection::LEFT, this->m_GameSettings);
		}

		// Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			this->m_LevelManager.GetPlayer()->MovePlayer(MovementDirection::RIGHT, this->m_GameSettings);
		}
	}
}
