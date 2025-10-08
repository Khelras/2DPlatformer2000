/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cCameraManager.cpp
 Description :   Defines the cCameraManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cCameraManager.h"

cCameraManager::cCameraManager() {
	this->m_MainWindow = nullptr;
}

cCameraManager::~cCameraManager() {
}

void cCameraManager::Initialise(sf::RenderWindow& _mainWindow) {
	// Main Window
	this->m_MainWindow = &_mainWindow;

	// Camera Dimensions
	int iCameraDimensionX = _mainWindow.getSize().x / 3; // Third of Window (3x Zoom)
	int iCameraDimensionY = _mainWindow.getSize().y / 3; // Third of Window (3x Zoom)
	sf::Vector2f CameraDimensions(iCameraDimensionX, iCameraDimensionY); 

	// Offset Camera Position
	sf::Vector2f Offset(iCameraDimensionX / 2, iCameraDimensionY / 2);

	// Camera
	this->m_CameraView = sf::View(sf::Vector2f(0.0f, 0.0f), CameraDimensions);
	this->m_CameraView.move(Offset);
	this->m_CameraPosition = sf::Vector2f(0.0f, 0.0f) + Offset;

	// Update Camera to Window
	this->UpdateCamera();
}

void cCameraManager::MoveCamera(sf::Vector2f _offset) {
	// Moving the Camera Position by a given Offset
	this->m_CameraPosition += _offset;
	this->m_CameraView.move(_offset);

	// Updates the Camera
	this->UpdateCamera();
}

void cCameraManager::UpdateCamera() {
	// Updates the Camera to the Window
	this->m_MainWindow->setView(this->m_CameraView);
}

sf::View cCameraManager::GetCameraView() const {
	// Returns a Pointer to the Camera View
	return this->m_CameraView;
}

sf::Vector2f cCameraManager::GetCameraPosition() const {
	// Returns the Position of the Camera
	return this->m_CameraPosition;
}