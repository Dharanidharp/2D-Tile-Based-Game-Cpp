#pragma once

enum class ComponentID
{
	UNDEFINED = -1,
	INPUT = 0,
	POSITION = 1,
	VELOCITY = 2,
	TTL = 3,
	HEALTH = 4,
	GRAPHICS = 5,
	COLLIDER = 6,
	LOGIC = 7,
	AUDIO = 8
};

class Component
{
public:
	~Component() {}
	virtual const ComponentID getID() const = 0;
};
