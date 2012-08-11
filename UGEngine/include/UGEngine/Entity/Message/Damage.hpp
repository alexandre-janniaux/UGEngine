#pragma once

#include <UGEngine/Core/Type.hpp>
#include <UGEngine/Entity/Message/Value.hpp>

namespace uge {

template <typename T>
struct DamageMessage : public ValueMessage <T> {
	DamageMessage(T value) : ValueMessage<T>(value){};
};

}
