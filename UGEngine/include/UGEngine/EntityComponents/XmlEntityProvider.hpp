#pragma once

#include <vector>

class Component;

////////////////////////////////////////////////////////////
// Not used yet
class DataDrivenEntity {
////////////////////////////////////////////////////////////
public:

	////////////////////////////////////////////////////////////
	void registerComponent (Component& component);

////////////////////////////////////////////////////////////
private:

	std::vector<Component*>	m_components; /// List of all components

};