#pragma once
#include "Entity.h"
#include "../components/TTLComponent.h"
#include "../../include/components/VelocityComponent.h"

class Fire : public Entity
{
public:
	const int startTimeToLive = 150; //frames

	Fire();
	~Fire();

	int getTTL();
};

