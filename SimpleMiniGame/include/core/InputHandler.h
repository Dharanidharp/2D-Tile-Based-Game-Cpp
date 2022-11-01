#pragma once
#include "../../include/core/Command.h"
#include <memory>
#include <vector>

class InputHandler
{
private:
	std::shared_ptr<Command> pauseCommand;

public:
	InputHandler();
	~InputHandler() {}
	std::shared_ptr<Command> handleInput();
};

class PlayerInputHandler
{
public:
	PlayerInputHandler() :
		moveUpCommand{ std::make_shared<MoveUpCommand>() },
		moveDownCommand{ std::make_shared<MoveDownCommand>() },
		moveLeftCommand{ std::make_shared<MoveLeftCommand>() },
		moveRightCommand{ std::make_shared<MoveRightCommand>() },
		attackCommand{ std::make_shared<AttackCommand>() },
		shoutCommand{ std::make_shared<ShoutCommand>() } {}

	~PlayerInputHandler() {}

	std::vector<std::shared_ptr<Command>>& handleInput();
	std::vector<std::shared_ptr<Command>>& handleInputCursor();

private:
	std::vector<std::shared_ptr<Command>> commands;

	std::shared_ptr<Command> moveUpCommand;
	std::shared_ptr<Command> moveLeftCommand;
	std::shared_ptr<Command> moveDownCommand;
	std::shared_ptr<Command> moveRightCommand;
	std::shared_ptr<Command> attackCommand;
	std::shared_ptr<Command> shoutCommand;
};