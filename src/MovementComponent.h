#pragma once
#include <Component.h>
#include <Vector3.h>

class Transform;
class RigidBody;
class MovementComponent : public Component {
private:
	Transform* transform;
	RigidBody* rigidBody;
	forge::Vector3 currentDirection;
	float nextJumpTime;
	float jumpCooldown;
	float jumpForce;

	forge::Vector3 jumpDirection;
public:
	static const std::string id;

#pragma region Constructoras
	MovementComponent();
	~MovementComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Movement
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Aplica una fuerza al objeto en la direccion indicada en el eje indicado
	/// </summary>
	void move(float direction, int axis);

	/// <summary>
	/// Aplica una fuerza hacia arriba si ha pasado el tiempo de cooldown
	/// </summary>
	void jump();

	/// <summary>
	/// Detiene el movimiento del objeto de forma linear
	/// </summary>
	void stop();

	/// <summary>
	/// Detiene el movimiento del objeto de forma brusca
	/// </summary>
	void fullStop();
};
