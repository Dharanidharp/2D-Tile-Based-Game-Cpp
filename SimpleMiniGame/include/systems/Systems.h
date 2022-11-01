#pragma once
#include "../utils/Bitmask.h"
#include "../entities/Entity.h"
#include <functional>

class Game;
class Entity;

class System
{
public:
	virtual void update(Game* game, Entity* entity, float elapsed) = 0;

	bool validate(Entity* entity) const { return entity->hasComponent(componentMask); }

protected:
	Bitmask componentMask;
};

class TTLSystem : public System
{
public:
	TTLSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};

class InputSystem : public System
{
public:
	InputSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};

class MovementSystem : public System
{
public:
	MovementSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};

class GraphicsSystem : public System
{
public:
	GraphicsSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};

class ColliderSystem : public System
{
public:
	ColliderSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};

class GameplaySystem : public System
{
public:
	GameplaySystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};