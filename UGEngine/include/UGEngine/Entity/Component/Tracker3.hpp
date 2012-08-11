#pragma once

#include <UGEngine/Core/Vector3.hpp>
#include <UGEngine/Entity/Message/TrackPosition3.hpp>
#include <UGEngine/Entity/Message/Update.hpp>

namespace uge {

namespace component {

class Tracker3 :
	public Component,
	public MessageHandler<TrackPosition3Message>,
	public MessageHandler<UpdateMessage>
{
public:
	Tracker3 ();

	void setTrackPosition (const uge::Vector3f& position);
	const uge::Vector3f& getPosition() const;

	virtual void receive (TrackPosition3Message& message, Component* sender=nullptr);
	virtual void receive (UpdateMessage& message, Component* sender=nullptr);

private:
	uge::Vector3f m_position;
};


} // namespace component

} // namespace uge