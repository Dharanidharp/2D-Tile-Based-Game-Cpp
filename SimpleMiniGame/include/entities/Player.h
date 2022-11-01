#pragma once
#include "Entity.h"
#include "../components/HealthComponent.h"
#include "../components/VelocityComponent.h"
#include "../components/ColliderComponent.h"
#include "../components/LogicComponent.h"
#include "../../include/utils/Subject.h"
#include <functional>

class Fire;

using OnCollisionCallback = std::function<void(float)>;

// VI.A (2/2): Add a forward declaration to the class PlayerInputHandler
class InputComponent;

class Player :  public Entity
{
public:

	const float playerSpeed = 100.f;
	const int startingHealth = 60;
	const int maxHealth = 100;
	const int maxWood = 100;
	const int shootingCost = 20;
	const float fireSpeed = 200.f;
	const float shootCooldownTime = 3.f; //in seconds

	Player();
	~Player();

	void init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics) override;

	bool isAttacking();
	void setAttacking(bool at);

	bool isShouting();
	void setShouting(bool sh);

	int getWood();
	void addWood(int num);

	std::shared_ptr<Fire> createFire();

	bool collision(Entity& other);

	void registerPotionCallback(int entityID, OnCollisionCallback func);
	void registerLogCallback(int entityID, OnCollisionCallback func);

	void positionSprite(int row, int col, int spriteWH, float tileScale);

	/*Subject getPotionsSubject();
	Subject getShoutSubject();*/

private:
	/*Subject potionsCollected;
	Subject shoutFiveTimes;*/

	std::map<int, OnCollisionCallback> potionCollision;
	std::map<int, OnCollisionCallback> logCollision;
};

