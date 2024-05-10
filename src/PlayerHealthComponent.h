#pragma once
#ifndef PLAYER_HEALTH_COMPONENT_H_
#define PLAYER_HEALTH_COMPONENT_H_
#include "HealthComponent.h"
#include <string>

class Transform;
class UIManager;
class LevelManager;

class PlayerHealthComponent : public HealthComponent {
private:
	std::string kelpBlueprint;
	Transform* transform;
	UIManager* ui;
	LevelManager* level;
	int maxKelpsSpawned;
	float invulnerabilityTime;
	float invulnerability;
public:

	static const std::string id;

#pragma region Constructoras
	PlayerHealthComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Health cuando se activa
	/// </summary>
	/// <returns> True si se ha inicializado correctamente</returns>
	/// <param name="data"> Datos del componente</param>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Si ha recibido daño, suelta todas las algas que lleva. Si no llevaba algas o ha recibido daño letal (100 o mas), muere
	/// </summary>
	/// <param name="damage"> Daño recibido</param>
	void damage(int damage) override;

	/// <summary>
	/// Suelta todas las algas que lleva o hasta un maximo si lleva mas de maxKelpsSpawned
	/// </summary>
	void dropKelps();

	/// <summary>
	/// Suma kelps (vida) al jugador
	/// </summary>
	/// <param name="kelp"> Numero de kelps a sumar</param>
	void addKelp(int kelp);

	/// <summary>
	/// Realiza los procesos necesarios para la muerte del jugador
	/// </summary>
	void death();
};

#endif //PLAYER_HEALTH_COMPONENT_H_