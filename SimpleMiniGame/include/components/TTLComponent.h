#pragma once
#include "Components.h"

class TTLComponent : public Component
{
private:
	int ttl;

public:
	virtual const ComponentID getID() const { return ComponentID::TTL; }
	TTLComponent(int val) :ttl{ val } {}
	void decrease() { ttl = ttl > 0 ? ttl - 1 : ttl; }
	int getTTL() const { return ttl; }
};