#pragma once

#include <UGEngine/EntityComponents/Component.hpp>
#include <UGEngine/EntityComponents/Entity.hpp>

namespace uge {

template <typename T>
MessageHandler<T>::MessageHandler(Entity& entity) : 
	m_messageEntity(entity) 
{
}

template <typename T>
Entity& MessageHandler<T>::getMessageEntity() {
	return m_messageEntity;
}

////////////////////////////////////////////////////////////
/// Bind a message type to another destination
////////////////////////////////////////////////////////////
template <typename T>
void MessageHandler<T>::bind(MessageHandler<T>& destination) {

}

} // namespace uge