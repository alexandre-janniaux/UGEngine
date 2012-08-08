#include <UGEngine/Entity/Message/Die.hpp>
#include <UGEngine/Entity/Core/Entity.hpp>

namespace uge {

DieMessage::DieMessage(Entity& entity) : 
	m_entity (entity)
{
}

Entity& DieMessage::getEntity() {
	return m_entity;
}

}