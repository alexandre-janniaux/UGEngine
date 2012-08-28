#include <UGEngine/Core/DestructionTrigger.hpp>
#include <UGEngine/Core/DestructionListener.hpp>

namespace uge {

template <typename T>
DestructionTrigger<T>::DestructionTrigger(T& instance) : m_instance(instance) {}

template <typename T>
DestructionTrigger<T>::~DestructionTrigger() {
	for (auto listener : m_listeners)
		listener->onTriggerDestruction(&m_instance);
}

template <typename T>
void DestructionTrigger<T>::subscribe(DestructionListener<T>& listener) {
	m_listeners.push_back(&listener);
}


}
