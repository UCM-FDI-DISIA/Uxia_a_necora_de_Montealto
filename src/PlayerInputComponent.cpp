#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "LevelManager.h"
#include <Input.h>
#include <Scene.h>
#include <Entity.h>
#include <Vector2.h>
#include <ForgeError.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <Transform.h>

const std::string PlayerInputComponent::id = "PlayerInputComponent";

PlayerInputComponent::PlayerInputComponent(): 
	input(*Input::GetInstance()),
	movement(nullptr),
	level(nullptr),
	attacking(false),
	dead(false),
	attackOffset(2),
	speed(1),
	lastDirection(1) {
	serializer(speed, "speed");
	serializer(attackOffset, "attackOffset");
}

bool PlayerInputComponent::initComponent(ComponentData* data)
{
	if (!entity->hasComponent<MovementComponent>()) {
		throwError(false, "El componente PlayerInput necesita un componente Movement");
	}
	movement = entity->getComponent<MovementComponent>();
	Entity* manager = scene->getEntityByHandler("manager");
	if (manager != nullptr) {
		level = manager->getComponent<LevelManager>();
		if (level != nullptr) {
			return true;
		}
	}
	throwError(false, "No se han encontrado los Managers");
}

void PlayerInputComponent::update() {
	if (!dead) {

		if (input.keyUp(K_A) || input.keyUp(K_D)) {
			movement->stop();
		}

		if (input.keyPressed(K_A)) {
			movement->move(-speed, 0);
			lastDirection = -1;
		}
		else if (input.keyPressed(K_D)) {
			movement->move(speed, 0);
			lastDirection = 1;
		}
		if (input.keyDown(K_W)) {
			movement->jump();
		}
		if (input.keyPressed(K_SPACE) && !attacking) {
			forge::Vector3 offset = forge::Vector3(attackOffset, 0, 0) * lastDirection;
			sceneManager.instantiateBlueprint("Attack", offset, entity);
			attacking = true;
		}		
		if (input.keyUp(K_ESC)) {
			level->setPauseMenu();
		}
	}
	else {
		if (input.keyDown(K_SPACE)) {
			level->spawn();
		}
	}
}

void PlayerInputComponent::setAttacking(bool attack) {
	attacking = attack;
}

void PlayerInputComponent::setDead(bool isDead) {
	dead = isDead;
}