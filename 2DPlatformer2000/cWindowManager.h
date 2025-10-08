/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cWindowManager.h
 Description :   Declares the cWindowManager Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class cWindowManager {
private:
	// Windows
	sf::RenderWindow m_MainWindow; // Main Window
	sf::RenderWindow m_DebugWindow; // Debug Window

	// Default Font
	const std::string m_DefaultFont = "fonts/determination.ttf";

	// Tutorial Text
	sf::Font m_TutorialFont;
	sf::Text* m_TutorialText;

	// Debug Text
	sf::Font m_DebugFont;
	sf::Text* m_DebugText;

public:
	cWindowManager(); // Constructor
	~cWindowManager(); // Destructor

	// Window Manager Functions
	bool Process(); // Process Window Manager
	void ProcessTutorial(); // Process Window for Tutorial Screen
	void Clear(bool _onlyDebugWindow); // Clears the Window
	void Draw(bool _onlyDebugWindow); // Draw to Window
	void Display(bool _onlyDebugWindow); // Display the Window

	// Getters
	sf::RenderWindow& GetMainWindow(); // Returns a Reference to Main Window
	sf::RenderWindow* GetDebugWindow(); // Returns a Pointer to Debug Window
};

