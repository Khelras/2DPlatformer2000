/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c) 2025 Media Design School
 File Name   :   cAnimation.cpp
 Description :   Defines the cLevel Class Properties and Functions
 Author      :   Angelo Joseph Arawiran Bohol
 Mail        :   angelo.bohol@mds.ac.nz
 ***********************************************************************/

#include "cAnimation.h"

cAnimation::cAnimation(PlaybackType _playbackType, cTileMap& _tileMap, sf::Sprite& _sprite, int _start, int _end) {
	// Animation Attributes
	this->m_PlaybackType = _playbackType;
	this->m_IsPlaying = false; // Default to Paused State
	this->m_TileMap = &_tileMap;
	this->m_Sprite = &_sprite;

	// Reverse Boolean
	this->m_IsReverse = (
		_playbackType == PlaybackType::REVERSE_ONCE || 
		_playbackType == PlaybackType::REVERSE_LOOP ||
		_playbackType == PlaybackType::REVERSE_PING_PONG_ONCE ||
		_playbackType == PlaybackType::REVERSE_PING_PONG_LOOP
	);

	// Animation Playback (Values are based on Playback Type)
	this->m_Start = this->m_IsReverse ? _end : _start;
	this->m_End = this->m_IsReverse ? _start : _end;
	this->m_Current = this->m_IsReverse ? _end : _start;
	this->m_HasPlayedPing = false; // Default to false

	// Animation Timings
	this->m_SpeedScalar = 1.0f; // Default to 1x Speed
	this->m_FramePerSecond = 1.0f / 12.0f; // Default to 12 FPS
	this->m_TimeAccumulator = 0.0f; // Default to 0
}

cAnimation::~cAnimation() {
}

void cAnimation::UpdateAnimation(float _deltaTime) {
	// Update if Animation is Playing
	if (this->m_IsPlaying == false) return;

	// Update Accumulator
	this->m_TimeAccumulator += _deltaTime * this->m_SpeedScalar;
	
	// Animation
	while (this->m_TimeAccumulator >= this->m_FramePerSecond) {
		this->m_TimeAccumulator -= this->m_FramePerSecond;

		switch (this->m_PlaybackType) {
			// Normal Playback Once
			case(PlaybackType::NORMAL_ONCE): {
				this->UpdatePlaybackNormal(false);
			} break;

			// Normal Playback Once
			case(PlaybackType::NORMAL_LOOP): {
				this->UpdatePlaybackNormal(true);
			} break;

			// Reverse Playback Once
			case(PlaybackType::REVERSE_ONCE): {
				this->UpdatePlaybackNormal(false);
			} break;

			// Reverse Playback Loop
			case(PlaybackType::REVERSE_LOOP): {
				this->UpdatePlaybackNormal(true);
			} break;

			// Ping Pong Playback Once
			case(PlaybackType::PING_PONG_ONCE): {
				this->UpdatePlaybackPingPong(false);
			} break;

			// Ping Pong Playback Loop
			case(PlaybackType::PING_PONG_LOOP): {
				this->UpdatePlaybackPingPong(true);
			} break;

			// Reverse Ping Pong Playback Once
			case(PlaybackType::REVERSE_PING_PONG_ONCE): {
				this->UpdatePlaybackPingPong(false);
			} break;

			// Reverse Ping Pong Playback Loop
			case(PlaybackType::REVERSE_PING_PONG_LOOP): {
				this->UpdatePlaybackPingPong(true);
			} break;
		}
	}
}

void cAnimation::UpdatePlaybackNormal(bool _isLoop) {
	// Set Texture Rect of Sprite
	this->m_Sprite->setTextureRect(this->m_TileMap->GetTile(this->m_Current));

	// If this is the Last Frame in the Animation
	if (this->m_Current == this->m_End) {
		// If no Loop, then Stop Playback
		if (_isLoop == false) this->m_IsPlaying = false;

		// Animation Done
		this->m_Current = this->m_Start;
		return;
	}

	// Progress Frame Afterwards 
	int iPlaybackDirection = this->m_IsReverse ? -1 : 1;
	this->m_Current += iPlaybackDirection;
}

void cAnimation::UpdatePlaybackPingPong(bool _isLoop) {
	// Set Texture Rect of Sprite
	this->m_Sprite->setTextureRect(this->m_TileMap->GetTile(this->m_Current));

	// The "Ping" Section of the Ping-Pong Playback
	if (this->m_HasPlayedPing == false) {
		if (this->m_Current == this->m_End) {
			this->m_HasPlayedPing = true;
		}
	}
	// The "Pong" Section of the Ping-Pong Playback
	else if (this->m_HasPlayedPing == true) {
		if (this->m_Current == this->m_Start) {
			// If no Loop, then Stop Playback
			if (_isLoop == false) this->m_IsPlaying = false;

			// Animation Done
			this->m_HasPlayedPing = false;
			this->m_Current = this->m_Start;
			return;
		}
	}

	// Progress Frame Afterwards 
	int iPingOrPong = this->m_HasPlayedPing ? -1 : 1; // -1 For Pong, 1 for Ping
	int iPlaybackDirection = this->m_IsReverse ? -1 : 1; // Reverse
	this->m_Current += iPingOrPong * iPlaybackDirection;
}

void cAnimation::PlayAnimation() {
	this->m_IsPlaying = true;
}

void cAnimation::PlayAnimationFromStart() {
	// Reset Playback Values
	this->m_Current = this->m_IsReverse ? this->m_End : this->m_Start;
	this->m_HasPlayedPing = false; // Default to false

	// Start Playing
	this->m_IsPlaying = true;
}

void cAnimation::PauseAnimation() {
	this->m_IsPlaying = false;
}

void cAnimation::ResetAnimation() {
	// Reset Playback Values
	this->m_Current = this->m_IsReverse ? this->m_End : this->m_Start;
	this->m_HasPlayedPing = false; // Default to false

	// Stop Playing
	this->m_IsPlaying = false;
}

void cAnimation::SetSpeedScalar(float _speed) {
	this->m_SpeedScalar = _speed;
}

void cAnimation::SetFramePerSecond(float _fps) {
	this->m_FramePerSecond = _fps;
}
