#pragma once


#include <UGEngine/Core/Vector2.hpp>

namespace uge {

class PathQueryPosition2Message {
public:
	PathQueryPosition2Message(
		const Vector2f& pos,
		const Vector2f& track,
		Float time
		);

	const Vector2f& getPosition() const;
	const Vector2f& getTrackPosition() const;
	Float getTime() const;

private:
	Vector2f 	m_position,
				m_trackPosition;
	
};

} // namespace uge