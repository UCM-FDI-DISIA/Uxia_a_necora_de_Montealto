#pragma once
#ifndef ENEMY_COMPONENT_H_
#define ENEMY_COMPONENT_H_
#include <Component.h>
#include <Vector3.h>

class MovementComponent;
class RigidBody;
class Transform;
class Collider;
class AudioSource;
class EnemyComponent : public Component {
private:
	/// <summary>
	/// El menor de los dos puntos
	/// </summary>
	forge::Vector3 p1; 
	/// <summary>
	/// El mayor de los dos puntos
	/// </summary>
	forge::Vector3 p2; 
	float sign;
	float speed;
	int damage;
	bool changeDir;
	/// <summary>
	/// 0 = x, 1 = y, 2 = z
	/// </summary>
	int axis;
	MovementComponent* movementComponent;
	RigidBody* rb;
	Transform* transform;
	AudioSource* audio;

public:

	static const std::string id;
#pragma region Constructoras
	EnemyComponent();
#pragma endregion

	/// <summary>
	/// Logica del enemigo, cambia de direccion si llega a los puntos establecidos
	/// </summary>
	void update() override;

	/// <summary>
	/// Inicializa el componente Enemy
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Actualiza el componente Enemy. Si tiene que cambiar de direccion detiene el movimiento y ejerce una fuerza en la direccion contraria
	/// </summary>
	void fixedUpdate() override;
	/// <summary>
	/// Activa el flag para mover el Rigidbody
	/// </summary>
	void onEnabled() override;

	/// <summary>
	/// Realiza los procesos necesarios al morir el enemigo
	/// </summary>
	void onDeath();
};

#endif // !ENEMY_COMPONENT_H_

