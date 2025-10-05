/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cWindowManager.cpp
 Description :   Defines the cWindowManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cWindowManager.h"

cWindowManager::cWindowManager() {
    // Main Window
    this->m_MainWindow.create(sf::VideoMode({ 1200, 1000 }), "Epic 2D Platformer 2000!");
    this->m_MainWindow.setFramerateLimit(60); // Sets the Framerate Limit to 60fps for the Main Window
    this->m_MainWindow.setKeyRepeatEnabled(false); // Prevents repeats on KeyPressed Event

    // Debug Window
    this->m_DebugWindow.create(sf::VideoMode({ 600, 600 }), "Epic Debugger 2000!");
    this->m_DebugWindow.setFramerateLimit(60); // Sets the Framerate Limit to 60fps for the Debug Window
    this->m_DebugWindow.close();
}

cWindowManager::~cWindowManager() {
}

bool cWindowManager::Process() {
    // Main Window
    if (this->m_MainWindow.isOpen()) {
        return true;
    }

    // Return false otherwise
    return false;
}

void cWindowManager::Clear() {
    // Main Window
    if (this->m_MainWindow.isOpen()) {
        this->m_MainWindow.clear();
    }

    // Debug Window
    if (this->m_DebugWindow.isOpen()) {
        this->m_DebugWindow.clear();
    }
}

void cWindowManager::Draw() {
    // Main Window
    if (this->m_MainWindow.isOpen()) {
        
    }

    // Debug Window
    if (this->m_DebugWindow.isOpen()) {
        
    }
}

void cWindowManager::Display() {
    // Main Window
    if (this->m_MainWindow.isOpen()) {
        this->m_MainWindow.display();
    }

    // Debug Window
    if (this->m_DebugWindow.isOpen()) {
        this->m_DebugWindow.display();
    }
}

sf::RenderWindow& cWindowManager::GetMainWindow() {
    return this->m_MainWindow;
}

sf::RenderWindow& cWindowManager::GetDebugWindow() {
    return this->m_DebugWindow;
}