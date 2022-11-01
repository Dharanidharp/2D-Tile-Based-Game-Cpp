#include "pch.h"
#include "../SimpleMiniGame/include/entities/Entity.h"

namespace Entities
{

	void defaultEntityMembers(const Entity& ent)
	{
		/*EXPECT_EQ(ent.getPosition().x, 0);
		EXPECT_EQ(ent.getPosition().y, 0);

		EXPECT_EQ(ent.getVelocity().x, 0);
		EXPECT_EQ(ent.getVelocity().y, 0);

		EXPECT_EQ(ent.getSpeed(), 1.0f);*/
		/*EXPECT_FALSE(ent.isSpriteSheetEntity());
		EXPECT_EQ(ent.getID(), 0);*/
	}

	TEST(Entity, Init)
	{
		/*Entity ent;
		Entity ent2(EntityType::FIRE);

		EXPECT_EQ(ent.getEntityType(), EntityType::UNDEFINED);
		EXPECT_EQ(ent2.getEntityType(), EntityType::FIRE);
		defaultEntityMembers(ent);
		defaultEntityMembers(ent2);*/
	}

	TEST(Entity, SetPos)
	{
		/*Entity ent;
		ent.setPosition(1.0f, 2.0f);
		EXPECT_EQ(ent.getPosition().x, 1.0f);
		EXPECT_EQ(ent.getPosition().y, 2.0f);*/
	}

	TEST(Entity, InitSpreadSheetEntity)
	{
		/*Entity ent;
		ent.initSpriteSheet("../SimpleMiniGame/img/SpriteSheetDataTest.txt");

		EXPECT_TRUE(ent.isSpriteSheetEntity());
		EXPECT_EQ(ent.getSpriteSheet()->getCurrentAnim()->getName(), "Idle");

		EXPECT_EQ(ent.getSpriteScale().x, 3.0f);
		EXPECT_EQ(ent.getSpriteScale().y, 3.0f);
		EXPECT_EQ(ent.getTextureSize().x, 32);
		EXPECT_EQ(ent.getTextureSize().y, 32);*/
	}

	TEST(Entity, InitSpriteEntity)
	{
		/*Entity ent;
		ent.init("../SimpleMiniGame/img/potion.png", 2.0f);

		EXPECT_EQ(ent.getSpriteScale().x, 2.0f);
		EXPECT_EQ(ent.getSpriteScale().y, 2.0f);
		EXPECT_EQ(ent.getTextureSize().x, 50);
		EXPECT_EQ(ent.getTextureSize().y, 50);*/
	}
}