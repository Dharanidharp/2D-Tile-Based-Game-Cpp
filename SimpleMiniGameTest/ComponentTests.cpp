#include "pch.h"
#include "../SimpleMiniGame/include/components/Components.h"
#include "../SimpleMiniGame/include/entities/Player.h"
#include "../SimpleMiniGame/include/entities/StaticEntities.h"
#include "../SimpleMiniGame/include/entities/Fire.h"

TEST(Components, AddPlayer)
{
	std::shared_ptr<Player> player = std::make_shared<Player>();
	auto bitmask = player->getComponentSet();

	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));

	/* Add here test for the other components you have implemented,
	   with either EXPECT_TRUE or EXPECT_FALSE depending on these components
	   expected to be there or not.*/
}

TEST(Components, AddPotion)
{
	std::shared_ptr<Potion> potion = std::make_shared<Potion>();

	auto bitmask = potion->getComponentSet();

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));

	/* Add here test for the other components you have implemented,
	   with either EXPECT_TRUE or EXPECT_FALSE depending on these components
	   expected to be there or not.*/
}

TEST(Components, AddLog)
{
	std::shared_ptr<Log> log = std::make_shared<Log>();

	auto bitmask = log->getComponentSet();

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));

	/* Add here test for the other components you have implemented,
	   with either EXPECT_TRUE or EXPECT_FALSE depending on these components
	   expected to be there or not.*/
}


TEST(Components, AddFire)
{
	std::shared_ptr<Fire> fire = std::make_shared<Fire>();

	auto bitmask = fire->getComponentSet();

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));

	/* Add here test for the other components you have implemented,
	   with either EXPECT_TRUE or EXPECT_FALSE depending on these components
	   expected to be there or not.*/
}