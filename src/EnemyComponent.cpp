#include "EnemyComponent.h"
#include "MovementComponent.h"
#include <RigidBody.h>
#include <Entity.h>
#include <Serializer.h>
#include <Transform.h>
#include <Scene.h>


const std::string EnemyComponent::id = "EnemyComponent";


EnemyComponent::EnemyComponent() :
	radius(0),
	sign(1),
	movementComponent(nullptr),
	rb(nullptr),
	transform (nullptr),
	p1(forge::Vector3::ZERO),
	p2(forge::Vector3::ZERO),
	speed(0),
	changeDir(false){
	serializer(p1, "p1");
	serializer(p2, "p2");
	serializer(radius, "radius");
	serializer(speed, "speed");
}

EnemyComponent::~EnemyComponent() {

}

void EnemyComponent::update() {
	//Merodeo
	if (p1.getX() >= transform->getGlobalPosition().getX()) {
		changeDir = true;
		rb->setPositionX(p1.getX());
		sign = 1;
	}
	if (p2.getX() <= transform->getGlobalPosition().getX()) {
		changeDir = true;
		rb->setPositionX(p2.getX());
		sign = -1;
	}

	/* // Movimiento cuando el player esta cerca
	float distance = movementComponent->getTransform()->getPosition().getX() -
	uxia->movementComponent->transform->getPosition().getX();
	if ((abs)distance <= radius && radius != 0) {
		changeDir = true;
		if (distance >= 0) {
			sign = 1;
		}
		else {
			sign = -1;
		}
	}
	*/

	//std::cout << transform->getGlobalPosition().getX() << " " 
	//	<< transform->getGlobalPosition().getY() << " " 
	//	<< transform->getGlobalPosition().getZ() << "\n";
}

void EnemyComponent::fixedUpdate() {
	// Cambio de direccion al llegar a un borde
	if (changeDir) {
		rb->clearForces();
		changeDir = false;
		movementComponent->moveHorizontal(speed * sign);
	}
	//Comprobacion de ataque
	uxia = scene->getEntityByHandler("uxia");
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
		movementComponent->moveHorizontal(speed * sign);
		uxia = scene->getEntityByHandler("uxia");
		return true;
	}
	else {
		reportError("El componente Enemy requiere un componente Transform, Rigidbody y Movement");
	}
	return false;
}

bool EnemyComponent::checkAttack() {
	//if (rb->hasCollidedWith(uxia)) {
	//	return true;
	//}
	return false;
}

void EnemyComponent::attack() {
	//uxia->healthComponent()->damage();
	//std::cout << "damages\n";
}

void EnemyComponent::setRadius(float r) {
	radius = r;
}
