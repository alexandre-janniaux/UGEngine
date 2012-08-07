#pragma once

#include <UGEngine/EntityComponents/Entity.hpp>
#include <UGEngine/EntityComponents/Component.hpp>

#include <UGEngine/EntityComponents/EntitySpecialisedMessage.hpp>

namespace uge {

template <typename T, typename... Args>
void Entity::broadcast (Entity& source, Args... args) {
	T message (args...);

	for (auto component : EntitySpecialisedMessage<T>::get(*this).getComponents()) {
		if ( &source == &component->getMessageEntity()) // won't work
			continue; // bypass the component sender

		component->receive(message, source);
	}
}

/*
template <typename T, typename... MessageTypes>
void Entity::addComponent(T& component) {
	addComponentImpl<T, MessageTypes...>(component);
}
*/

template <typename Msg, typename T>
void Entity::addComponent(T& component) {
	addComponentImpl<Msg, T>(component);
}

/*
template <typename T, typename Msg, typename... Messages>
void Entity::addComponentImpl(T& component) {
	addComponentImpl<T,Msg> (component);
	addComponentImpl<T, Messages...> (component);
}
*/
template <typename Msg, typename T>
void Entity::addComponentImpl(T& component) {
	EntitySpecialisedMessage<Msg>::get(*this).addComponent<T>(component);
}

} // namespace uge 


