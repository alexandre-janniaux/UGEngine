#include <UGEngine/Entity/Core/Component.hpp>

namespace uge {

template <typename T>
void Broadcaster::bind(MessageHandler<T>& destination) {
	this->m_listeners.push_back(&destination);
}

template <typename T>
void Broadcaster::broadcast(T& message) {
	for(auto listener : this->m_listeners)
		listener->receive(message);
}

template <typename T>
void receive (T& message, Component* component) {
	this->broadcast(message, component);
}


} // namespace uge
