/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cTileMap.cpp
 Description :   Defines the cTileMap Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cTileMap.h"

bool cTileMap::AssertXY(int _x, int _y) const {
	// First check if the given X and Y are not negative
	if (_x >= 0 && _y >= 0) {
		// Then check if the given X and Y are within the Tile Map X and Y
		if (_x < this->m_TileMapX && _y < this->m_TileMapY) {
			// Return true (Assertion successful)
			return true;
		}
	}

	// Return false otherwise (Assertion failed)
	return false;
}

cTileMap::cTileMap() {
	// Loda the Default Tile Map
	this->LoadTileMap("tilemaps/default.png", 16);

	// Error Tile Texture
	sf::Image RedImage({ 16, 16 }, sf::Color::Red); // Creates a Red 16x16 Image
	if (this->m_ErrorTexture.loadFromImage(RedImage)); // Loads the Texture from the Red 16x16 Image
}

cTileMap::cTileMap(std::string _path, int _tileSides) {
	// Load Tile Map
	this->LoadTileMap(_path, _tileSides, _tileSides);

	// Error Tile Texture
	sf::Image RedImage({ 16, 16 }, sf::Color::Red); // Creates a Red 16x16 Image
	if (this->m_ErrorTexture.loadFromImage(RedImage)); // Loads the Texture from the Red 16x16 Image
}

cTileMap::cTileMap(std::string _path, int _tileWidth, int _tileHeight) {
	// Load Tile Map
	this->LoadTileMap(_path, _tileWidth, _tileHeight);

	// Error Tile Texture
	sf::Image RedImage({ 16, 16 }, sf::Color::Red); // Creates a Red 16x16 Image
	if (this->m_ErrorTexture.loadFromImage(RedImage)); // Loads the Texture from the Red 16x16 Image
}

cTileMap::~cTileMap() {
}

bool cTileMap::LoadTileMap(std::string _path, int _tileSides) {
	// Loading was Successful
	if (this->LoadTileMap(_path, _tileSides, _tileSides) == true) {
		return true;
	}

	// Returns false otherwise (File Loading Failed)
	return false;
}

bool cTileMap::LoadTileMap(std::string _path, int _tileWidth, int _tileHeight) {
	// Validate Tile Map Texture successfully loads from File Path
	if (this->m_TileMapTexture.loadFromFile(_path)) {
		// Tile Map Attributes
		this->m_TileWidth = _tileWidth;
		this->m_TileHeight = _tileHeight;
		this->m_TileMapX = this->m_TileMapTexture.getSize().x / this->m_TileWidth;
		this->m_TileMapY = this->m_TileMapTexture.getSize().y / this->m_TileHeight;
		this->m_TileMax = m_TileMapX * m_TileMapY;

		// Loading Successful
		this->m_HasLoadedTexture = true;
		return true;
	}

	// Returns false otherwise (File Loading Failed)
	return false;
}

sf::IntRect cTileMap::GetTile(unsigned int _x, unsigned int _y) const {
	// First check if a Tile Map has loaded and the given X and Y values are valid
	if (this->m_HasLoadedTexture && this->AssertXY(_x, _y)) {
		// Return a FloatRect Section on the Tile Map
		return sf::IntRect(
			sf::Vector2i( // Position
				_x * this->m_TileWidth,
				_y * this->m_TileHeight
			),
			sf::Vector2i( // Size
				this->m_TileWidth,
				this->m_TileHeight
			)
		);
	}
	// Otherwise, the Error Texture has is loaded
	else {
		// Return the Default
		return sf::IntRect(
			sf::Vector2i( // Position
				0, 0
			),
			sf::Vector2i( // Size
				this->m_TileWidth,
				this->m_TileHeight
			)
		);
	}
}

sf::IntRect cTileMap::GetTile(unsigned int _n) const {
	// First check if a Tile Map has loaded and the given n value is valid
	if (this->m_HasLoadedTexture && _n < this->m_TileMax) {
		// Convert to X and Y
		unsigned int iTileX = _n % this->m_TileMapX;
		unsigned int iTileY = _n / this->m_TileMapX;

		// Return using the X and Y GetTile() function
		return this->GetTile(iTileX, iTileY);
	}
}

const sf::Texture& cTileMap::GetTileMapTexture() const {
	// If a Tile Map has been Loaded
	if (this->m_HasLoadedTexture == true) {
		return this->m_TileMapTexture;
	}

	// Otherwise, Return the Error Texture
	return this->m_ErrorTexture;
}

sf::Vector2i cTileMap::GetTileSize() const {
	return sf::Vector2i(this->m_TileWidth, this->m_TileHeight);
}

sf::Vector2i cTileMap::GetTileMapSize() const {
	return sf::Vector2i(this->m_TileMapX, this->m_TileMapY);
}

int cTileMap::GetTileMax() const {
	return this->m_TileMax;
}
