#include "EnemyComponent.h"
#include "MovementComponent.h"
#include "PlayerHealthComponent.h"
#include <TimeForge.h>
#include <RigidBody.h>
#include <Entity.h>
#include <Serializer.h>
#include <Transform.h>
#include <Scene.h>


const std::string EnemyComponent::id = "EnemyComponent";


EnemyComponent::EnemyComponent() :
	radius(0),
	sign(1),
	damage(1),
	movementComponent(nullptr),
	uxiaHealthComponent(nullptr),
	rb(nullptr),
	transform(nullptr),
	p1(forge::Vector3::ZERO),
	p2(forge::Vector3::ZERO),
	speed(0),
	changeDir(false),
	axis(0),
	cooldown(0),
	timeBetweenHits(0.25),
	uxia(nullptr){
	serializer(p1, "p1");
	serializer(p2, "p2");
	serializer(radius, "radius");
	serializer(speed, "speed");
	serializer(damage, "damage");
	serializer(axis, "axis");
	serializer(timeBetweenHits, "cooldown");
}

EnemyComponent::~EnemyComponent() {

}

void EnemyComponent::update() {
	cooldown += (float) forge::Time::deltaTime;
	//Merodeo
	switch (axis) {
		case 1:
			if (transform->getGlobalPosition().getY() >= p2.getY()) {	
				changeDir = true;
				sign = -1;
			}
			else if (transform->getGlobalPosition().getY() <= p1.getY()) {
				changeDir = true;
				sign = 1;
			}
			break;
		case 2:
			if (transform->getGlobalPosition().getZ() >= p2.getZ()) {
				changeDir = true;
				sign = -1;
			}
			else if (transform->getGlobalPosition().getZ() <= p1.getZ()) {
				changeDir = true;
				sign = 1;
			}
			break;
		default:
			if (transform->getGlobalPosition().getX() >= p2.getX()) {
				changeDir = true;
				sign = -1;
			}
			else if (transform->getGlobalPosition().getX() <= p1.getX()) {
				changeDir = true;
				sign = 1;
			}
			break;
	}
}

void EnemyComponent::fixedUpdate() {
	// Cambio de direccion al llegar a un borde
	if (changeDir) {
		movementComponent->stop();
		changeDir = false;
		movementComponent->move(speed * sign, axis);
	}
	//Comprobacion de ataque
	if (checkAttack()) {
		attack();
	}
}

bool EnemyComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Transform>() && entity->hasComponent<RigidBody>()
		&& entity->hasComponent<MovementComponent>()) {
		transform = entity->getComponent<Transform>();
		rb = entity->getComponent<RigidBody>();
		movementComponent = entity->getComponent<MovementComponent>();
		rb->setGravity(forge::Vector3(0, 0, 0));
		movementComponent->move(speed * sign, axis);
		uxia = scene->getEntityByHandler("Player");
		uxiaHealthComponent = uxia->getComponent<PlayerHealthComponent>();
		return true;
	}
	else {
		reportError("El componente Enemy requiere un componente Transform, Rigidbody y Movement");
	}
	return false;
}

bool EnemyComponent::checkAttack() {
	if (cooldown > timeBetweenHits && rb->hasCollidedWith(uxia)) {
		return true;
	}
	return false;
}

void EnemyComponent::attack() {
	cooldown = 0;
	uxiaHealthComponent->damage(0);
	//std::cout << "enemigo\n";
}