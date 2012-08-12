#include <UGEngine/Entity/Core/Component.hpp>
#include <UGEngine/Entity/Core/Entity.hpp>

namespace uge {

template <typename T>
void Broadcaster<T>::bind(MessageHandler<T>& destination) {
	this->m_listeners.push_back(&destination);
}

template <typename T>
void Broadcaster<T>::bind(Entity& entity) {
	this->m_entities.push_back(&entity);
}

template <typename T>
void Broadcaster<T>::unbind(const MessageHandler<T>& destination) {
	auto ptr = this->m_listeners.find(&destination);
	if (ptr != this->m_listeners.end())
		this->m_listeners.erase(ptr);
}

template <typename T>
void Broadcaster<T>::unbind(const Entity& entity) {
	auto ptr = this->m_entities.find(&entity);
	if (ptr != this->m_entities.end())
		this->m_entities.erase(ptr);
}

template <typename T>
void Broadcaster<T>::broadcast(T& message, Component* component) {
	for(auto listener : this->m_listeners)
		listener->receive(message, component);

	for(auto entity : this->m_entities)
		entity->broadcast(message, component);

}

template <typename T>
void Broadcaster<T>::receive (T& message, Component* component) {
	this->broadcast(message, component);
}


} // namespace uge
