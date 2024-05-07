#pragma once
#include <Component.h>
#include <Vector3.h>

class PlayerHealthComponent;
class MovementComponent;
class RigidBody;
class Transform;

class EnemyComponent : public Component {
private:
	forge::Vector3 p1; // El menor de ambos puntos
	forge::Vector3 p2; // El mayor de ambos puntos
	float sign;
	float radius;
	float speed;
	float damage;
	bool changeDir;
	int axis; // 0 = x, 1 = y, 2 = z
	PlayerHealthComponent* uxiaHealthComponent;
	MovementComponent* movementComponent;
	RigidBody* rb;
	Transform* transform;
	Entity* uxia;
public:

	static const std::string id;

	EnemyComponent();
	
	~EnemyComponent();

	/// <summary>
	/// Logica del enemigo, cambia de direccion si llega a los puntos establecidos
	/// o sigue al jugador si esta en su rango y comprueba si el enemigo debe atacar al jugador
	/// </summary>
	void update() override;

	/// <summary>
	/// Movimiento y comprobacion de ataque
	/// </summary>
	void fixedUpdate() override;

	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Comprueba si el enemigo choca con Uxia
	/// </summary>
	bool checkAttack();

	/// <summary>
	/// Restar vida a Uxia
	/// </summary>
	void attack();

};

