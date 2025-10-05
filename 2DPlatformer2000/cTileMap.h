/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cTileMap.h
 Description :   Declares the cTileMap Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class cTileMap {
private:
	sf::Texture m_TileMapTexture; // Tile Map Texture
	sf::Texture m_ErrorTexture; // Red Square Tile Texture (For Errors)
	int m_TileWidth; // Single Tile Width
	int m_TileHeight; // Single Tile Height
	int m_TileMapX; // Total Tiles on the x-axis
	int m_TileMapY; // Total Tiles on the y-axis
	int m_TileMax; // Total Number of Tiles
	bool m_HasLoadedTexture; // If a Tile Map Texture has been Loaded

	// Helper Functions
	bool AssertXY(int _x, int _y) const; // Ensures that X and Y values were given are valid (0-Index)

public:
	cTileMap(); // Default Constructor;
	cTileMap(std::string _path, int _tileSides); // Constructor given a Path and Tile Sides (Square Tiles)
	cTileMap(std::string _path, int _tileWidth, int _tileHeight); // Constructor given a Path and Tile Height and Width
	~cTileMap();

	// Tile Map Functions
	bool LoadTileMap(std::string _path, int _tileSides); // Load Tile Map given a Path and Tiles Sides (Square Tiles)
	bool LoadTileMap(std::string _path, int _tileWidth, int _tileHeight); // Load Tile Map given a Path and Tile Height and Width
	sf::IntRect GetTile(unsigned int _x, unsigned int _y) const; // Get the Tile from Tile Map given the X and Y (0-Index)
	sf::IntRect GetTile(unsigned int _n) const; // Get the n'th Tile from Tile Map given N (0-Index)

	// Getters
	const sf::Texture& GetTileMapTexture() const; // Returns the Tile Map Texture
	sf::Vector2i GetTileSize() const; // Returns the Size of the Tile
	sf::Vector2i GetTileMapSize() const; // Returns the Size of the Tile Map (Measured in Tiles)
	int GetTileMax() const; // Returns the Total number of Tiles
};

