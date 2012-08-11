#pragma once

#include <UGEngine/Entity/Message/Value.hpp>

namespace uge {

template <typename T>
struct DieMessage : public ValueMessage <T> {
	DieMessage(T value) : ValueMessage<T>(value) {}
};

} // namespace uge
