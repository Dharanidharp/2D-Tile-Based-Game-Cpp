#include "../../include/systems/Systems.h"
#include "../../include/entities/Player.h"
#include "../../include/entities/Fire.h"
#include "../../include/core/Game.h"
#include "../../include/components/LogicComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/VelocityComponent.h"
#include "../../include//utils/SoundPlayer.h"
#include "../../include//utils/ServiceLocator.h"

GameplaySystem::GameplaySystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::LOGIC));
	componentMask.turnOnBit(static_cast<int>(ComponentID::GRAPHICS));
	componentMask.turnOnBit(static_cast<int>(ComponentID::VELOCITY));
}

void GameplaySystem::update(Game* game, Entity* entity, float elapsed)
{
	auto graphics = dynamic_cast<SpriteSheetGraphics*>(entity->getComponentID(ComponentID::GRAPHICS));
	auto velocity = dynamic_cast<VelocityComponent*>(entity->getComponentID(ComponentID::VELOCITY));
	auto logic = dynamic_cast<LogicComponent*>(entity->getComponentID(ComponentID::LOGIC));
	if (logic)
	{
		if (graphics)
		{
			if (velocity)
			{
				auto& spriteSheet{ graphics->getSpriteSheet() };

				auto player = dynamic_cast<Player*>(entity);

				if (player->isAttacking())
				{
					spriteSheet.setAnimation("Attack", true, false);

					AudioManager* audio = ServiceLocator::GetAudio();
					audio->PlaySound("sounds/swing.flac");
				}
				else if (player->isShouting())
				{
					spriteSheet.setAnimation("Shout", true, false);
				}
				else if (velocity->getVelocity() != Vector2f(0.f, 0.f))
				{
					spriteSheet.setAnimation("Walk", true, true);

					if (velocity->getVelocity().x > 0.f)
					{
						spriteSheet.setSpriteDirection(Direction::Right);
					}

					if (velocity->getVelocity().x < 0.f)
					{
						spriteSheet.setSpriteDirection(Direction::Left);
					}
				}
				else
				{
					spriteSheet.setAnimation("Idle", true, true);
				}

				if (logic->isShouting() && graphics->isInAction() && logic->getWood() >= logic->getShootingCost() && logic->getShootCooldown() <= 0)
				{
					logic->setShootCooldown(logic->getShootCooldownTime());
					game->addEntity(player->createFire());
					logic->addWood(-logic->getShootingCost());
				}

				if (logic->isAttacking() && !(graphics->isPlaying()))
				{
					logic->setAttacking(false);
				}

				if (logic->isShouting() && !(graphics->isPlaying()))
				{
					logic->setShouting(false);
				}
			}
			else
			{
				throw std::runtime_error("NO Velocity Component");
			}
		}
		else
		{
			throw std::runtime_error("NO Graphics Component");
		}
	}
	else
	{
		throw std::runtime_error("NO Logic Component");
	}
}