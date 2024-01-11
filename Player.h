#pragma once
#include <SFML/Graphics.hpp>	

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	// Where is the player
	Vector2f m_Position;

	// Sprite for the player
	Sprite m_Sprite;

	// Texture for the sprite
	Texture m_Texture;

	// Screen resolution
	Vector2f m_Resolution;

	// Size of the arena
	IntRect m_Arena;

	// How big is each tile of the arena
	int m_TileSize;

	// Player's direction
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_RightPressed;
	bool m_LeftPressed;

	// Player's health
	int m_Health;

	// Maximum hp that player can have
	int m_MaxHealth;

	// When was the player last hit
	Time m_LastHit;

	// Speed in pixels per second
	float m_Speed;

public:
	Player();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);

	// Call this at the end of every game
	void resetPlayerStats();

	// Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	// How long ago was the player last hit
	Time getLastHitTime();

	// Where is the player
	FloatRect getPosition();

	// Where is the center of the player
	Vector2f getCenter();

	// What angle is te player facing
	float getRotation();

	// Send a copy of the sprite to the main function
	Sprite getSprite();

	// Movement functions
	void moveLeft();
	void stopLeft();

	void moveRight();
	void stopRight();

	void moveUp();
	void stopUp();

	void moveDown();
	void stopDown();

	// Update function to call every frame
	void update(float elapsedTime, Vector2i mousePosition);

	// Give the player a speed boost
	void upgradeSpeed();

	// Give the player a health boost
	void upgradeHealth();

	// Increase the max amount of hp the player can have
	void increaseHealthLevel(int amount);

	// How much health has the player currently got?
	int getHealth();

};
