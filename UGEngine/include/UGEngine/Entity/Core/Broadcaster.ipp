#include <UGEngine/Entity/Core/Component.hpp>
#include <UGEngine/Entity/Core/Entity.hpp>

namespace uge {

template <typename T>
void Broadcaster::bind(MessageHandler<T>& destination) {
	this->m_listeners.push_back(&destination);
}

template <typename T>
void Broadcaster::bind(Entity& entity) {
	this->m_entities.push_back(&entity);
}

template <typename T>
void Broadcaster::unbind(MessageHandler<T>& destination) {
	auto ptr = this->m_listeners.find(&destination);
	if (ptr != this->m_listeners.end())
		this->m_listeners.erase(ptr);
}

template <typename T>
void Broadcaster::unbind(Entity& entity) {
	auto ptr = this->m_entities.find(&entity);
	if (ptr != this->m_entities.end())
		this->m_entities.erase(ptr);
}

template <typename T>
void Broadcaster::broadcast(T& message, Component* component) {
	for(auto listener : this->m_listeners)
		listener->receive(message, component);

	for(auto entity : this->m_entities)
		entity->broadcast(message, component)

}

template <typename T>
void receive (T& message, Component* component) {
	this->broadcast(message, component);
}


} // namespace uge
