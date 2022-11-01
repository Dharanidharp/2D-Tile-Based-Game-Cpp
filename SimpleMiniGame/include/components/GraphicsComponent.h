#pragma once
#include "../graphics/SpriteSheet.h"
#include "../utils/Rectangle.h"
#include "Components.h"

class Entity;
class Window;
class Player;

class GraphicsComponent : public Component
{
public:
	virtual const ComponentID getID() const { return ComponentID::GRAPHICS; }
	
	GraphicsComponent() : isSpriteSheet{ false } {}
	virtual ~GraphicsComponent() {}

	virtual void init(const std::string& File) {}
	virtual void setPosition(Vector2f position) = 0;
	virtual const sf::Vector2f& getSpriteScale() const = 0;
	virtual const sf::Vector2i& getTextureSize() const = 0;
	virtual const Direction& getSpriteDirection() const = 0;
	virtual const std::string& getAnimName() const = 0;
	virtual bool isInAction() const = 0;
	virtual bool isPlaying() const = 0;

	bool isSpriteSheetEntity() const { return isSpriteSheet; }
	const Vector2f& getBBoxSize() const { return bBoxSize; }

protected:
	bool isSpriteSheet;
	Vector2f bBoxSize;
};

class SpriteSheetGraphics : public GraphicsComponent 
{
public:
	SpriteSheetGraphics() { isSpriteSheet = true; }
	~SpriteSheetGraphics() {}

	virtual void init(const std::string& spriteSheetFile) override;
	virtual void setPosition(Vector2f position) override;
	virtual const sf::Vector2f& getSpriteScale() const override;
	virtual const sf::Vector2i& getTextureSize() const override;
	virtual const Direction& getSpriteDirection() const override;
	virtual const std::string& getAnimName() const override;
	virtual bool isInAction() const override;
	virtual bool isPlaying() const override;
	SpriteSheet& getSpriteSheet() { return spriteSheet; }

private:
	SpriteSheet spriteSheet;
};

class SimpleSpriteGraphics : public GraphicsComponent 
{
public:
	SimpleSpriteGraphics(float val) : scale{ val } {}
	~SimpleSpriteGraphics() {}

	virtual void init(const std::string& textureFile) override;
	virtual const sf::Vector2f& getSpriteScale() const override;
	virtual const sf::Vector2i& getTextureSize() const override { return textureSize; }
	virtual const Direction& getSpriteDirection() const override { throw std::runtime_error("Sprite"); }
	virtual void setPosition(Vector2f position) override;
	virtual const std::string& getAnimName() const override { throw std::runtime_error("Sprite"); }
	virtual bool isInAction() const override { throw std::runtime_error("Sprite"); }
	virtual bool isPlaying() const override { throw std::runtime_error("Sprite"); }
	sf::Sprite& getSprite() { return sprite; }

private:
	sf::Texture texture;
	sf::Vector2i textureSize;
	sf::Sprite sprite;
	float scale;
};