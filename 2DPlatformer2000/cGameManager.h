/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cGameManager.h
 Description :   Declares the cGameManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cWindowManager.h"
#include "cEventManager.h"
#include "cCameraManager.h"
#include "cUserInterfaceManager.h"
#include "cTileMap.h"

class cGameManager {
private:
	// Tile Map
	cTileMap m_TileMap;

	// Actors
	std::vector<cActor*> m_Actors;
	cPlayer* m_Player;
	
	// Managers
	cWindowManager m_WindowManager;
	cEventManager m_EventManager;
	cCameraManager m_CameraManager;
	cUserInterfaceManager m_UserInterfaceManager;

	float m_DeltaTime;

public:
	cGameManager(); // Constructor
	~cGameManager(); // Destructor

	// Actor Functions
	void Process();
	void PlayerControls();
};

