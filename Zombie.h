#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	// Speed of each zombies
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;

	// Health points of each zombies
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;

	// Make each zombie vary its speed slightly
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	// Zombie positions
	Vector2f m_Position;

	// A sprite for the zombie
	Sprite m_Sprite;

	// Speed of one zombie
	float m_Speed;

	// Health point of one zombie
	float m_Health;

	// Alive or dead?
	bool m_Alive;

public:
	// Bullet hit to zombie?
	bool hit();

	// Find out if zombie is alive
	bool isAlive();

	// Spawn a new zombie
	void spawn(float startX, float startY, int type, int seed);

	// Return a rectange that is the position in the world
	FloatRect getPosition();

	// Get a copy of the sprite to draw
	Sprite getSprite();

	// Update the zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);

};