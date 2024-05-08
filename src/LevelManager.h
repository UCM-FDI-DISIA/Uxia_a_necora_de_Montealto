#pragma once
#ifndef LEVEL_MANAGER_H_
#define LEVEL_MANAGER_H_
#include "Component.h"
#include <string>


class LevelManager : public Component {
private:
public:
	static const std::string id;

	LevelManager();
	bool initComponent(ComponentData* data) override;
};

#endif // !LEVEL_MANAGER_H_