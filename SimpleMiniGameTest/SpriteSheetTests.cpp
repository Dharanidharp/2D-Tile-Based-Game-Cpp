#include "pch.h"
#include "../SimpleMiniGame/include/graphics/SpriteSheet.h"

namespace SpriteAnimations
{
	TEST(SpriteSheet, Init)
	{
		SpriteSheet ss;

		EXPECT_TRUE(ss.getCurrentAnim() == nullptr);

		const sf::Vector2f& sscale = ss.getSpriteScale();
		EXPECT_EQ(sscale.x, 1.f);
		EXPECT_EQ(sscale.y, 1.f);

		const Direction& sdir = ss.getSpriteDirection();
		EXPECT_EQ(sdir, Direction::Right);
	}


	TEST(SpriteSheet, SetSpriteSize)
	{
		SpriteSheet ss;
		ss.setSpriteSize({ 1, 3 });
		EXPECT_EQ(ss.getSpriteSize().x, 1);
		EXPECT_EQ(ss.getSpriteSize().y, 3);
	}

	TEST(SpriteSheet, SetSpriteScale)
	{
		SpriteSheet ss;
		ss.setSpriteScale({ 10.f, 20.f });
		EXPECT_EQ(ss.getSpriteScale().x, 10.f);
		EXPECT_EQ(ss.getSpriteScale().y, 20.f);
	}

	TEST(SpriteSheet, SetSpritePosition)
	{
		SpriteSheet ss;
		ss.setSpritePosition({ -1.f, 5.f });
		EXPECT_EQ(ss.getSpritePosition().x, -1.f);
		EXPECT_EQ(ss.getSpritePosition().y, 5.f);
	}

	TEST(SpriteSheet, SetSpriteDirection)
	{
		SpriteSheet ss;
		ss.setSpriteDirection(Direction::Left);
		EXPECT_EQ(ss.getSpriteDirection(), Direction::Left);
	}

	TEST(SpriteSheet, Loading)
	{
		SpriteSheet ss;
		ss.loadSheet("../SimpleMiniGame/img/SpriteSheetDataTest.txt");
		int numAnimations = ss.getNumAnimations();
		EXPECT_EQ(numAnimations, 5);

		const sf::Vector2f& sscale = ss.getSpriteScale();
		EXPECT_EQ(sscale.x, 3.f);
		EXPECT_EQ(sscale.y, 3.f);

		const sf::Vector2i& ssize = ss.getSpriteSize();
		EXPECT_EQ(ssize.x, 32);
		EXPECT_EQ(ssize.y, 32);

		const std::string& aType = ss.getAnimType();
		EXPECT_EQ(aType, "Directional");
	}

	TEST(SpriteSheet, LoadingAnimValues)
	{
		SpriteSheet ss;
		ss.loadSheet("../SimpleMiniGame/img/SpriteSheetDataTest.txt");
		ss.setAnimation("Walk");
		AnimBase* anim = ss.getCurrentAnim();
		EXPECT_EQ(anim->getCurrentFrame(), 0);
		EXPECT_EQ(anim->getStartFrame(), 0);
		EXPECT_EQ(anim->getEndFrame(), 7);
		EXPECT_EQ(anim->getFrameRow(), 1);
		EXPECT_EQ(anim->getFrameTime(), 0.1f);
		EXPECT_EQ(anim->getFrameActionStart(), -1);
		EXPECT_EQ(anim->getFrameActionEnd(), -1);
	}

	TEST(SpriteSheet, SetAnimation)
	{
		SpriteSheet ss;
		ss.loadSheet("../SimpleMiniGame/img/SpriteSheetDataTest.txt");

		ss.setAnimation("Idle");
		AnimBase* animation = ss.getCurrentAnim();
		EXPECT_EQ(animation->getName(), "Idle");
		EXPECT_FALSE(animation->isLooping());
		EXPECT_FALSE(animation->isPlaying());

		ss.setAnimation("Death", true);
		animation = ss.getCurrentAnim();
		EXPECT_EQ(animation->getName(), "Death");
		EXPECT_FALSE(animation->isLooping());
		EXPECT_TRUE(animation->isPlaying());

		ss.setAnimation("Walk", true, true);
		AnimBase* anim2 = ss.getCurrentAnim();
		EXPECT_FALSE(animation->isPlaying());
		EXPECT_TRUE(anim2->isPlaying());
		EXPECT_TRUE(anim2->isLooping());
	}

	TEST(SpriteSheet, Release)
	{
		SpriteSheet ss;
		ss.loadSheet("../SimpleMiniGame/img/SpriteSheetDataTest.txt");
		ss.releaseSheet();
		EXPECT_EQ(ss.getNumAnimations(), 0);
		AnimBase* animation = ss.getCurrentAnim();
		EXPECT_EQ(ss.getCurrentAnim(), nullptr);
	}


	TEST(SpriteSheet, UpdateAnimation)
	{
		SpriteSheet ss;
		ss.loadSheet("../SimpleMiniGame/img//SpriteSheetDataTest.txt");
		ss.setAnimation("Attack", true);
		AnimBase* anim = ss.getCurrentAnim();

		//Running through the Attack animation.
		anim->update(0.075f);
		EXPECT_EQ(anim->getCurrentFrame(), 0);
		anim->update(0.075f);
		EXPECT_EQ(anim->getCurrentFrame(), 1);
		anim->update(0.1f);
		EXPECT_EQ(anim->getCurrentFrame(), 2);
		anim->update(0.1f);
		EXPECT_EQ(anim->getCurrentFrame(), 3);
		EXPECT_FALSE(anim->isInAction());
		anim->update(0.1f);
		EXPECT_TRUE(anim->isInAction());
		anim->update(0.1f);
		EXPECT_TRUE(anim->isInAction());
		anim->update(0.1f);
		EXPECT_FALSE(anim->isInAction());
		anim->update(0.1f);
		EXPECT_FALSE(anim->isPlaying()); //end.
	}

}