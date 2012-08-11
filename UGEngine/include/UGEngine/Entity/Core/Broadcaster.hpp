#pragma once

#include <vector>
#include <UGEngine/Entity/Core/MessageHandler.hpp>

namespace uge {

class Component;
class Entity;

template <typename T>
class Broadcaster : public MessageHandler<T> {
public:
	void bind(MessageHandler<T>& destination);
	void bind(Entity& destination);

	void unbind(const MessageHandler<T>& destination);
	void unbind(const Entity& destination);

	void broadcast(T& message, Component* component=nullptr);

	virtual void receive (T& message, Component* component=nullptr);

private:
	std::vector<MessageHandler<T>*> m_listeners;
	std::vector<Entity*> m_entities;
};

}

#include <UGEngine/Entity/Core/Broadcaster.ipp>