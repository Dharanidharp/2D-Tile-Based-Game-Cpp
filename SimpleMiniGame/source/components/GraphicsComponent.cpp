#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/PositionComponent.h"

void SpriteSheetGraphics::init(const std::string& spriteSheetFile)
{
	spriteSheet.loadSheet(spriteSheetFile);
	spriteSheet.setAnimation("Idle", true, true);
	bBoxSize = { spriteSheet.getSpriteSize().x * spriteSheet.getSpriteScale().x,
		spriteSheet.getSpriteSize().y * spriteSheet.getSpriteScale().y };
}

void SpriteSheetGraphics::setPosition(Vector2f position)
{
	spriteSheet.getSprite().setPosition(position.x, position.y);
}

const sf::Vector2f& SpriteSheetGraphics::getSpriteScale() const
{
	return spriteSheet.getSpriteScale();
}

const sf::Vector2i& SpriteSheetGraphics::getTextureSize() const
{
	return spriteSheet.getSpriteSize();
}

bool SpriteSheetGraphics::isInAction() const
{
	return spriteSheet.getCurrentAnim()->isInAction();
}

bool SpriteSheetGraphics::isPlaying() const
{
	return spriteSheet.getCurrentAnim()->isPlaying();
}

const Direction& SpriteSheetGraphics::getSpriteDirection() const
{
	return spriteSheet.getSpriteDirection();
}

const std::string& SpriteSheetGraphics::getAnimName() const
{
	return spriteSheet.getCurrentAnim()->getName();
}


void SimpleSpriteGraphics::init(const std::string& textureFile)
{
	texture.loadFromFile(textureFile);
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	isSpriteSheet = false;
	bBoxSize = { texture.getSize().x * sprite.getScale().x, texture.getSize().y * sprite.getScale().y };
	textureSize = { static_cast<int>(texture.getSize().x), static_cast<int>(texture.getSize().y) };
}

void SimpleSpriteGraphics::setPosition(Vector2f position)
{
	sprite.setPosition(position.x, position.y);
}

const sf::Vector2f& SimpleSpriteGraphics::getSpriteScale() const
{
	return sprite.getScale();
}