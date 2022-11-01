#pragma once
#include "../../include/utils/Vector2.h"
#include "Components.h"

class Entity;

class VelocityComponent : public Component
{
private:
	Vector2f direction;
	float speed;

public:
	virtual const ComponentID getID() const { return ComponentID::VELOCITY; }

	VelocityComponent(float speed = 1.0f) : speed{ speed } {}
	const Vector2f& getVelocity() const { return direction; }
	float getSpeed() const { return speed; }
	void setVelocity(float x, float y) { direction.x = x, direction.y = y; }
};