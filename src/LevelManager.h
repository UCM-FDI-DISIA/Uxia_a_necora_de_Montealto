#pragma once
#ifndef LEVEL_MANAGER_H_
#define LEVEL_MANAGER_H_
#include "Component.h"
#include <string>
#include <Vector3.h>


class LevelManager : public Component {
private:
	forge::Vector3 spawnpoint;
public:
	static const std::string id;

	LevelManager();
	bool initComponent(ComponentData* data) override;
	void setSpawnpoint(forge::Vector3);
	forge::Vector3 getSpawnpoint();
};

#endif // !LEVEL_MANAGER_H_