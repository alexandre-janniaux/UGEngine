#pragma once

#include <UGEngine/Entity/Core/Entity.hpp>
#include <UGEngine/Entity/Core/Component.hpp>

#include <UGEngine/Entity/Core/EntityImpl.hpp>

namespace uge {

template <typename T>
void Entity::broadcast (T& message, Component* source) {
	for (auto component : EntityImpl<T>::get(*this).getComponents()) {
		component->receive(message, source);
	}
}

template <typename Msg, typename T>
void Entity::bind(T& component) {
	EntityImpl<Msg>::get(*this).bind<T>(component);
}

} // namespace uge 


