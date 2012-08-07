#pragma once

#include <UGEngine/Core/Type.hpp>

namespace uge {

class DamageMessage {
public:
	DamageMessage(uge::Uint32 damage);

	uge::Uint32 getDamage() const;

private:
	uge::Uint32 m_damage;

};

}