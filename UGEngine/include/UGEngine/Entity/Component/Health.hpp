#pragma once

#include <UGEngine/Core/Type.hpp>

#include <UGEngine/Entity/Message/Damage.hpp>
#include <UGEngine/Entity/Message/Heal.hpp>
#include <UGEngine/Entity/Message/Die.hpp>

#include <UGEngine/Entity/Core/MessageHandler.hpp>
#include <UGEngine/Entity/Core/Component.hpp>

namespace uge {

class Entity;

namespace component {

template <typename T>
class Health : 	public Component, 
				public MessageHandler<DamageMessage<T>>, 
				public MessageHandler<HealMessage<T>>
{
public:	
	Health (Entity& entity, T health=0, T maxHealth=0);

	void setHealth (T value);
	T getHealth() const;

	void setMaxHealth (T value);
	T getMaxHealth () const;
 
	virtual void receive (DamageMessage<T>& message, Component* source=nullptr);

	virtual void receive (HealMessage<T>& message, Component* source=nullptr);
private:
	T 		m_health,
			m_maxHealth;
};

} // namespace component

} // namespace uge


#include <UGEngine/Entity/Component/Health.ipp>

