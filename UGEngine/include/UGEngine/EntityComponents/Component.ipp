#pragma once

#include <UGEngine/EntityComponents/Entity.hpp>

namespace uge {

////////////////////////////////////////////////////////////
/// broadcast a message to the owner composant's entity with a message and its parameters
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
template <typename T, typename... Args>
void Component::broadcastToEntity(Entity& entity, Args... args) {
	entity.broadcast<T, Args...> (getEntity(), args...); 
}

} // namespace uge