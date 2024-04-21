#include "MovementComponent.h"
#include <Transform.h>
#include <Entity.h>

MovementComponent::MovementComponent() : transform(nullptr) {}

bool MovementComponent::initComponent(ComponentData* data)
{
	if (entity->hasComponent<Transform>()) {
		transform = entity->getComponent<Transform>();
		return true;
	}
	return false;
}

void MovementComponent::moveHorizontal(float direction) {
	currentDirection = (direction, 0, 0);
	transform->movePosition(transform->getPosition()+currentDirection);
}

void MovementComponent::jump() {

}