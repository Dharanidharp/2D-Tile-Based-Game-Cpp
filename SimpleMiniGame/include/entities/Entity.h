#pragma once
#include "../graphics/Window.h"
#include "../graphics/SpriteSheet.h"
#include "../utils/Rectangle.h"
#include "../components/Components.h"
#include "../utils/Bitmask.h"

using EntityID = unsigned int;
enum class EntityType
{
	UNDEFINED = -1,
	PLAYER = 0,
	POTION = 1,
	LOG = 2,
	FIRE = 3
};

class Game; //forward declaration
class PositionComponent;
class GraphicsComponent;
class ColliderComponent;
class TTLComponent;
class LogicComponent;
class InputComponent;
class VelocityComponent;
class Component;

class Entity
{
public:

	//Constructors and Desctrutors
	Entity();
	Entity(EntityType et);
	~Entity();
	
	//Init and update functions
	virtual void init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics);
	virtual void init(bool use, const std::string& textureFile, std::shared_ptr<GraphicsComponent> graphics);
	bool inUse() const { return isInUse; }
	
	// Object pool
	Entity* getNext() const { return next; }
	void setNext(Entity* nextEnt) { next = nextEnt; }

	//Getters and Setters
	void setID(EntityID entId) { id = entId; }
	const EntityID& getID() const { return id; }
	const sf::Vector2f& getSpriteScale();
	const sf::Vector2i& getTextureSize();
	const EntityType& getEntityType() const { return type; }
	const std::string& getAnimName();
	bool isSpriteSheetEntity();

	bool isDeleted() const { return deleted; }
	void deleteEntity() { deleted = true; }

	const Bitmask& getComponentSet() const { return componentSet; }
	void addComponent(std::shared_ptr<Component> component);
	bool hasComponent(Bitmask mask) const;
	Component* getComponentID(ComponentID id);

	void setUseBool(bool b);

protected:

	Entity* next;
	EntityType type;
	EntityID id;

	// X.A Add a bool member variable "deleted" to this class.
	bool deleted;

	Bitmask componentSet;
	std::map<ComponentID, std::shared_ptr<Component>> IDMap;
	bool isInUse;
};