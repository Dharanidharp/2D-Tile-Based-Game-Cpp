#include "../../include/components/ColliderComponent.h"

bool ColliderComponent::intersects(ColliderComponent* colliderComp)
{
	return boundingBox.intersects(colliderComp->getBoundingBox());
}