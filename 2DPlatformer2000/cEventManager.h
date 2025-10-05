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
#include "cPlayer.h"

class cEventManager {
private:
	// Windows
	sf::RenderWindow* m_MainWindow; // Pointer to Main Window
	sf::RenderWindow* m_DebugWindow; // Pointer to Debug Window

public:
	cEventManager(); // Constructor
	~cEventManager(); // Destructor

	// Event Manager Functions
	void Intialise(sf::RenderWindow& _mainWindow, sf::RenderWindow& _debugWindow); // Initialise the Event Manager
	void Process(cPlayer* _player); // Process Event Manager
};

