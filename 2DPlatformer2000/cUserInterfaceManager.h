/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cUserInterfaceManager.h
 Description :   Declares the cUserInterfaceManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cUserInterface.h"
#include "cPlayer.h"

class cUserInterfaceManager {
private:
	cTileMap m_TileMap;
	std::vector<cUserInterface> m_PlayerLivesUI;
	cUserInterface m_PlayerKey;

public:
	cUserInterfaceManager(); // Constructor
	~cUserInterfaceManager(); // Destructor

	// User Interface Manager Functions
	void Process(GameSettings& _settings, cPlayer* _player); // Process User Interface
	void DrawUI(sf::RenderWindow& _window); // Draw the User Interface
};

