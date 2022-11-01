#pragma once
#include "../../include/utils/Rectangle.h"
#include "Components.h"

class ColliderComponent : public Component
{
private:
	Rectangle boundingBox;
	Vector2f bBoxSize;

public:
	virtual const ComponentID getID() const { return ComponentID::COLLIDER; }
	
	Rectangle& getBoundingBox() { return boundingBox; }
	
	const Vector2f& getBBoxSize() const { return bBoxSize; }

	void setBboxSize(Vector2f size) { bBoxSize = size; }

	bool intersects(ColliderComponent* collider);
};