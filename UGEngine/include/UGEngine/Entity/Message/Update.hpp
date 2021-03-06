#pragma once

#include <UGEngine/Entity/Message/Value.hpp>

namespace uge {

template <typename T>
struct UpdateMessage : public ValueMessage<T> {
	UpdateMessage(T value) : ValueMessage<T>(value){};
};

}