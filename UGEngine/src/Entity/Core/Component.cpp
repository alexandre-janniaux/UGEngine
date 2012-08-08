#include <UGEngine/Entity/Core/Component.hpp>

namespace uge {

Component::Component(Entity& entity) : m_entity (entity){
}

Entity& Component::getEntity() {
	return m_entity;
}

}