/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cCameraManager.h
 Description :   Declares the cCameraManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include <SFML/Graphics.hpp>

class cCameraManager {
private:
	sf::RenderWindow* m_MainWindow; // Pointer to the Main Window
	sf::View m_CameraView; // Camera View
	sf::Vector2f m_CameraPosition; // Position of the Camera

public:
	cCameraManager(); // Constructor
	~cCameraManager(); // Destructor

	// Camera Functions
	void Initialise(sf::RenderWindow& _mainWindow, sf::Vector2f _position); // Initialise the Camera Manager
	void MoveCamera(sf::Vector2f _offset); // Moves the Camera given an Offset
	void UpdateCamera(); // Updates the Camera to the Window

	// Getters
	sf::View GetCameraView() const; // Returns a Pointer to Camera View
	sf::Vector2f GetCameraPosition() const; // Returns the Position of the Camera
};
