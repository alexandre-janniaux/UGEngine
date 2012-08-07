#include <UGEngine/EntityComponents/Component.hpp>

namespace uge {

Component::Component(Entity& entity) : m_entity (entity){
}

Component::~Component() {}

Entity& Component::getEntity() {
	return m_entity;
}

}