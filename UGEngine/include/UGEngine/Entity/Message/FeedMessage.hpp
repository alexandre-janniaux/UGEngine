#pragma once

#include <UGEngine/Entity/Message/Value.hpp>

namespace uge {

template <typename T>
struct FeedMessage : public ValueMessage<T> {
	FeedMessage(T value) : ValueMessage<T>(value){};
};

}