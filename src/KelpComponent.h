#pragma once
#ifndef KELP_COMPONENT_H_
#define KELP_COMPONENT_H_
#include <Component.h>
#include <string>

class Collider;
class GameManager;

class KelpComponent : public Component {
private:
    int score;
public:
	static const std::string id;

#pragma region Constructoras
	KelpComponent();
	~KelpComponent();
#pragma endregion

	/// <summary>
	/// Inicializa el componente Kelp
	/// </summary>
	bool initComponent(ComponentData* data) override;
};

#endif // !KELP_COMPONENT_H_