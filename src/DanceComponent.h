#pragma once
#include <Component.h>
class Transform;

class DanceComponent : public Component {
protected:
	Transform* myTransform;
	float limSup, limInf;
	float originalHeight;
	bool goingUp;

public:
	static const std::string id;

#pragma region Constructoras
	DanceComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Dance
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Actualiza la posicion del objeto dependiendo de si esta subiendo o bajando
	/// </summary>
	void update() override;
};