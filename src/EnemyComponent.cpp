#include "EnemyComponent.h"
#include "MovementComponent.h"
#include "PlayerHealthComponent.h"
#include <TimeForge.h>
#include <RigidBody.h>
#include <Entity.h>
#include <Serializer.h>
#include <Transform.h>
#include <Collider.h>
#include <Scene.h>
#include <AudioSource.h>


const std::string EnemyComponent::id = "EnemyComponent";


EnemyComponent::EnemyComponent() :
	sign(1),
	damage(1),
	movementComponent(nullptr),
	rb(nullptr),
	transform(nullptr),
	audio(nullptr),
	p1(forge::Vector3::ZERO),
	p2(forge::Vector3::ZERO),
	changeDir(false),
	speed(0),
	axis(0) {
	serializer(p1, "p1");
	serializer(p2, "p2");
	serializer(speed, "speed");
	serializer(damage, "damage");
	serializer(axis, "axis");
}

void EnemyComponent::update() {
	//Merodeo
	if(movementComponent != nullptr){
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
}

bool EnemyComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Transform>()) {
		transform = entity->getComponent<Transform>();
		if(entity->hasComponent<RigidBody>() && entity->hasComponent<MovementComponent>()){			
			rb = entity->getComponent<RigidBody>();
			movementComponent = entity->getComponent<MovementComponent>();
			rb->setGravity(forge::Vector3(0, 0, 0));
			movementComponent->move(speed * sign, axis);
			rb->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
				Entity* player = other->getEntity();
				if (player->hasComponent<PlayerHealthComponent>()) {
					player->getComponent<PlayerHealthComponent>()->damage(damage);
				}
			});
			if (entity->hasComponent<AudioSource>()) {
				audio = entity->getComponent<AudioSource>();
			}
			return true;
		}
	}
	else {
		reportError("El componente Enemy requiere un componente Transform, Rigidbody y Movement");
	}
	return false;
}

void EnemyComponent::fixedUpdate() {
	// Cambio de direccion al llegar a un borde
	if (movementComponent != nullptr && changeDir) {
		movementComponent->fullStop();
		changeDir = false;
		movementComponent->move(speed * sign, axis);
	}
}

void EnemyComponent::onEnabled() {
	changeDir = true;
}

void EnemyComponent::onDeath()
{
	if (audio != nullptr) {
		audio->play();
	}
	entity->setAlive(false);
}
