#pragma once
#include "../../include/entities/Entity.h"
#include "../../include/entities/EntityPool.h"
#include "../../include/components/GraphicsComponent.h"

EntityPool::EntityPool() 
{
    firstAvailableFire = &entitiesFire[0];
    firstAvailablePotion = &entitiesPotion[0];
    firstAvailableLog = &entitiesLog[0];

    for (int i = 0; i < POOL_SIZE_FIRE - 1; i++) 
    {
        entitiesFire[i].setNext(&entitiesFire[i + 1]);
    }

    entitiesFire[POOL_SIZE_FIRE - 1].setNext(nullptr);

    for (int i = 0; i < POOL_SIZE_POTION - 1; i++)
    {
        entitiesPotion[i].setNext(&entitiesPotion[i + 1]);
    }

    entitiesPotion[POOL_SIZE_POTION - 1].setNext(nullptr);

    for (int i = 0; i < POOL_SIZE_LOG - 1; i++)
    {
        entitiesLog[i].setNext(&entitiesLog[i + 1]);
    }

    entitiesLog[POOL_SIZE_LOG - 1].setNext(nullptr);
}

void EntityPool::createPotionEntity(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics)
{
    if (firstAvailablePotion != nullptr) 
    {
        Entity* newEntity = firstAvailablePotion;
        firstAvailablePotion = newEntity->getNext();
        newEntity->init(true, textureFile, graphics);
    }
}

void EntityPool::createLogEntity(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics)
{
    if (firstAvailableLog != nullptr)
    {
        Entity* newEntity = firstAvailableLog;
        firstAvailableLog = newEntity->getNext();
        newEntity->init(true, textureFile, graphics);
    }
}

void EntityPool::createFireEntity(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics)
{
    if (firstAvailableFire != nullptr)
    {
        Entity* newEntity = firstAvailableFire;
        firstAvailableFire = newEntity->getNext();
        newEntity->init(true, textureFile, graphics);
    }
}
