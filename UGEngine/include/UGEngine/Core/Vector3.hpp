#pragma once

#include <UGEngine/Core/Type.hpp>

namespace uge {

template <typename T>
class Vector3 {
public:
	T x, y, z;
};

using Vector3f = Vector3<uge::Float>;
} // namespace uge