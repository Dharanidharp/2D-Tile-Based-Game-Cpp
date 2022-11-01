//#include "../../include/components/InputComponent.h"
//#include "../../include/core/Game.h"
//#include "../../include/core/InputHandler.h"
//
//PlayerInputComponent::PlayerInputComponent() 
//{
//	playerInputHandler = std::make_unique<PlayerInputHandler>();
//
//}
//
//void PlayerInputComponent::update(Game& game) 
//{
//	// I-C
//	auto v = game.getPlayer()->getVelocityComp();
//	v->setVelocity(0.0f, 0.0f);
//
//	auto command = playerInputHandler->handleInput();
//
//	for(std::shared_ptr<Command> comm: command)
//	{
//		comm->execute(game);
//	}
//}