#include "../../include/systems/Systems.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/ColliderComponent.h"

ColliderSystem::ColliderSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::POSITION));
	componentMask.turnOnBit(static_cast<int>(ComponentID::COLLIDER));
}

void ColliderSystem::update(Game* game, Entity* entity, float elapsed)
{
	auto position = dynamic_cast<PositionComponent*>(entity->getComponentID(ComponentID::POSITION));
	auto collider = dynamic_cast<ColliderComponent*>(entity->getComponentID(ComponentID::COLLIDER));

	if (position)
	{
		if (collider)
		{
			collider->getBoundingBox().setTopLeft(position->getPosition());
			collider->getBoundingBox().setBottomRight(position->getPosition() + collider->getBBoxSize());
		}
		else
		{
			throw std::runtime_error("No Collider Component");
		}
	}
	else
	{
		throw std::runtime_error("No Position Component");
	}
}