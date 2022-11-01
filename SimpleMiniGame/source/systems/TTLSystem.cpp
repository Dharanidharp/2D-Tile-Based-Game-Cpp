#include "../../include/systems/Systems.h"
#include "../../include/components/Components.h"
#include "../../include/components/TTLComponent.h"

TTLSystem::TTLSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::TTL));
}

void TTLSystem::update(Game* game, Entity* entity, float elapsed)
{
	auto ttl = dynamic_cast<TTLComponent*>(entity->getComponentID(ComponentID::TTL));

	if (ttl)
	{
		ttl->decrease();

		if (ttl->getTTL() <= 0)
		{
			entity->setUseBool(false);
		}
	}
	else
	{
		throw std::runtime_error("No TTL Component");
	}
}