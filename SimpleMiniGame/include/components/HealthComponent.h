#pragma once
#include "Components.h"

class HealthComponent : public Component
{
protected:
	int currentHealth;
	int maximumHealth;

public:
	HealthComponent(int startHealth, int maxHealth) : currentHealth{ startHealth }, maximumHealth{ maxHealth }{}
	
	virtual const ComponentID getID() const { return ComponentID::HEALTH; }

	int getHealth() const { return currentHealth; }
	
	void changeHealth(int val) 
	{
		currentHealth += val;

		if (currentHealth > maximumHealth)
			currentHealth = maximumHealth;
		else if (currentHealth < 0)
			currentHealth = 0;
	}
};