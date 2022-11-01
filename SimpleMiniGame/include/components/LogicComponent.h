#pragma once
#include "Components.h"

class Entity;
class Game;

class LogicComponent : public Component
{
public:
	virtual const ComponentID getID() const { return ComponentID::LOGIC; }

	virtual bool isAttacking() const = 0;
	virtual void setAttacking(bool attack) = 0;

	virtual bool isShouting() const = 0;
	virtual void setShouting(bool shout) = 0;

	virtual void addWood(int num) = 0;
	virtual int getWood() const = 0;

	virtual int getShootingCost() const = 0;
	virtual float getShootCooldown() const = 0;
	virtual void setShootCooldown(float val) = 0;
	virtual float getShootCooldownTime() const = 0;
};

class PlayerStateComponent : public LogicComponent
{
private:
	int wood;
	int maxWood;
	bool attacking;
	bool shouting;
	int shootingCost;
	float shootCooldown;
	float shootCooldownTime;

public:
	PlayerStateComponent(int maxWood, int shootingCost, float shootCooldownTime);
	~PlayerStateComponent() {}

	virtual bool isAttacking() const override { return attacking; }
	virtual void setAttacking(bool attack) override { attacking = attack; }

	virtual bool isShouting() const override { return shouting; }
	virtual void setShouting(bool shout) override { shouting = shout; }

	virtual void addWood(int num);
	virtual int getWood() const { return wood; }

	virtual float getShootCooldown() const { return shootCooldown; }
	virtual void setShootCooldown(float sh) { shootCooldown = sh; }
	virtual float getShootCooldownTime() const { return shootCooldownTime; }
	virtual int getShootingCost() const { return shootingCost; }
};