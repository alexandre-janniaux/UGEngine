#pragma once

#include <map>
#include <vector>

namespace uge {

template <typename T>
class MessageHandler;

class Entity;

template <typename T>
class EntitySpecialisedMessage  {
public:
	std::vector<MessageHandler<T>*> getComponents ();

	template <typename U>
	void addComponent(U& component);

	static EntitySpecialisedMessage<T>& get(Entity& entity);

private:
	EntitySpecialisedMessage();

	std::vector<MessageHandler<T>*> m_messagehandler;
	static std::map<Entity*, EntitySpecialisedMessage*> m_instances;
};

} // namespace uge

#include <UGEngine/EntityComponents/EntitySpecialisedMessage.ipp>