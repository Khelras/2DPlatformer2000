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

// REMOVE LATER
#include "cPlayer.h"
#include "cJumpPad.h"
#include "cMovingPlatform.h"

cGameManager::cGameManager() {
	// Player Actor
	this->m_Player = new cPlayer();
	this->m_Actors.push_back(this->m_Player);

	// Managers
	this->m_EventManager.Intialise(this->m_WindowManager.GetMainWindow(), this->m_WindowManager.GetDebugWindow());
	this->m_CameraManager.Initialise(this->m_WindowManager.GetMainWindow(), sf::Vector2f(0.0f, 0.0f));
	this->m_UserInterfaceManager.Initialise(&(this->m_TileMap));

	// Other
	this->m_DeltaTime = 0;
}

cGameManager::~cGameManager() {
	for (auto* Actor : this->m_Actors) {
		delete(Actor);
	}
}

void cGameManager::Process() {
	// Clock (for Delta Time)
	sf::Clock Clock;

	// Main Platform Solid
	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[1]->SetActorSprite(16, 8);
	this->m_Actors[1]->SetActorPosition(sf::Vector2f(0.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[2]->SetActorSprite(16, 8);
	this->m_Actors[2]->SetActorPosition(sf::Vector2f(16.0f, 16.0f));
	
	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[3]->SetActorSprite(16, 8);
	this->m_Actors[3]->SetActorPosition(sf::Vector2f(-16.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[4]->SetActorSprite(16, 8);
	this->m_Actors[4]->SetActorPosition(sf::Vector2f(32.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[5]->SetActorSprite(16, 8);
	this->m_Actors[5]->SetActorPosition(sf::Vector2f(-32.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[6]->SetActorSprite(16, 8);
	this->m_Actors[6]->SetActorPosition(sf::Vector2f(48.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[7]->SetActorSprite(16, 8);
	this->m_Actors[7]->SetActorPosition(sf::Vector2f(-48.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[8]->SetActorSprite(17, 8);
	this->m_Actors[8]->SetActorPosition(sf::Vector2f(64.0f, 16.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[9]->SetActorSprite(15, 8);
	this->m_Actors[9]->SetActorPosition(sf::Vector2f(-64.0f, 16.0f));

	
	// Upper Platform Solid
	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[10]->SetActorSprite(16, 8);
	this->m_Actors[10]->SetActorPosition(sf::Vector2f(0.0f, -32.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[11]->SetActorSprite(17, 8);
	this->m_Actors[11]->SetActorPosition(sf::Vector2f(16.0f, -32.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[12]->SetActorSprite(15, 8);
	this->m_Actors[12]->SetActorPosition(sf::Vector2f(-16.0f, -32.0f));


	// Pushable Solid
	this->m_Actors.push_back(new cActor(ActorType::SOLID_PUSHABLE));
	this->m_Actors[13]->SetActorSprite(10);
	this->m_Actors[13]->SetActorPosition(sf::Vector2f(-16.0f, 0.0f));


	// Floating Platform Through
	this->m_Actors.push_back(new cActor(ActorType::SOLID_THROUGH));
	this->m_Actors[14]->SetActorSprite(4, 2);
	this->m_Actors[14]->SetActorPosition(sf::Vector2f(32.0f, -64.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID_THROUGH));
	this->m_Actors[15]->SetActorSprite(5, 2);
	this->m_Actors[15]->SetActorPosition(sf::Vector2f(48.0f, -64.0f));

	this->m_Actors.push_back(new cActor(ActorType::SOLID_THROUGH));
	this->m_Actors[16]->SetActorSprite(6, 2);
	this->m_Actors[16]->SetActorPosition(sf::Vector2f(64.0f, -64.0f));


	// Back to Main Platform Again...
	this->m_Actors.push_back(new cActor(ActorType::SOLID));
	this->m_Actors[17]->SetActorSprite(18, 8);
	this->m_Actors[17]->SetActorPosition(sf::Vector2f(-80.0f, 0.0f));

	this->m_Actors.push_back(new cJumpPad());
	this->m_Actors[18]->SetActorSprite(3, 8);
	this->m_Actors[18]->SetActorPosition(sf::Vector2f(48.0f, 0.0f));

	
	// The Moving Platform
	this->m_Actors.push_back(new cMovingPlatform());
	this->m_Actors[19]->SetActorSprite(4, 7);
	this->m_Actors[19]->SetActorPosition(sf::Vector2f(-16.0f, -96.0f));

	this->m_Actors.push_back(new cMovingPlatform());
	this->m_Actors[20]->SetActorSprite(6, 7);
	this->m_Actors[20]->SetActorPosition(sf::Vector2f(0.0f, -96.0f));


	// Another Moving Platform
	this->m_Actors.push_back(new cMovingPlatform());
	this->m_Actors[21]->SetActorSprite(4, 7);
	this->m_Actors[21]->SetActorPosition(sf::Vector2f(-16.0f, 64.0f));

	this->m_Actors.push_back(new cMovingPlatform());
	this->m_Actors[22]->SetActorSprite(6, 7);
	this->m_Actors[22]->SetActorPosition(sf::Vector2f(0.0f, 64.0f));

	// Starts Window Manager (Main Game Loop)
	while (this->m_WindowManager.Process()) {
		// Delta Time
		this->m_DeltaTime = Clock.restart().asSeconds();

		// User Interface Processing
		this->m_UserInterfaceManager.Process(this->m_Player);

		// Event Processing
		this->m_EventManager.Process(this->m_Player);

		// Player
		this->PlayerControls(); // Player Controls

		// Update Actors
		for (cActor* Actor : this->m_Actors) {
			Actor->UpdateActor(this->m_DeltaTime, this->m_Actors);
		}

		// Clear
		this->m_WindowManager.Clear();

		// Draw Actors
		for (cActor* Actor : this->m_Actors) {
			Actor->DrawActor(this->m_WindowManager.GetMainWindow());
		}

		// Draw User Interfaces
		this->m_UserInterfaceManager.DrawUI(this->m_WindowManager.GetMainWindow());

		// Display
		this->m_WindowManager.Display();
	}
}

void cGameManager::PlayerControls() {
	// Left Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		this->m_Player->MovePlayer(MovementDirection::LEFT);
	}

	// Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		this->m_Player->MovePlayer(MovementDirection::RIGHT);
	}

}
