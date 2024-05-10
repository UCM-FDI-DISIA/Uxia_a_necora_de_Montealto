#pragma once
#ifndef LIFETIME_COMPONENT_H_
#define LIFETIME_COMPONENT_H_
#include <Component.h>

class LifeTimeComponent : public Component {
private:
	double lifetime;

public:

	static const std::string id;

#pragma region Constructoras
	LifeTimeComponent();
	~LifeTimeComponent();
#pragma endregion

	/// <summary>
	/// Si el tiempo de vida del objeto ha terminado, lo destruye
	/// </summary>
	void update() override;
};
#endif //LIFETIME_COMPONENT_H_