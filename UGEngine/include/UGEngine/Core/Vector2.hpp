#pragma once

#include <UGEngine/Core/Type.hpp>

namespace uge {

template <typename T>
class Vector2 {
public:
	T x, y;
};

using Vector2f = Vector2<uge::Float>;
} // namespace uge