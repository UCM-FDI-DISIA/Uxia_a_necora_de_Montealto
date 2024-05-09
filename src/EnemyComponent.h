#pragma once
#ifndef ENEMY_COMPONENT_H_
#define ENEMY_COMPONENT_H_
#include <Component.h>
#include <Vector3.h>

class MovementComponent;
class RigidBody;
class Transform;

class EnemyComponent : public Component {
private:
	forge::Vector3 p1; // El menor de ambos puntos
	forge::Vector3 p2; // El mayor de ambos puntos
	float sign;
	float speed;
	float damage;
	bool changeDir;
	int axis; // 0 = x, 1 = y, 2 = z
	MovementComponent* movementComponent;
	RigidBody* rb;
	Transform* transform;
public:

	static const std::string id;

	EnemyComponent();
	
	~EnemyComponent();

	/// <summary>
	/// Logica del enemigo, cambia de direccion si llega a los puntos establecidos
	/// o sigue al jugador si esta en su rango y comprueba si el enemigo debe atacar al jugador
	/// </summary>
	void update() override;

	bool initComponent(ComponentData* data) override;

	void fixedUpdate() override;
};

#endif // !ENEMY_COMPONENT_H_

