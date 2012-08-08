#pragma once

#include <vector>
#include <UGEngine/Entity/Core/MessageHandler.hpp>

namespace uge {

class Component;

template <typename T>
class Broadcaster : public MessageHandler<T> {
public:
	void bind(MessageHandler<T>& destination);

	void broadcast(T& message);

	virtual void receive (T& message, Component* component);

private:
	std::vector<MessageHandler<T>*> m_listeners;
};

}

#include <UGEngine/Entity/Core/Broadcaster.ipp>