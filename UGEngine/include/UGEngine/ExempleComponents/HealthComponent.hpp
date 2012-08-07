#pragma once

#include <UGEngine/Core/Type.hpp>

#include <UGEngine/MessageComponents/DamageMessage.hpp>
#include <UGEngine/MessageComponents/HealMessage.hpp>

#include <UGEngine/EntityComponents/MessageHandler.hpp>

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
 
	virtual void receive (const DamageMessage& message, Entity& source);

	virtual void receive (const HealMessage& message, Entity& source);
private:
	Uint32 	m_health,
			m_maxHealth;
};

} // namespace components

} // namespace uge