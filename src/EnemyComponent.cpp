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
		rb->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
			Entity* player = other->getEntity();
			if (player->hasComponent<PlayerHealthComponent>()) {
				player->getComponent<PlayerHealthComponent>()->damage(0);
			}
		});
		return true;
	}
	else {
		reportError("El componente Enemy requiere un componente Transform, Rigidbody y Movement");
	}
	return false;
}
