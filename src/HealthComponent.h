#pragma once
#ifndef HEALTH_COMPONENT_H_
#define HEALTH_COMPONENT_H_
#include <Component.h>

class HealthComponent : public Component {
protected:
	int health;
	int maxHealth;
public:

	static const std::string id;
#pragma region Constructoras
	HealthComponent();
	~HealthComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Health cuando se activa
	/// </summary>
	void onEnabled() override;
	/// <summary>
	/// Inicializa el componente Health
	/// </summary>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Reduce la vida actual en funcion del daño recibido
	/// </summary>
	/// <param name="damage"> Daño recibido</param>
	virtual void damage(int damage);
};

#endif // !HEALTH_COMPONENT_H_