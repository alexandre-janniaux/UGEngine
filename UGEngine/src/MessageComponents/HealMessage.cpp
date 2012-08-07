#include <UGEngine/MessageComponents/HealMessage.hpp>

namespace uge {

HealMessage::HealMessage(uge::Uint32 heal) :
	m_heal(heal)
{
}

uge::Uint32 HealMessage::getHeal() const {
	return m_heal;
}

}