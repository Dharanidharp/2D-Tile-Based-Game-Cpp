#include "pch.h"
#include "../SimpleMiniGame/include/utils/Vector2.h"

namespace ArithmeticOperations {
	TEST(VectorOperations, Init) {
		Vector2f v1(1.0f, 2.0f);
		EXPECT_EQ(v1.x, 1.0f);
		EXPECT_EQ(v1.y, 2.0f);
	}
	TEST(VectorOperations, Empty) {
		Vector2f v1;
		EXPECT_EQ(v1.x, 0.0f);
		EXPECT_EQ(v1.y, 0.0f);
	}
	TEST(VectorOperations, Add) {
		Vector2f v1(3.0f, 5.0f);
		Vector2f v2(2.0f, 1.0f);
		Vector2f v3 = v1 + v2;
		EXPECT_EQ(v3.x, 5.0f);
		EXPECT_EQ(v3.y, 6.0f);
	}
	TEST(VectorOperations, Subtract) {
		Vector2f v1(3.0f, 5.0f);
		Vector2f v2(2.0f, 1.0f);
		Vector2f v3 = v1 - v2;
		EXPECT_EQ(v3.x, 1.0f);
		EXPECT_EQ(v3.y, 4.0f);
	}
	TEST(VectorOperations, Multiply) {
		Vector2f v1(3.0f, 5.0f);
		Vector2f v2 = v1 * 2.0f;
		EXPECT_EQ(v2.x, 6.0f);
		EXPECT_EQ(v2.y, 10.0f);
	}
	TEST(VectorOperations, Division) {
		Vector2f v1(4.0f, 6.0f);
		Vector2f v2 = v1 / 2.0f;
		EXPECT_EQ(v2.x, 2.0f);
		EXPECT_EQ(v2.y, 3.0f);
	}
	TEST(VectorOperations, Equality) {
		Vector2f v1(4.0f, 6.0f);
		Vector2f v2(2.0f, 1.0f);
		Vector2f v3(4.0f, 6.0f);
		EXPECT_FALSE(v1 == v2);
		EXPECT_TRUE(v1 == v3);
	}
	TEST(VectorOperations, Inequality) {
		Vector2f v1(4.0f, 6.0f);
		Vector2f v2(2.0f, 1.0f);
		Vector2f v3(4.0f, 6.0f);
		EXPECT_TRUE(v1 != v2);
		EXPECT_FALSE(v1 != v3);
	}
	TEST(VectorOperations, Magnitude) {
		Vector2f v1(2.0f, 3.0f);
		EXPECT_EQ(v1.magnitude(), 3.60555127546f);
	}
	TEST(VectorOperations, Normalisation) {
		Vector2f v1(3.0f, 4.0f);
		Vector2f v2(0.6f, 0.8f);
		Vector2f v3 = v1.normalized();
		EXPECT_TRUE(v3 == v2);
	}
	TEST(VectorOperations, Euclidean) {
		Vector2f v1(2.0f, 3.0f);
		Vector2f v2(3.0f, 4.0f);
		float d = abs(v1.distance(v2) - 1.41421356f);
		EXPECT_TRUE(d < 0.001);
	}
	TEST(VectorOperations, Manhattan) {
		Vector2f v1(2.0f, 3.0f);
		Vector2f v2(3.0f, 4.0f);
		EXPECT_EQ(v1.manhattanDistance(v2), 2);
	}
	TEST(VectorOperations, Chebyshev) {
		Vector2f v1(2.0f, 3.0f);
		Vector2f v2(3.0f, 4.0f);
		EXPECT_EQ(v1.chebyshevDistance(v2), 1);
	}
}