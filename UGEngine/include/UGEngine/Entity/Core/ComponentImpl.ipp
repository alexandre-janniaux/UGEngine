#include <UGEngine/Entity/Core/ComponentImpl.hpp>
#include <UGEngine/Entity/Core/Component.hpp>
#include <UGEngine/Core/DestructionTrigger.hpp>

namespace uge {

template <typename T>
std::map<Component*, ComponentImpl<T>*> ComponentImpl<T>::m_instances;

template <typename T>
void ComponentImpl<T>::onTriggerDestruction (const DestructionTrigger* trigger) {
	delete this;
}


template <typename T>
ComponentImpl<T>::ComponentImpl(Component& component) {
}


template <typename T>
void ComponentImpl<T>::bind(MessageHandler<T>& destination) {
	m_bindTable.push_back(&destination);
}

template <typename T>
void ComponentImpl<T>::broadcast(T& message, Component* source) {
	for (auto component : m_bindTable)
		component->receive(message, source);
}

template <typename T>
ComponentImpl<T>* ComponentImpl<T>::get(Component& component) {
	auto ptr = m_instances.find(&component);
	if (ptr == m_instances.end())
	{
		ComponentImpl<T>* newComponent = m_instances[&component] = new ComponentImpl<T>(component);
		return newComponent;
	}

	return ptr->second;
}

} // namespace uge