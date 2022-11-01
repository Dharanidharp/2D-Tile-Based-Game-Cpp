#include "pch.h"
#include "../SimpleMiniGame/include/core/Board.h"


namespace BoardTests
{

	TEST(Tile, Init)
	{
		Tile t(TileType::CORRIDOR);

		EXPECT_EQ(t.x(), 0);
		EXPECT_EQ(t.y(), 0);
		EXPECT_EQ(t.getScale().x, 1.f);
		EXPECT_EQ(t.getScale().y, 1.f);
	}

	TEST(Tile, Load)
	{
		Tile t(TileType::CORRIDOR);
		t.loadTile(2, 3, 8.f, "../SimpleMiniGame/img/floor.png");

		EXPECT_EQ(t.x(), 2);
		EXPECT_EQ(t.y(), 3);
		EXPECT_EQ(t.getScale().x, 8.f);
		EXPECT_EQ(t.getScale().y, 8.f);
		
		float expSpriteX = t.x() * 50.f * t.getScale().x;
		float expSpriteY = t.y() * 50.f * t.getScale().y;
		EXPECT_EQ(t.getSpriteXpos(), expSpriteX);
		EXPECT_EQ(t.getSpriteYpos(), expSpriteY);
	}


	TEST(Board, Init)
	{
		Board b;
		Board b2{ 10, 20 };

		EXPECT_EQ(b.getWidth(), 0);
		EXPECT_EQ(b.getHeight(), 0);
		EXPECT_EQ(b.getNumTiles(), 0);

		EXPECT_EQ(b2.getWidth(), 10);
		EXPECT_EQ(b2.getHeight(), 20);
		EXPECT_EQ(b2.getNumTiles(), 0);
	
	}

	TEST(Board, Bounds)
	{
		Board b{ 10, 20 };
		EXPECT_TRUE(b.inBounds(0,0));
		EXPECT_TRUE(b.inBounds(5, 19));
		EXPECT_FALSE(b.inBounds(5, 20));
		EXPECT_TRUE(b.inBounds(9, 5));
		EXPECT_FALSE(b.inBounds(10, 5));
		EXPECT_TRUE(b.inBounds(3, 9));
		EXPECT_FALSE(b.inBounds(10, 20));

		EXPECT_TRUE(b.inBounds({ 0, 0 }));
		EXPECT_TRUE(b.inBounds({ 5, 19 }));
		EXPECT_FALSE(b.inBounds({ 5, 20 }));
		EXPECT_TRUE(b.inBounds({ 9, 5 }));
		EXPECT_FALSE(b.inBounds({ 10, 5 }));
		EXPECT_TRUE(b.inBounds({ 3, 9 }));
		EXPECT_FALSE(b.inBounds({ 10, 20 } ));
	}

	TEST(Board, AddTile)
	{
		Board b{ 10,20 };
		b.addTile(0, 0, 1.f, TileType::WALL, "../SimpleMiniGame/img/wall.png");
		b.addTile(0, 1, 1.f, TileType::CORRIDOR, "../SimpleMiniGame/img/floor.png");


		EXPECT_EQ(b.getNumTiles(), 2);
		auto t00 = b[{0, 0}];
		EXPECT_EQ(t00->x(), 0);
		EXPECT_EQ(t00->y(), 0);

		auto t01 = b.get(1, 0);
		EXPECT_EQ(t01->x(), 0);
		EXPECT_EQ(t01->y(), 1);
	}

}