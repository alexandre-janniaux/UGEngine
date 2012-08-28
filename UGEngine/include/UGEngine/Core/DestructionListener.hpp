#pragma once

namespace uge {
	
template <typename T>
class DestructionTrigger;

template <typename T>
class DestructionListener {
protected:
	virtual void onTriggerDestruction(T* trigger) =0;
	friend class DestructionTrigger<T>;
};

}
