#include <UGEngine/Entity/Component/Health.hpp>

namespace uge 
{

namespace component
{
 
template <typename T>
Health<T>::Health(Entity& entity, T health, T maxHealth) : 
	Component(entity),
	m_health(health), 
	m_maxHealth(maxHealth)
{
	if(m_maxHealth < m_health) // ex : maxHealth = 0
		m_maxHealth = m_health;
}

template <typename T>
void Health<T>::setHealth (T value) {
	this->m_health = value;
	if (m_health == 0)
	{
		DieMessage<Entity&> msg(getEntity());
		broadcast( msg );
	}
}

template <typename T>
T Health<T>::getHealth() const { 
	return this->m_health;
}


template <typename T>
void Health<T>::setMaxHealth (T value) {
	this->m_maxHealth = value;
}

template <typename T>
T Health<T>::getMaxHealth () const {
	return this->m_maxHealth;
}

template <typename T>
void Health<T>::receive (DamageMessage<T>& message) {
	T damage = message.getValue();
	if (this->m_health < damage)
		this->setHealth(0);
	else
		this->setHealth(this->m_health - damage);
}

template <typename T>
void Health<T>::receive (HealMessage<T>& message) {
	T heal = message.getValue();
	if (this->m_health + heal > this->m_maxHealth)
		setHealth(this->m_maxHealth);
	else
		setHealth(this->m_health + heal);
}

} // namespace component

} // namespace uge

