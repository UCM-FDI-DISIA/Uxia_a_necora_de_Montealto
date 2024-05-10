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
	UpdateSeaweedComponent();
	bool initComponent(ComponentData* data) override;
};