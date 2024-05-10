#pragma once
#include <Component.h>
class AudioSource;

class ButtonSoundComponent : public Component {
protected:
	AudioSource* audioComponent;
public:
	static const std::string id;

	ButtonSoundComponent();

	bool initComponent(ComponentData* data) override;

	void playClicked();
};