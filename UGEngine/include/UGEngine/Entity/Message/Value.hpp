#pragma once

namespace uge {
	
template <typename T>
class ValueMessage {
public:
	ValueMessage(T value);

	T getValue() const;

private:
	T m_value;

};

}

#include <UGEngine/Entity/Message/Value.ipp>