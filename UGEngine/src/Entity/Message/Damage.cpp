#include <UGEngine/Entity/Message/Damage.hpp>

namespace uge {

DamageMessage::DamageMessage(uge::Uint32 damage) :
	m_damage(damage)
{
}

uge::Uint32 DamageMessage::getDamage() const {
	return m_damage;
}

}