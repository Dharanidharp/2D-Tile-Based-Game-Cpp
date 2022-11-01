#include "../../include/entities/Fire.h"

#include <iostream>

Fire::Fire() : Entity(EntityType::FIRE)
{
	addComponent(std::make_shared<TTLComponent>(startTimeToLive));
	addComponent(std::make_shared<VelocityComponent>());
}

Fire::~Fire()
{}

//void Fire::update(Game* game, float elapsed)
//{
//	// XI.C First, update the position of the Fire object by calling the parent Entity::update() function.
//	Entity::update(game, elapsed);
//	
//	// I-C
//	vel->update(*this, elapsed);
//
//	// XI.D Time to live (Fire::ttl member variable) needs to be reduced by 1 at every frame. If this gets
//	//		to 0, the entity must be deleted (here, just setting the deleted flag to ture).
//
//
//}

int Fire::getTTL() 
{
	return dynamic_cast<TTLComponent*>(getComponentID(ComponentID::TTL))->getTTL();
}
