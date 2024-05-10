#pragma once
#ifndef PLAYER_INPUT_CONTROLLER_H
#define PLAYER_INPUT_CONTROLLER_H

#include <Component.h>

class Input;
class MovementComponent;
class LevelManager;

class PlayerInputComponent : public Component {
private:
	Input& input;
	MovementComponent* movement;
	LevelManager* level;
	float speed;
	bool attacking;
	float attackOffset;
	short lastDirection;
	bool dead;

public:
	static const std::string id;

	PlayerInputComponent();
	bool initComponent(ComponentData* data) override;
	void update() override;

	void setAttacking(bool attack);
	void setDead(bool isDead);
};
#endif // !PLAYER_INPUT_CONTROLLER_H
