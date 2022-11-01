#pragma once
#include "Entity.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/ColliderComponent.h"


class Potion : public Entity
{
public:
	Potion() : Entity(EntityType::POTION) 
	{
		addComponent(std::make_shared<ColliderComponent>());
	}
	~Potion() {}

	void init(bool b, const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics) override
	{
		Entity::init(b, textureFile, graphics);

		dynamic_cast<ColliderComponent*>(getComponentID(ComponentID::COLLIDER))->setBboxSize(graphics->getBBoxSize());
	}

	int getHealth() const { return potionHealth; }

protected:
	const int potionHealth = 10;
};


class Log : public Entity
{
public:
	Log() : Entity(EntityType::LOG) 
	{ 
		addComponent(std::make_shared<ColliderComponent>());
	}
	~Log() {}

	void init(bool b, const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics) override
	{
		Entity::init(b, textureFile, graphics);

		dynamic_cast<ColliderComponent*>(getComponentID(ComponentID::COLLIDER))->setBboxSize(graphics->getBBoxSize());
	}

	int getWood() const { return woodAdded; }

protected:
	const int woodAdded = 15;
};