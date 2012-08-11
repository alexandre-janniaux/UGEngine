#include <UGEngine/Entity/Component/Tracker3.hpp>

namespace uge {

namespace component {

Tracker3::Tracker3 () {

}

void Tracker3::setTrackPosition (const uge::Vector3f& position) {

}

const uge::Vector3f& Tracker3::getPosition() const {
	return m_position;
}

void Tracker3::receive (TrackPosition3Message& message, Component* sender=nullptr) {

}

void Tracker3::receive (UpdateMessage& message, Component* sender=nullptr) {

}

} // namespace component

} // namespace uge