#pragma once
#include "Component.h"
class LevelManager;
class Text;

class UpdateSeaweedComponent : public Component {
protected:
	LevelManager* levelManager;
	Text* myText;
public:
	static const std::string id;

#pragma region Constructoras
	UpdateSeaweedComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente UpdateSeaweed
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;
};