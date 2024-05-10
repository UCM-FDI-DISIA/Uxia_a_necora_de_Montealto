#pragma once
#ifndef UI_MANAGER_H_
#define UI_MANAGER_H_
#include "Component.h"
#include <string>

class Text;

class UIManager : public Component {
private:
    Text* kelpText;
	Text* deathText;
public:
	static const std::string id;

#pragma region Constructoras
	UIManager();
#pragma endregion

	/// <summary>
	/// Inicializa el componente UIManager
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Actualiza el texto de las algas en funcion de las algas que tenga el jugador
	/// </summary>
	/// <param name="kelp"> Algas que tiene el jugador</param>
	void updateKelpText(int kelp);

	/// <summary>
	/// Activa o desactiva el texto de las algas
	/// </summary>
	/// <param name="enabled"> Si se activa o desactiva</param>
	void enableKelpText(bool enabled);

	/// <summary>
	/// Activa o desactiva el texto de muerte
	/// </summary>
	/// <param name="enabled"> Si se activa o desactiva</param>
	void enableDeathText(bool enabled);

};

#endif // !UI_MANAGER_H_