#include "../../include/entities/Entity.h"
#include "../../include/graphics/Window.h"
#include <iostream>
#include "../../include/components/Components.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/GraphicsComponent.h"


Entity::Entity() :
	id(0),
	type(EntityType::UNDEFINED),
	deleted(false),
	isInUse(false)
{
	auto position = std::make_shared<PositionComponent>();
	position->setPosition(0.0f, 0.0f);
	addComponent(position);
}

Entity::Entity(EntityType et) :
	id(0),
	type(et),
	deleted(false),
	isInUse(false)
{
	auto position = std::make_shared<PositionComponent>();
	position->setPosition(0.0f, 0.0f);
	addComponent(position);
}

Entity::~Entity()
{
}

void Entity::init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics)
{
	addComponent(graphics);
	graphics->init(textureFile);
	graphics->setPosition(dynamic_cast<PositionComponent*>(getComponentID(ComponentID::POSITION))->getPosition());
}

void Entity::init(bool use, const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics)
{
	isInUse = use;
	addComponent(graphics);
	graphics->init(textureFile);
	graphics->setPosition(dynamic_cast<PositionComponent*>(getComponentID(ComponentID::POSITION))->getPosition());
}

const sf::Vector2f& Entity::getSpriteScale()
{
	return dynamic_cast<GraphicsComponent*>(getComponentID(ComponentID::GRAPHICS))->getSpriteScale();
}

const sf::Vector2i& Entity::getTextureSize()
{
	return dynamic_cast<GraphicsComponent*>(getComponentID(ComponentID::GRAPHICS))->getTextureSize();
}

bool Entity::isSpriteSheetEntity()
{
	return dynamic_cast<GraphicsComponent*>(getComponentID(ComponentID::GRAPHICS))->isSpriteSheetEntity();
}

const std::string& Entity::getAnimName()
{
	return dynamic_cast<GraphicsComponent*>(getComponentID(ComponentID::GRAPHICS))->getAnimName();
}

void Entity::addComponent(std::shared_ptr<Component> component)
{
	auto id = component->getID();
	IDMap.insert_or_assign(id, component);
	componentSet.turnOnBit(static_cast<unsigned int>(component->getID()));
}

bool Entity::hasComponent(Bitmask mask) const
{
	return componentSet.contains(mask);
}

Component* Entity::getComponentID(ComponentID id)
{
	return IDMap.find(id)->second.get();
}

void Entity::setUseBool(bool b) 
{
	isInUse = b;
}
