#include "PlayerInputComponent.h"
#include <Input.h>
#include <Entity.h>
#include <Vector2.h>
#include "MovementComponent.h"
#include "ForgeError.h"

const std::string PlayerInputComponent::id = "PlayerInputComponent";

PlayerInputComponent::PlayerInputComponent(): 
	input(*Input::GetInstance()),
	movement(nullptr) {
}

bool PlayerInputComponent::initComponent(ComponentData* data)
{
	if (entity->hasComponent<MovementComponent>()) {
		movement = entity->getComponent<MovementComponent>();
		return true;
	}
	else {
		reportError("El componente PlayerInput necesita un componente Movement");
	}
	return false;
}

void PlayerInputComponent::update() {
	//Movimiento A / D

	if (input.keyDown(K_A)) {
		movement->moveHorizontal(-speed);
	}
	else if (input.keyDown(K_D)) {
		movement->moveHorizontal(speed);
	}

	//Salto
	if (input.keyDown(K_W)) {
		movement->jump();
	}
}