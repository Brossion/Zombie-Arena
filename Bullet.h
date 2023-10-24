#pragma once
#include <SFML/Graphics.hpp>
//#include "TextureHolder.h"

using namespace sf;

class Bullet
{
private:
	// Bullet's position
	Vector2f m_Position;

	// Bullet's shape
	RectangleShape m_BulletShape;

	// Is bullet flying?
	bool m_InFlight = false;

	// Bullet's speed
	float m_BulletSpeed = 1000;

	// What fraction of 1 pixel does the bullet travel
	// Horizontally and vertically each frame?
	// These values will be derived from m_BulletSpeed
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	// Boundaries of bullet
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;

public:
	Bullet();

	// Stop the bullet
	void stop();

	// Returns the value of m_InFlight
	bool isInFlight();

	// Launch a new buller
	void shoot(float startX, float startY, float targetX, float targetY);

	// Tell the calling code where the bullet is in the world
	FloatRect getPosition();

	// Return the actual shape (for drawing)
	RectangleShape getShape();

	// Update the bullet each frame
	void update(float elapsedTime);
};