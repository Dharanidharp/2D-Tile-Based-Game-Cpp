#include "../../include/core/InputHandler.h"
#include "../../include/core/Command.h"
#include <SFML/Graphics.hpp>

InputHandler::InputHandler() :pauseCommand(std::make_shared<PauseCommand>()) {}

std::shared_ptr<Command> InputHandler::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return pauseCommand;
	}

	return nullptr;
}

std::vector<std::shared_ptr<Command>>& PlayerInputHandler::handleInput()
{
	commands.clear();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		commands.push_back(moveUpCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		commands.push_back(moveLeftCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		commands.push_back(moveDownCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		commands.push_back(moveRightCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		commands.push_back(attackCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		commands.push_back(shoutCommand);
	}

	return commands;
}

std::vector<std::shared_ptr<Command>>& PlayerInputHandler::handleInputCursor()
{
	commands.clear();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		commands.push_back(moveUpCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		commands.push_back(moveLeftCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		commands.push_back(moveDownCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		commands.push_back(moveRightCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		commands.push_back(attackCommand);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		commands.push_back(shoutCommand);
	}

	return commands;
}