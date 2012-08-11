#pragma once

#include <UGEngine/Core/Type.hpp>
#include <UGEngine/Entity/Message/Value.hpp>

namespace uge {

struct FeedStateMessage : public ValueMessage<Uint32> {
	FeedStateMessage(uge::Uint32 state) : ValueMessage<Uint32>(state) {}
};

};

}