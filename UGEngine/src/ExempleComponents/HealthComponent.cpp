#include <UGEngine/ExempleComponents/HealthComponent.hpp>
#include <UGEngine/MessageComponents/DamageMessage.hpp>
#include <UGEngine/MessageComponents/HealMessage.hpp>
#include <UGEngine/MessageComponents/DieMessage.hpp>

namespace uge 
{

namespace components
{

Health::Health(Entity& entity, Uint32 health, Uint32 maxHealth) : 
	Component(entity),
	MessageHandler<DamageMessage>(entity),
	MessageHandler<HealMessage>(entity),
	m_health(health), 
	m_maxHealth(maxHealth)
{
	if(m_maxHealth < m_health) // ex : maxHealth = 0
		m_maxHealth = m_health;
}

void Health::setHealth (Uint32 value) {
	this->m_health = value;
	if (m_health == 0)
	{
		broadcastToEntity<DieMessage>(getEntity(), getEntity());
	}
}

Uint32 Health::getHealth() const { 
	return this->m_health;
}


void Health::setMaxHealth (Uint32 value) {
	this->m_maxHealth = value;
}

Uint32 Health::getMaxHealth () const {
	return this->m_maxHealth;
}

void Health::receive (const DamageMessage& message, Entity& /*source*/) {
	uge::Uint32 damage = message.getDamage();
	if (this->m_health < damage)
		this->setHealth(0);
	else
		this->setHealth(this->m_health - damage);
}

void Health::receive (const HealMessage& message, Entity& /*source*/) {
	uge::Uint32 heal = message.getHeal();
	if (this->m_health + heal > this->m_maxHealth)
		setHealth(this->m_maxHealth);
	else
		setHealth(this->m_health + heal);

}

} // namespace components

} // namespace uge

