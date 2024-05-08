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

	UIManager();
	bool initComponent(ComponentData* data) override;

	void updateKelpText(int kelp);
	void enableDeathText(bool enabled);

};

#endif // !UI_MANAGER_H_