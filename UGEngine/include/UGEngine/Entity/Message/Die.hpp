#pragma once

namespace uge {

class Entity;

class DieMessage {
public:
	DieMessage(Entity& entity);

	Entity& getEntity();

private:
	Entity& m_entity;

};

} // namespace uge