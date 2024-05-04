#pragma once
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
	float radius;
	float speed;
	bool changeDir;
	int axis; // 0 = x, 1 = y, 2 = z
	//HealthComponent* healthComponent;
	MovementComponent* movementComponent;
	//AttackComponent* attackComponent;
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

	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Comprueba si el enemigo choca con Uxia
	/// </summary>
	bool checkAttack();

	/// <summary>
	/// Restar vida a Uxia
	/// </summary>
	void attack();

	void setRadius(float r);

};

