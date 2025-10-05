/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cAnimation.h
 Description :   Declares the cLevel Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#pragma once
#include "cTileMap.h"

// Play Modes
enum class PlaybackType {
	NORMAL_ONCE, // Play Once
	NORMAL_LOOP, // Loops Start to End
	REVERSE_ONCE, // Play End to Start (Reverse) Once
	REVERSE_LOOP, // Loops End to Start (Reverse)
	PING_PONG_ONCE, // Plays Start to End to Start (Ping Pong) Once
	PING_PONG_LOOP, // Loops Start to End to Start (Ping Pong)
	REVERSE_PING_PONG_ONCE, // Plays from End to Start to End (Reverse Ping Pong) Once
	REVERSE_PING_PONG_LOOP, // Loops from End to Start to End (Reverse Ping Pong)
};

class cAnimation {
private:
	// Animation Attributes
	PlaybackType m_PlaybackType; // Play Mode
	bool m_IsPlaying; // Animation is Playing or not Playing?
	cTileMap* m_TileMap;
	sf::Sprite* m_Sprite;

	// Animation Playback
	bool m_IsReverse; // If the Playback is Reverse
	int m_Start; // Start Tile-Index
	int m_End; // End Tile-Index
	int m_Current; // Current Tile-Index
	bool m_HasPlayedPing; // Done the "Ping" Section of the Ping-Pong Playback

	// Animation Timings
	float m_SpeedScalar; // Speed Scalar
	float m_FramePerSecond; // How many Frames are Played per Second (Second / Frame)
	float m_TimeAccumulator; // Accumulates Delta Time for Frame Timinings

public:
	cAnimation(PlaybackType _playbackType, cTileMap& _tileMap, sf::Sprite& _sprite, int _start, int _end); // Constructor
	~cAnimation(); // Destructor

	// Animation Functions
	void UpdateAnimation(float _deltaTime); // Update Animation given Delta Time and a Sprite
	void UpdatePlaybackNormal(bool _isLoop); // Update Animation for Normal Playback
	void UpdatePlaybackPingPong(bool _isLoop); // Update Animation for Ping-Pong Playback

	// Playback Controls
	void PlayAnimation(); // Play Animation
	void PlayAnimationFromStart(); // Play Animation from the Start
	void PauseAnimation(); // Pause Animation
	void ResetAnimation(); // Reset Animation

	// Setters
	void SetSpeedScalar(float _speed); // Set the Speed Scalar
	void SetFramePerSecond(float _fps); // Set the Frame Per Second (Second / Frame)
};

