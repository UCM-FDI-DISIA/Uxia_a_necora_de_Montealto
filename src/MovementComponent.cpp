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
	if (rigidBody->getSpeed() < 5)
		rigidBody->applyForce(currentDirection);
	else if (currentDirection.getX() < 0)
		rigidBody->setLinearVelocity(forge::Vector3(-5, rigidBody->getLinearVelocity().getY(), 0));
	else if (currentDirection.getX() > 0)
		rigidBody->setLinearVelocity(forge::Vector3(5, rigidBody->getLinearVelocity().getY(), 0));
}

void MovementComponent::jump() {
	rigidBody->applyForce(jumpDirection);
}

void MovementComponent::stop() {/*
	rigidBody->rest();
	currentDirection.set(forge::Vector3::ZERO);*/
}