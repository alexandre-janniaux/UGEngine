#pragma once

#include <string>
#include <vector>

namespace uge {

class Component;

class Entity {
public:

	Entity(const std::string& name="");

	template <typename T>
	void broadcast (T& message, Component* Component=nullptr);	

	template <typename Msg, typename T>
	void bind(T& component);

private:

	std::string m_name;
	std::vector<Component*> m_components;

};

} // namespace uge

#include <UGEngine/Entity/Core/Entity.ipp>