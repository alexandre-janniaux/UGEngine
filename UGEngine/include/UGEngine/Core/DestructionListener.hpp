#pragma once

namespace uge {
	
class DestructionTrigger;

class DestructionListener {
protected:
	virtual void onTriggerDestruction(const DestructionTrigger* trigger) =0;
	friend class DestructionTrigger;
};

}