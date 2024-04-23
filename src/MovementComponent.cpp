#include "MovementComponent.h"
#include <Transform.h>
#include <Entity.h>

const std::string MovementComponent::id = "MovementComponent";


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
	currentDirection = forge::Vector3(direction, 0, 0);
	transform->movePosition(transform->getPosition()+currentDirection);
}

void MovementComponent::jump() {

}