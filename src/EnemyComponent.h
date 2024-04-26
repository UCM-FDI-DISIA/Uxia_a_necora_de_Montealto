#pragma once
#include <Component.h>
#include <Vector3.h>
#include <Transform.h>

class MovementComponent;
class RigidBody;

class EnemyComponent : public Component {
private:
	forge::Vector3 p1;
	forge::Vector3 p2;
	float sign;
	float radius;
	//HealthComponent* healthComponent;
	MovementComponent* movementComponent;
	//AttackComponent* attackComponent;
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

