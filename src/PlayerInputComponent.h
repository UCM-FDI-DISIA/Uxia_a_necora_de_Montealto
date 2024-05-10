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

#pragma region Constructoras
	PlayerInputComponent();
#pragma endregion


#pragma region Getters/Setters

	/// <summary>
	/// Setea si el jugador esta atacando o no
	/// </summary>
	/// <param name="attack">Si el jugador esta atacando o no</param>
	void setAttacking(bool attack);

	/// <summary>
	/// Setea si el jugador esta muerto o no
	/// </summary>
	/// <param name="isDead">Si el jugador esta muerto o no</param>
	void setDead(bool isDead);
#pragma endregion

	/// <summary>
	/// Inicializa el componente PlayerInput
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Comprueba la entrada del jugador y mueve al jugador en consecuencia
	/// </summary>
	void update() override;

};
#endif // !PLAYER_INPUT_CONTROLLER_H
