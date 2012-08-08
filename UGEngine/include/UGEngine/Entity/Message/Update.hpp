#pragma once

#include <UGEngine/Core/Type.hpp>

namespace uge {

class UpdateMessage {
public:
	UpdateMessage(uge::Float time);

	uge::Float getTime() const;

private:
	uge::Float m_time;
};

}