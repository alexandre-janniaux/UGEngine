#include <UGEngine/Entity/Message/Update.hpp>

namespace uge {

UpdateMessage::UpdateMessage (uge::Float time) :
	m_time(time)
{}

uge::Float UpdateMessage::getTime() const {
	return m_time;
}

} // namespace uge