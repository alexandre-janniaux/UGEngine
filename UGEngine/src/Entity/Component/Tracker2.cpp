#include <UGEngine/Entity/Component/Tracker2.hpp>

namespace uge {

namespace component {

Tracker2::Tracker2 () {

}

void Tracker2::setPosition (const uge::Vector2f& position) {
	m_position = position;
}

const Vector2f& Tracker2::getPosition () const {
	return m_position;
}

void Tracker2::setTrackPosition (const uge::Vector2f& position) {
	m_trackPosition = position;
}

const Vector2f& Tracker2::getTrackPosition() const {
	return m_trackPosition;
}

void Tracker2::receive (TrackPosition2Message& message, Component* sender=nullptr) {
	setTrackPosition(message.getTrackPosition());
}

void Tracker2::receive (UpdateMessage& message, Component* sender=nullptr) {
	PathQueryPosition2Message msg (getPosition(), getTrackPosition(), message.getTime());
	broadcast (msg);
}

void Tracker2::receive (PathResponsePosition2& message, Component* sender=nullptr) {
	PositionMessage msg (message.getPosition());
	broadcast (msg);
}

} // namespace component

} // namespace uge