#pragma once

#include <map>
#include <vector>

namespace uge {

template <typename T>
class MessageHandler;

class Entity;

template <typename T>
class EntityImpl  {
public:
	std::vector<MessageHandler<T>*> getComponents ();

	template <typename U>
	void bind(U& component);

	static EntityImpl<T>& get(Entity& entity);

private:
	EntityImpl();

	std::vector<MessageHandler<T>*> m_messagehandler;
	static std::map<Entity*, EntityImpl*> m_instances;
};

} // namespace uge

#include <UGEngine/Entity/Core/EntityImpl.ipp>