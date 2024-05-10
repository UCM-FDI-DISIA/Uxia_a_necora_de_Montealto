#pragma once
#include <Component.h>
class AudioSource;

class ButtonSoundComponent : public Component {
protected:
	AudioSource* audioComponent;
public:
	static const std::string id;

#pragma region Constructoras
	ButtonSoundComponent();
	~ButtonSoundComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente ButtonSound
	/// </summary>
	/// <param name="data"> Datos del componente</param>
	/// <returns> True si se ha inicializado correctamente</returns>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Reproduce el sonido del boton
	/// </summary>
	void playClicked();
};