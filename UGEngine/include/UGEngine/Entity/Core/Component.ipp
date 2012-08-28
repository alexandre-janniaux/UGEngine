#pragma once

#include <UGEngine/Entity/Core/Entity.hpp>
#include <UGEngine/Entity/Core/MessageHandler.hpp>

namespace uge {

////////////////////////////////////////////////////////////
/// broadcast a message to the owner composant's entity with a message and its parameters
////////////////////////////////////////////////////////////
template <typename T>
void Component::broadcastToEntity(Entity& entity, T& message) {
	entity.broadcast (message, this); 
}


////////////////////////////////////////////////////////////
/// Broadcast a message to the connected components
////////////////////////////////////////////////////////////
template <typename T>
void Component::broadcast(T& message) {
	ComponentImpl<T>::get(*this)->broadcast(message, this);
}

////////////////////////////////////////////////////////////
/// Bind a message type to another destination
////////////////////////////////////////////////////////////
template <typename T>
void Component::bind(MessageHandler<T>& destination) {
	ComponentImpl<T>::get(*this)->bind(destination);
}

} // namespace uge
