#pragma once
#include "../../include/entities/Entity.h"
#include "../../include/components/GraphicsComponent.h"

static const int POOL_SIZE_POTION = 50;
static const int POOL_SIZE_LOG = 50;
static const int POOL_SIZE_FIRE = 50;

class EntityPool
{
public:
	EntityPool();

	void createPotionEntity(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics);
	void createLogEntity(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics);
	void createFireEntity(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics);

private:
	bool entInUse = false;
	const float itemScale = 1.0f;
	Entity entitiesPotion[POOL_SIZE_POTION];
	Entity entitiesLog[POOL_SIZE_LOG];
	Entity entitiesFire[POOL_SIZE_FIRE];
	
	Entity* firstAvailableFire;
	Entity* firstAvailablePotion;
	Entity* firstAvailableLog;
};
