#include <UGEngine/MessageComponents/DieMessage.hpp>
#include <UGEngine/EntityComponents/Entity.hpp>

namespace uge {

DieMessage::DieMessage(Entity& entity) : 
	m_entity (entity)
{
}

Entity& DieMessage::getEntity() {
	return m_entity;
}

}