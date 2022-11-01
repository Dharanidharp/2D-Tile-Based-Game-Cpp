#include "../../include/core/Command.h"
#include "../../include/core/Game.h"

void MoveUpCommand::execute(Game& game)
{
	auto v = dynamic_cast<VelocityComponent*>(game.getPlayer()->getComponentID(ComponentID::VELOCITY));
	v->setVelocity(v->getVelocity().x, -1.0f);
}

void MoveLeftCommand::execute(Game& game)
{
	auto v = dynamic_cast<VelocityComponent*>(game.getPlayer()->getComponentID(ComponentID::VELOCITY));
	v->setVelocity(-1.0f, v->getVelocity().y);
}

void MoveDownCommand::execute(Game& game)
{
	auto v = dynamic_cast<VelocityComponent*>(game.getPlayer()->getComponentID(ComponentID::VELOCITY));
	v->setVelocity(v->getVelocity().x, 1.0f);
}

void MoveRightCommand::execute(Game& game)
{
	auto v = dynamic_cast<VelocityComponent*>(game.getPlayer()->getComponentID(ComponentID::VELOCITY));
	v->setVelocity(1.0f, v->getVelocity().y);
}

void AttackCommand::execute(Game& game)
{
	game.getPlayer()->setAttacking(true);
}

void ShoutCommand::execute(Game& game)
{
	game.getPlayer()->setShouting(true);
}
