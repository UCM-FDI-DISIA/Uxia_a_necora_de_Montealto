#pragma once
#ifndef LEVEL_MANAGER_H_
#define LEVEL_MANAGER_H_
#include "Component.h"
#include <string>
#include <Vector3.h>


class LevelManager : public Component {
private:
	std::string mainMenu;
	std::string pauseMenu;
	std::vector<std::string> levels;
	forge::Vector3 spawnpoint;
	int currentLevel;
public:
	static const std::string id;

	LevelManager();
	bool initComponent(ComponentData* data) override;
	
	void changeLevel(int level);
	int getLevel();

	void returnToLevel();
	void setMainMenu();
	void setPauseMenu();

	void setSpawnpoint(forge::Vector3);
	forge::Vector3 getSpawnpoint();
};

#endif // !LEVEL_MANAGER_H_