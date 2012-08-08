#pragma once

#include <UGEngine/Core/Type.hpp>

#include <UGEngine/Entity/Message/Damage.hpp>
#include <UGEngine/Entity/Message/Heal.hpp>
#include <UGEngine/Entity/Message/Die.hpp>

#include <UGEngine/Entity/Core/MessageHandler.hpp>
#include <UGEngine/Entity/Core/Component.hpp>

namespace uge {

class Entity;

namespace components {

class Health : 	public Component, 
				public MessageHandler<DamageMessage>, 
				public MessageHandler<HealMessage>
{
public:	
	Health (Entity& entity, Uint32 health=0, Uint32 maxHealth=0);

	void setHealth (Uint32 value);
	Uint32 getHealth() const;

	void setMaxHealth (Uint32 value);
	Uint32 getMaxHealth () const;
 
	virtual void receive (DamageMessage& message, Component* source=nullptr);

	virtual void receive (HealMessage& message, Component* source=nullptr);
private:
	Uint32 	m_health,
			m_maxHealth;
};

} // namespace components

} // namespace uge