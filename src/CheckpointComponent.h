#pragma once
#include <Component.h>
#include <Vector3.h>

class Collider;
class LevelManager;

class CheckpointComponent : public Component
{
private:
	forge::Vector3 respawnpoint;
	Collider* collider;
	LevelManager* level;
public:
	static const std::string id;

#pragma region Constructoras
	CheckpointComponent();
	~CheckpointComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Checkpoint		
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;
};
