#include "../../include/systems/Systems.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/core/Game.h"
#include "../../include/entities/Player.h"
#include "../../include/entities/EntityPool.h"

GraphicsSystem::GraphicsSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::POSITION));
	componentMask.turnOnBit(static_cast<int>(ComponentID::GRAPHICS));
}

void GraphicsSystem::update(Game* game, Entity* entity, float elapsed)
{
	auto position = dynamic_cast<PositionComponent*>(entity->getComponentID(ComponentID::POSITION));
	auto graphics = dynamic_cast<GraphicsComponent*>(entity->getComponentID(ComponentID::GRAPHICS));

	if (position)
	{
		if (graphics)
		{
			if (graphics->isSpriteSheetEntity())
			{
				auto spriteSheetGraphics = dynamic_cast<SpriteSheetGraphics*>(graphics);

				auto& spriteSheet{ spriteSheetGraphics->getSpriteSheet() };
				spriteSheet.setSpritePosition(sf::Vector2f(position->getPosition().x, position->getPosition().y));
				spriteSheet.update(elapsed);

				game->getWindow()->draw(spriteSheet.getSprite());
			}

			else
			{
				if (!entity->inUse())
					return;

				auto spriteGraphics = dynamic_cast<SimpleSpriteGraphics*>(graphics);
				spriteGraphics->getSprite().setPosition(position->getPosition().x, position->getPosition().y);

				if (entity->inUse()) 
				{
					game->getWindow()->draw(spriteGraphics->getSprite());
				}
			}
		}
		else
		{
			throw std::runtime_error("No Graphics Component");
		}
	}
	else
	{
		throw std::runtime_error("No Position Component");
	}
}