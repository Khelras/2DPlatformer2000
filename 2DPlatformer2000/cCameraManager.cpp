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

void cCameraManager::Initialise(sf::RenderWindow& _mainWindow, sf::Vector2f _position) {
	// Main Window
	this->m_MainWindow = &_mainWindow;

	// Camera Dimensions
	int iCameraDimensionX = _mainWindow.getSize().x / 4; // Quarter of Window (4x Zoom)
	int iCameraDimensionY = _mainWindow.getSize().y / 4; // Quarter of Window (4x Zoom)
	sf::Vector2f CameraDimensions(iCameraDimensionX, iCameraDimensionY); 

	// Camera
	this->m_CameraView = sf::View(_position, CameraDimensions);
	this->m_CameraPosition = _position;

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