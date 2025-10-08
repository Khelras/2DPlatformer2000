/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cEventManager.h
 Description :   Declares the cEventManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cLevelManager.h"

class cEventManager {
private:
	// Windows
	sf::RenderWindow* m_MainWindow; // Pointer to Main Window

	// Shift Key
	bool m_IsShiftPressed;

public:
	cEventManager(); // Constructor
	~cEventManager(); // Destructor

	// Event Manager Functions
	void Intialise(sf::RenderWindow& _mainWindow); // Initialise the Event Manager
	void Process(GameSettings& _settings, sf::RenderWindow* _debugWindow, cLevelManager& _levelManager); // Process Event Manager
};

