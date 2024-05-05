#include "MovementComponent.h"
#include <Transform.h>
#include <RigidBody.h>
#include <Entity.h>
#include <Serializer.h>


const std::string MovementComponent::id = "MovementComponent";


MovementComponent::MovementComponent() : transform(nullptr), rigidBody(nullptr), jumpForce(1) {
	currentDirection = forge::Vector3();
	jumpDirection = forge::Vector3();
	serializer(jumpForce, "jumpForce");
}

bool MovementComponent::initComponent(ComponentData* data) {
	jumpDirection.set(0, jumpForce, 0);
	if (entity->hasComponent<Transform>()&&entity->hasComponent<RigidBody>()) {
		transform = entity->getComponent<Transform>();
		rigidBody = entity->getComponent<RigidBody>();
		return true;
	}
	return false;
}

void MovementComponent::move(float direction, int axis) {
	switch (axis)
	{
		case 1:
			currentDirection.set(0, direction, 0);
			break;
		case 2:
			currentDirection.set(0, 0, direction);
			break;
		default: 
			currentDirection.set(direction, 0, 0);
			break;
	}
	rigidBody->applyForce(currentDirection);	
}

void MovementComponent::jump() {
	rigidBody->applyForce(jumpDirection);
}

void MovementComponent::stop() {
	rigidBody->clearForces();
	currentDirection.set(forge::Vector3::ZERO);
}