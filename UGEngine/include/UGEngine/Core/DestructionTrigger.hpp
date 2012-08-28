#pragma once

#include <vector>

namespace uge {

template <typename T>
class DestructionListener;

template <typename T>
class DestructionTrigger {
public:
    DestructionTrigger(T& m_instance);
	virtual ~DestructionTrigger();

	void subscribe(DestructionListener<T>& listener);

private:
	std::vector <DestructionListener<T>*> m_listeners;
	T& m_instance;
};

}

#include <UGEngine/Core/DestructionTrigger.ipp>
