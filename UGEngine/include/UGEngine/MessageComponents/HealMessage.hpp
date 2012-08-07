#pragma once

#include <UGEngine/Core/Type.hpp>

namespace uge {

class HealMessage {
public:
	HealMessage(uge::Uint32 health);

	uge::Uint32 getHeal() const;

private:
	uge::Uint32 m_heal;

};

} // namespace uge