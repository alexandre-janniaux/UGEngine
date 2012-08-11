#pragma once

#include <UGEngine/Core/Type.hpp>

#include <UGEngine/Entity/Core/Component.hpp>
#include <UGEngine/Entity/Core/MessageHandler.hpp>

#include <UGEngine/Entity/Message/Value.hpp>

#include <map>

namespace uge {
	
class Entity;

namespace component {
	
class Fear : 
	public Component,
	public MessageHandler<ThreatMessage>
{
public:
	using FearStatutMessage = ValueMessage <Uint32, Fear>;

	Fear ();

	void setFearStatut(Entity& entity, Uint32 value);
	Uint32 getFearStatut(Entity& entity);

	virtual void receive (ThreatMessage& message, Component* component=nullptr);
	virtual void receive (AskMessage<FearStatutMessage>& message, Component* component=nullptr);
private:
	std::map<Entity*, Uint32> m_fearStatuts;
};

} // namespace component

} // namespace uge