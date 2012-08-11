#pragma once

#include <UGEngine/Core/Vector2.hpp>

namespace uge {

class Position2Message {
public:
	Position2Message(const uge::Vector2f& pos);

	const uge::Vector2f& getPosition() const;

private:
	uge::Vector2f m_position;
};

}