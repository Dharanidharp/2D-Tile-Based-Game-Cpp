#include "../../include/systems/Systems.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/VelocityComponent.h"

MovementSystem::MovementSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::POSITION));
	componentMask.turnOnBit(static_cast<int>(ComponentID::VELOCITY));
}

void MovementSystem::update(Game* game, Entity* entity, float elapsed)
{
	auto position = dynamic_cast<PositionComponent*>(entity->getComponentID(ComponentID::POSITION));
	auto velocity = dynamic_cast<VelocityComponent*>(entity->getComponentID(ComponentID::VELOCITY));

	if (position)
	{
		if (velocity)
		{
			auto update = position->getPosition() + velocity->getVelocity() * velocity->getSpeed() * elapsed;
			position->setPosition(update.x, update.y);
		}
		else
		{
			throw std::runtime_error("No Velocity Component");
		}
	}
	else
	{
		throw std::runtime_error("No Position Component");
	}
}