#include "../../include/systems/Systems.h"
#include "../../include/components/InputComponent.h"
#include "../../include/components/VelocityComponent.h"
#include "../../include/core/InputHandler.h"
#include "../../include/core/Game.h"

InputSystem::InputSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::INPUT));
	componentMask.turnOnBit(static_cast<int>(ComponentID::VELOCITY));
}

void InputSystem::update(Game* game, Entity* entity, float elapsed)
{
	auto input = dynamic_cast<InputComponent*>(entity->getComponentID(ComponentID::INPUT));
	auto velocity = dynamic_cast<VelocityComponent*>(entity->getComponentID(ComponentID::VELOCITY));

	if (input)
	{
		if (velocity)
		{
			velocity->setVelocity(0.f, 0.f);

			auto handler{ input->getPlayerInputHandler() };
			if (handler)
			{
				// WASD
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					auto& commands{ handler->handleInput() };
					
					for (auto command : commands)
					{
						command->execute(*game);
					}
				}
				else 
				{
					// Arrow keys
					auto& commands{ handler->handleInputCursor() };

					for (auto command : commands)
					{
						command->execute(*game);
					}
				}
			}
			else
			{
				throw std::runtime_error("Player Input Handler not found");
			}
		}
		else
		{
			throw std::runtime_error("No Velocity Component");
		}
	}
	else
	{
		throw std::runtime_error("No Input Component");
	}
}