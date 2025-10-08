/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cLevelManager.h
 Description :   Declares the cLevelManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include <fstream>
#include <sstream>
#include "cPlayer.h"
#include "cJumpPad.h"
#include "cMovingPlatform.h"
#include "cSpike.h"
#include "cKey.h"
#include "cDoor.h"

class cLevelManager {
private: 
	// Actors
	cTileMap m_TileMap; // Tile Map
	cPlayer* m_Player; // Player Actor
	std::vector<cActor*> m_Actors; // Actors

	// Levels
	const std::string m_Level1 = "levels/level1.txt";
	const std::string m_Level2 = "levels/level2.txt";
	int m_CurrentLevel;
	const int m_TotalLevels = 2; // Only 2 Level
	bool m_HasLoadedLevel;

	// Win Message
	sf::Font m_WinFont;
	sf::Text* m_WinText;
	
	// Load Test Level
	void TestLevel(); // My Testing Grounds

public:
	cLevelManager(); // Constructor
	~cLevelManager(); // Destructor
	
	// Level Manager Functions
	void Process(GameSettings& _settings, float _deltaTime, sf::RenderWindow& _window); // Process Level Manager
	void LoadLevel(); // Load Level
	void RestartLevel(); // Restart Level
	void UnloadLevel(); // Unload Level
	void NextLevel(); // Next Level
	void RestartGame(); // Restart the Whole Game

	// Getters
	cPlayer* GetPlayer() const; // Returns a Pointer to the Player Actor
};

