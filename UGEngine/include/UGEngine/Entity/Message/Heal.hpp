#pragma once

#include <UGEngine/Core/Type.hpp>
#include <UGEngine/Entity/Message/Value.hpp>

namespace uge {

template <typename T>
struct HealMessage : public ValueMessage<T> {
	HealMessage(T value) : ValueMessage<T>(value){};
};

} // namespace uge
