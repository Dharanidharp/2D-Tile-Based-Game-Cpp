#include "../../include/entities/Player.h"
#include "../../include/graphics/AnimBase.h"
#include "../../include/entities/Fire.h"
#include "../../include/core/Game.h"
#include "../../include/components/InputComponent.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/VelocityComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/core/Command.h"
#include "../../include//utils/SoundPlayer.h"
#include "../../include//utils/ServiceLocator.h"
#include <iostream>

Player::Player() : Entity(EntityType::PLAYER)
{
	// VI.B: Create the unique pointer to the PlayerInputHandler object
	addComponent(std::make_shared<PlayerInputComponent>());

	addComponent(std::make_shared<HealthComponent>(startingHealth, maxHealth));
	
	addComponent(std::make_shared<VelocityComponent>(playerSpeed));

	addComponent(std::make_shared<ColliderComponent>());
	
	addComponent(std::make_shared<PlayerStateComponent>(maxWood, shootingCost, shootCooldownTime));

}

Player::~Player() {}

void Player::init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics) 
{
	Entity::init(textureFile, graphics);
	dynamic_cast<ColliderComponent*>(getComponentID(ComponentID::COLLIDER))->setBboxSize(graphics->getBBoxSize());
}


bool Player::isAttacking()
{
	return dynamic_cast<LogicComponent*>(getComponentID(ComponentID::LOGIC))->isAttacking();
}

void Player::setAttacking(bool at)
{
	dynamic_cast<LogicComponent*>(getComponentID(ComponentID::LOGIC))->setAttacking(at);
}

bool Player::isShouting()
{
	return dynamic_cast<LogicComponent*>(getComponentID(ComponentID::LOGIC))->isShouting();
}

void Player::setShouting(bool sh)
{
	dynamic_cast<LogicComponent*>(getComponentID(ComponentID::LOGIC))->setShouting(sh);
}

std::shared_ptr<Fire> Player::createFire()
{
	
	AudioManager* audio = ServiceLocator::GetAudio();
	audio->PlaySound("sounds/shot.wav");

	auto fireEntity = std::make_shared<Fire>();		

	Vector2f pos{
		dynamic_cast<PositionComponent*>(getComponentID(ComponentID::POSITION))->
		getPosition().x + getTextureSize().x * 0.5f,
		dynamic_cast<PositionComponent*>(getComponentID(ComponentID::POSITION))->
		getPosition().y + getTextureSize().y * 0.5f
	};

	fireEntity->init(true, "img/fire.png", std::make_shared<SimpleSpriteGraphics>(1.0f));
	dynamic_cast<PositionComponent*>(fireEntity->getComponentID(ComponentID::POSITION))->setPosition(pos.x, pos.y);
	Vector2f vel(fireSpeed, 0.f);
	if (dynamic_cast<GraphicsComponent*>(getComponentID(ComponentID::GRAPHICS))->getSpriteDirection() == Direction::Left) vel.x = vel.x * -1.0f;
	dynamic_cast<VelocityComponent*>(fireEntity->getComponentID(ComponentID::VELOCITY))->setVelocity(vel.x, vel.y);

	return fireEntity;
}

void Player::addWood(int w)
{
	dynamic_cast<LogicComponent*>(getComponentID(ComponentID::LOGIC))->addWood(w);
}

int Player::getWood() 
{
	return dynamic_cast<LogicComponent*>(getComponentID(ComponentID::LOGIC))->getWood();
}

bool Player::collision(Entity& other) 
{
	return dynamic_cast<ColliderComponent*>(getComponentID(ComponentID::COLLIDER))->intersects(dynamic_cast<ColliderComponent*>(other.getComponentID(ComponentID::COLLIDER)));
}

void Player::registerPotionCallback(int entityID, OnCollisionCallback func) 
{
	potionCollision.emplace(entityID, func);
}

void Player::registerLogCallback(int entityID, OnCollisionCallback func)
{
	logCollision.emplace(entityID, func);
}

void Player::positionSprite(int row, int col, int spriteWH, float tileScale)
{
	sf::Vector2f scaleV2f = getSpriteScale();
	sf::Vector2i textureSize = getTextureSize();

	float x = col * spriteWH * tileScale;
	float y = (row)*spriteWH * tileScale;
	float spriteSizeY = scaleV2f.y * textureSize.y;
	float cntrFactorY = ((spriteWH * tileScale) - spriteSizeY);	// to align to lower side of the tile.
	float cntrFactorX = cntrFactorY * 0.5f;						//to center horizontally

	dynamic_cast<PositionComponent*>(getComponentID(ComponentID::POSITION))->setPosition(x + cntrFactorX, y + cntrFactorY);
	dynamic_cast<VelocityComponent*>(getComponentID(ComponentID::VELOCITY))->setVelocity(0.f, 0.f);
}
