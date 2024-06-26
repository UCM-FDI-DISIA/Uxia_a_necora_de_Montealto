#pragma once
#ifndef ATTACK_COMPONENT_H_
#define ATTACK_COMPONENT_H_
#include <Component.h>
#include <Vector3.h>
#include <string>

class Collider;
class PlayerInputComponent;

class AttackComponent : public Component {
private:
	Collider* hitbox;
	PlayerInputComponent* input;
	int damage;

public:
	static const std::string id;
#pragma region Constructoras
	AttackComponent();
	~AttackComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Attack
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;
};

#endif // !ATTACK_COMPONENT_H_