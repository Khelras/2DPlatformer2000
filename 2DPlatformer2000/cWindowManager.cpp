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
    this->m_MainWindow.create(sf::VideoMode({ (20 * 16) * 3, (18 * 16) * 3}), "Epic 2D Platformer 2000!"); // 20 x 18 (Tiles)
    this->m_MainWindow.setFramerateLimit(60); // Sets the Framerate Limit to 60fps for the Main Window
    this->m_MainWindow.setKeyRepeatEnabled(false); // Prevents repeats on KeyPressed Event

    // Debug Window
    this->m_DebugWindow.create(sf::VideoMode({ 600, 600 }), "Epic Debugger 2000!");
    this->m_DebugWindow.close();

    // Debug Text
    if (this->m_DebugFont.openFromFile("fonts/determination.ttf")) {
        // Font Loaded Successfully
        this->m_DebugText = new sf::Text(this->m_DebugFont);
        this->m_DebugText->setCharacterSize(29); // Set Text Size to 29px
        this->m_DebugText->setFillColor(sf::Color::White); // Set Text Color to White

        // Game Settings String
        std::string sGameSettings =
            "Game Settings:\n"
            "[G] Actor Gravity\n"
            "[S] Actor Speed Scalar\n"
            "[L] Player Lives\n"
            "[M] Player Move Speed\n"
            "[J] Player Jump Height\n"
            "[I] Player Infinite Double Jump\n"
            "[P] Jump Pad Height\n"
            "[SHIFT + ...] Inverts\n"
            "\n"
            "Reset:\n"
            "[R] Reset Game Settings to Default\n"
            "[SHIFT + R] Restart the Whole Game\n"
            "\n"
            "Press [ESC] to Save Changes!";

        // Set the Debug Text to the Game Settings String
        this->m_DebugText->setString(sGameSettings);
    }
    else {
        // Loading Failed
        this->m_DebugText = nullptr;
    }
}

cWindowManager::~cWindowManager() {
    delete(this->m_DebugText);
}

bool cWindowManager::Process() {
    // Main Window
    if (this->m_MainWindow.isOpen()) {
        return true;
    }

    // Return false otherwise
    return false;
}

void cWindowManager::Clear(bool _onlyDebugWindow) {
    // Main Window
    if (_onlyDebugWindow == false) {
        if (this->m_MainWindow.isOpen()) {
            this->m_MainWindow.clear(sf::Color(20, 20, 20));
        }
    }
    // Debug Window
    else if (_onlyDebugWindow == true) {
        if (this->m_DebugWindow.isOpen()) {
            this->m_DebugWindow.clear();
        }
    }
}

void cWindowManager::Draw(bool _onlyDebugWindow) {
    // Main Window
    if (_onlyDebugWindow == false) {
        if (this->m_MainWindow.isOpen()) {

        }
    }
    // Debug Window
    else if (_onlyDebugWindow == true) {
        if (this->m_DebugWindow.isOpen()) {
            // Ensure Debug Text Exists
            if (this->m_DebugText != nullptr) {
                // Draw the Debug Text
                float fTextCenterX = (this->m_DebugWindow.getSize().x - this->m_DebugText->getLocalBounds().size.x) / 2.0f;
                float fTextCenterY = (this->m_DebugWindow.getSize().y - this->m_DebugText->getLocalBounds().size.y) / 2.0f;
                this->m_DebugText->setPosition(sf::Vector2f(fTextCenterX, fTextCenterY));
                this->m_DebugWindow.draw(*(this->m_DebugText));
            }
        }
    }
}

void cWindowManager::Display(bool _onlyDebugWindow) {
    // Main Window
    if (_onlyDebugWindow == false) {
        if (this->m_MainWindow.isOpen()) {
            this->m_MainWindow.display();
        }
    }
    // Debug Window
    else if (_onlyDebugWindow == true) {
        if (this->m_DebugWindow.isOpen()) {
            this->m_DebugWindow.display();
        }
    }
}

sf::RenderWindow& cWindowManager::GetMainWindow() {
    return this->m_MainWindow;
}

sf::RenderWindow* cWindowManager::GetDebugWindow() {
    return &(this->m_DebugWindow);
}