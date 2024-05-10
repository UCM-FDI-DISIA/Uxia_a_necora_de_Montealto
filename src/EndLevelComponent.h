#pragma once
#include <Component.h>
#include <Vector3.h>

class Collider;
class LevelManager;

class EndLevelComponent : public Component
{
private:
	Collider* collider;
	LevelManager* level;
public:
	static const std::string id;

#pragma region Constructoras
	EndLevelComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente EndLevel
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;
};

