#pragma once

#include <vector>

namespace uge {

class DestructionListener;

class DestructionTrigger {
public:
	virtual ~DestructionTrigger();

	void notify(DestructionListener& listener);

private:
	std::vector <DestructionListener*> m_listeners;
};

}