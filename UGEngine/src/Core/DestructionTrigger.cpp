#include <UGEngine/Core/DestructionTrigger.hpp>
#include <UGEngine/Core/DestructionListener.hpp>

namespace uge {

DestructionTrigger::~DestructionTrigger() {
	for (auto listener : m_listeners)
		listener->onTriggerDestruction(this);
}

void DestructionTrigger::notify(DestructionListener& listener) {
	m_listeners.push_back(&listener);
}


}