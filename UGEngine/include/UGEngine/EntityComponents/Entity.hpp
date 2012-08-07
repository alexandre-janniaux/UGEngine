#pragma once

#include <string>
#include <vector>

namespace uge {

class Component;

class Entity {
public:

	Entity(const std::string& name="");

	template <typename T, typename... Args>
	void broadcast (Entity& Component, Args... args);	
/*
	template <typename T, typename... Messages>
	void addComponent(T& component);
//*/
	template <typename Msg, typename T>
	void addComponent(T& component);

private:
/*
	template <typename Msg, typename T, typename... Messages>
	void addComponentImpl(T& component);
//*/
	template <typename Msg, typename T>
	void addComponentImpl(T& component);

	std::string m_name;
	std::vector<Component*> m_components;

};

} // namespace uge

#include <UGEngine/EntityComponents/Entity.ipp>