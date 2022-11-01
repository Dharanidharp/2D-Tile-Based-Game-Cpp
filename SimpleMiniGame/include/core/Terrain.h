#pragma once
#include <SFML/Graphics/Texture.hpp>

enum class TileType {
	CORRIDOR,
	WALL
};

class Terrain 
{
public:
	Terrain(sf::Texture text) : texture(text) {}
	const sf::Texture& getTexture() const { return texture; }

private:
	sf::Texture texture;
};