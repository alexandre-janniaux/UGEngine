#pragma once

#include <map>
#include <vector>

#include <UGEngine/Core/DestructionListener.hpp>

namespace uge {

template <typename t>
class MessageHandler;

class Component;


template <typename T>
class ComponentImpl : public DestructionListener {
public:

	void bind (MessageHandler<T>& destination);

	void broadcast (T& message, Component* source);

	static ComponentImpl<T>* get (Component& component); 

protected:

	virtual void onTriggerDestruction (const DestructionTrigger* trigger);

private:
	ComponentImpl(Component& component);

	std::vector<MessageHandler<T>*> m_bindTable;
	static std::map<Component*, ComponentImpl*> m_instances;
};

}

#include <UGEngine/Entity/Core/ComponentImpl.ipp>