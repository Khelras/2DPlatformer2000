/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cLevelManager.cpp
 Description :   Defines the cLevelManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cLevelManager.h"

void cLevelManager::TestLevel() {
	// Push Player
	this->m_Actors.push_back(this->m_Player);

	// Main Platform Solid
	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[1]->SetActorSprite(16, 8);
	this->m_Actors[1]->SetActorDefaultPosition(sf::Vector2f(0.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[2]->SetActorSprite(16, 8);
	this->m_Actors[2]->SetActorDefaultPosition(sf::Vector2f(16.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[3]->SetActorSprite(16, 8);
	this->m_Actors[3]->SetActorDefaultPosition(sf::Vector2f(-16.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[4]->SetActorSprite(16, 8);
	this->m_Actors[4]->SetActorDefaultPosition(sf::Vector2f(32.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[5]->SetActorSprite(16, 8);
	this->m_Actors[5]->SetActorDefaultPosition(sf::Vector2f(-32.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[6]->SetActorSprite(16, 8);
	this->m_Actors[6]->SetActorDefaultPosition(sf::Vector2f(48.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[7]->SetActorSprite(16, 8);
	this->m_Actors[7]->SetActorDefaultPosition(sf::Vector2f(-48.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[8]->SetActorSprite(17, 8);
	this->m_Actors[8]->SetActorDefaultPosition(sf::Vector2f(64.0f, 16.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[9]->SetActorSprite(15, 8);
	this->m_Actors[9]->SetActorDefaultPosition(sf::Vector2f(-64.0f, 16.0f));


	// Upper Platform Solid
	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[10]->SetActorSprite(16, 8);
	this->m_Actors[10]->SetActorDefaultPosition(sf::Vector2f(0.0f, -32.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[11]->SetActorSprite(17, 8);
	this->m_Actors[11]->SetActorDefaultPosition(sf::Vector2f(16.0f, -32.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[12]->SetActorSprite(15, 8);
	this->m_Actors[12]->SetActorDefaultPosition(sf::Vector2f(-16.0f, -32.0f));


	// Pushable Solid
	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID_PUSHABLE));
	this->m_Actors[13]->SetActorSprite(10);
	this->m_Actors[13]->SetActorDefaultPosition(sf::Vector2f(-16.0f, 0.0f));


	// Floating Platform Through
	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID_THROUGH));
	this->m_Actors[14]->SetActorSprite(4, 2);
	this->m_Actors[14]->SetActorDefaultPosition(sf::Vector2f(32.0f, -64.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID_THROUGH));
	this->m_Actors[15]->SetActorSprite(5, 2);
	this->m_Actors[15]->SetActorDefaultPosition(sf::Vector2f(48.0f, -64.0f));

	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID_THROUGH));
	this->m_Actors[16]->SetActorSprite(6, 2);
	this->m_Actors[16]->SetActorDefaultPosition(sf::Vector2f(64.0f, -64.0f));


	// Back to Main Platform Again...
	this->m_Actors.push_back(new cActor(&(this->m_TileMap), ActorType::SOLID));
	this->m_Actors[17]->SetActorSprite(18, 8);
	this->m_Actors[17]->SetActorDefaultPosition(sf::Vector2f(-80.0f, 0.0f));

	this->m_Actors.push_back(new cJumpPad(&(this->m_TileMap)));
	this->m_Actors[18]->SetActorDefaultPosition(sf::Vector2f(48.0f, 0.0f));


	// The Moving Platform
	this->m_Actors.push_back(new cMovingPlatform(&(this->m_TileMap)));
	this->m_Actors[19]->SetActorSprite(4, 7);
	this->m_Actors[19]->SetActorDefaultPosition(sf::Vector2f(-16.0f, -96.0f));

	this->m_Actors.push_back(new cMovingPlatform(&(this->m_TileMap)));
	this->m_Actors[20]->SetActorSprite(6, 7);
	this->m_Actors[20]->SetActorDefaultPosition(sf::Vector2f(0.0f, -96.0f));


	// Another Moving Platform
	this->m_Actors.push_back(new cMovingPlatform(&(this->m_TileMap)));
	this->m_Actors[21]->SetActorSprite(4, 7);
	this->m_Actors[21]->SetActorDefaultPosition(sf::Vector2f(-16.0f, 64.0f));

	this->m_Actors.push_back(new cMovingPlatform(&(this->m_TileMap)));
	this->m_Actors[22]->SetActorSprite(6, 7);
	this->m_Actors[22]->SetActorDefaultPosition(sf::Vector2f(0.0f, 64.0f));

	// Random Spike
	this->m_Actors.push_back(new cSpike(&(this->m_TileMap)));
	this->m_Actors[23]->SetActorDefaultPosition(sf::Vector2f(96.0f, 64.0f));

	// Key
	this->m_Actors.push_back(new cKey(&(this->m_TileMap)));
	this->m_Actors[24]->SetActorDefaultPosition(sf::Vector2f(96.0f, -64.0f));

	// Door
	this->m_Actors.push_back(new cDoor(&(this->m_TileMap)));
	this->m_Actors[25]->SetActorDefaultPosition(sf::Vector2f(0.0f, -48.0f));
}

cLevelManager::cLevelManager() {
	this->m_Player = nullptr;
	this->m_CurrentLevel = 1; // First Level
	this->m_HasLoadedLevel = false;
	this->LoadLevel(); // Load Level

	// Win Message Text
	if (this->m_WinFont.openFromFile("fonts/determination.ttf")) {
		// Font Loaded Successfully
		this->m_WinText = new sf::Text(this->m_WinFont);
		this->m_WinText->setCharacterSize(45); // Set Text Size to 45px
		this->m_WinText->setFillColor(sf::Color::White); // Set Text Color to White

		// Win Message String
		std::string sWinMessage =
			"You Won! :)";

		// Set the Win Text to the Win Message String
		this->m_WinText->setString(sWinMessage);
		this->m_WinText->setLetterSpacing(2.0);
	}
	else {
		// Loading Filaed
		this->m_WinText = nullptr;
	}
}

cLevelManager::~cLevelManager() {
	if (this->m_HasLoadedLevel == true) {
		// Delete Actors
		for (auto* Actor : this->m_Actors) {
			delete(Actor);
		}
	}
}

void cLevelManager::Process(GameSettings& _settings, float _deltaTime, sf::RenderWindow& _window) {
	// If a Level has not Loaded
	if (this->m_HasLoadedLevel == false) {
		// Check if Player Won
		if (this->m_CurrentLevel > this->m_TotalLevels) {
			// Ensure Win Text Exists
			if (this->m_WinText != nullptr) {
				// Draw the Debug Text
				float fTextCenterX = ((_window.getSize().x / 3) - this->m_WinText->getLocalBounds().size.x) / 2.0f;
				float fTextCenterY = ((_window.getSize().y / 3) - this->m_WinText->getLocalBounds().size.y) / 2.0f;
				this->m_WinText->setPosition(sf::Vector2f(fTextCenterX, fTextCenterY - 20.0f));
				_window.draw(*(this->m_WinText));
			}
		}

		// Stop Here
		return;
	};

	// Player Lost a Life
	if (this->m_Player->GetPlayerDied() == true) {
		// Reset Player Death
		this->m_Player->SetPlayerDied(false);

		// Player Lost all Lives (Restart Game)
		if (_settings.m_PlayerLives == 0) {
			// Reset Lives
			_settings.ResetPlayerLives();

			// Restart Game
			this->RestartGame();
			return;
		}
		else {
			// Restart Level
			this->RestartLevel();
		}
	}

	// Update Actors
	for (auto* Actor : this->m_Actors) {
		Actor->UpdateActor(_settings, _deltaTime, this->m_Actors);
	}

	// Draw Actors
	for (auto* Actor : this->m_Actors) {
		Actor->DrawActor(_window);
	}

	// Player Completed the Level
	if (this->m_Player->GetPlayerCompletedLevel() == true) {
		// Go to Next Level
		this->NextLevel();
	}
}

void cLevelManager::LoadLevel() {
	// First Unload the Level if there is a Level that Loaded
	if (this->m_HasLoadedLevel == true) this->UnloadLevel();

	// What Level to Load
	std::string sFilePath;
	switch (this->m_CurrentLevel) {
		case 1: sFilePath = this->m_Level1; break; // Level One
		case 2: sFilePath = this->m_Level2; break; // Level Two
		default: sFilePath = this->m_Level1; break; // Default to the Level One
	}

	// Open File
	std::ifstream LevelFile(sFilePath);

	// Determine Width and Height from the File
	int iLevelWidth = 0;
	int iLevelHeight = 0;
	LevelFile >> iLevelWidth >> iLevelHeight;
	this->m_Actors.reserve(iLevelWidth * iLevelHeight); // Reserve Memory

	// First Read the Sprite Grid
	std::vector<std::vector<int>> SpritesGrid(iLevelHeight, std::vector<int>(iLevelWidth, 0));
	for (int y = 0; y < iLevelHeight; y++) { // Y-axis
		for (int x = 0; x < iLevelWidth; x++) { // X-axis
			LevelFile >> SpritesGrid[y][x];
		}
	}

	// Then Read the Actor Type Grid
	std::vector<std::vector<int>> ActorTypesGrid(iLevelHeight, std::vector<int>(iLevelWidth, 0));
	for (int y = 0; y < iLevelHeight; y++) { // Y-axis
		for (int x = 0; x < iLevelWidth; x++) { // X-axis
			LevelFile >> ActorTypesGrid[y][x];
		}
	}

	// Then Construct the Actors
	for (int y = 0; y < iLevelHeight; y++) { // Y-axis
		for (int x = 0; x < iLevelWidth; x++) { // X-axis
			// Top of Level Border
			if (y == 0) {
				sf::Vector2f BorderPosition(
					static_cast<float>(x) * this->m_TileMap.GetTileSize().x,
					(static_cast<float>(y) * this->m_TileMap.GetTileSize().y) - this->m_TileMap.GetTileSize().y
				);

				// Add Border
				cActor* Actor = new cActor(&(this->m_TileMap), ActorType::SOLID);
				Actor->SetActorSprite(0);
				Actor->SetActorDefaultPosition(BorderPosition);
				this->m_Actors.push_back(Actor);
			}
			// Bottom of Level Border
			else if (y == iLevelHeight - 1) {
				sf::Vector2f BorderPosition(
					static_cast<float>(x) * this->m_TileMap.GetTileSize().x,
					(static_cast<float>(y) * this->m_TileMap.GetTileSize().y) + this->m_TileMap.GetTileSize().y
				);

				// Add Spike
				cSpike* Actor = new cSpike(&(this->m_TileMap));
				Actor->SetActorSprite(0);
				Actor->SetActorDefaultPosition(BorderPosition);
				this->m_Actors.push_back(Actor);
			}

			// Very Left of Row Border
			if (x == 0) {
				sf::Vector2f BorderPosition(
					(static_cast<float>(x) * this->m_TileMap.GetTileSize().x) - this->m_TileMap.GetTileSize().x,
					static_cast<float>(y) * this->m_TileMap.GetTileSize().y
				);

				// Add Border
				cActor* Actor = new cActor(&(this->m_TileMap), ActorType::SOLID);
				Actor->SetActorSprite(0);
				Actor->SetActorDefaultPosition(BorderPosition);
				this->m_Actors.push_back(Actor);
			}
			// Very Right of Row Border
			else if (x == iLevelWidth - 1) {
				sf::Vector2f BorderPosition(
					(static_cast<float>(x) * this->m_TileMap.GetTileSize().x) + this->m_TileMap.GetTileSize().x,
					static_cast<float>(y) * this->m_TileMap.GetTileSize().y
				);

				// Add Border
				cActor* Actor = new cActor(&(this->m_TileMap), ActorType::SOLID);
				Actor->SetActorSprite(0);
				Actor->SetActorDefaultPosition(BorderPosition);
				this->m_Actors.push_back(Actor);
			}

			// Actor Construction
			int iSpriteTile = SpritesGrid[y][x]; // Sprite Tile
			int iActorType = ActorTypesGrid[y][x]; // Actor Type

			// Skip Empty Tiles
			if (iSpriteTile == 0 && iActorType == 0) continue;

			// Get the Position based on (x, y) and the Tile Size
			sf::Vector2f ActorPosition(
				static_cast<float>(x) * this->m_TileMap.GetTileSize().x,
				static_cast<float>(y) * this->m_TileMap.GetTileSize().y
			);

			// Construct the Actor based on Actor Type
			ActorType Type = static_cast<ActorType>(iActorType);
			switch (Type) {
				// Visual Actors
				case (ActorType::NONE): {
					cActor* Actor = new cActor(&(this->m_TileMap), Type);
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorOpacity(180);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;

				// Moving Platform
				case (ActorType::SOLID_THROUGH_MOVING): {
					cMovingPlatform* Actor = new cMovingPlatform(&(this->m_TileMap));
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;

				// Jump Pad
				case (ActorType::JUMP_PAD): {
					cJumpPad* Actor = new cJumpPad(&(this->m_TileMap));
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;

				// Spike
				case (ActorType::SPIKE): {
					cSpike* Actor = new cSpike(&(this->m_TileMap));
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;

				// Key
				case (ActorType::KEY): {
					cKey* Actor = new cKey(&(this->m_TileMap));
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;

				// Door
				case (ActorType::DOOR): {
					cDoor* Actor = new cDoor(&(this->m_TileMap));
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;

				// Player
				case (ActorType::PLAYER): {
					this->m_Player = new cPlayer(&(this->m_TileMap));
					this->m_Player->SetActorSprite(iSpriteTile);
					this->m_Player->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(this->m_Player);
				} break;

				// Other Actor Types
				default: {
					cActor* Actor = new cActor(&(this->m_TileMap), Type);
					Actor->SetActorSprite(iSpriteTile);
					Actor->SetActorDefaultPosition(ActorPosition);
					this->m_Actors.push_back(Actor);
				} break;
			}
		}
	}

	// Update Had Loaded Level
	this->m_HasLoadedLevel = true;
}

void cLevelManager::RestartLevel() {
	// Reset Actor Position
	for (auto* Actor : this->m_Actors) {
		Actor->ResetActor();
	}
}

void cLevelManager::UnloadLevel() {
	// Delete Actors
	for (auto* Actor : this->m_Actors) {
		delete(Actor);
	}

	// Player Point to nullptr
	this->m_Player = nullptr;

	// Clear Actors Vector
	this->m_Actors.clear();

	// Update Had Loaded Level
	this->m_HasLoadedLevel = false;
}

void cLevelManager::NextLevel() {
	// Reached the End of Levels
	if (this->m_CurrentLevel >= this->m_TotalLevels) {
		this->m_CurrentLevel++; // Indicates Player Won
		this->UnloadLevel();
	}
	else {
		this->m_CurrentLevel++;
		this->LoadLevel();
	}
}

void cLevelManager::RestartGame() {
	this->m_CurrentLevel = 1;
	this->LoadLevel();
}

cPlayer* cLevelManager::GetPlayer() const {
	return this->m_Player;
}
