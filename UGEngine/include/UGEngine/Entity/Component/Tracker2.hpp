#pragma once

#include <UGEngine/Core/Vector2.hpp>
#include <UGEngine/Entity/Message/TrackPosition3.hpp>
#include <UGEngine/Entity/Message/Update.hpp>

namespace uge {

namespace component {

class Tracker2 :
	public Component,
	public MessageHandler<TrackPosition3Message>,
	public MessageHandler<UpdateMessage>
{
public:
	Tracker2 ();

	void setTrackPosition (const uge::Vector2f& position);
	const uge::Vector2f& getPosition() const;

	virtual void receive (TrackPosition2Message& message, Component* sender=nullptr);
	virtual void receive (UpdateMessage& message, Component* sender=nullptr);

private:
	uge::Vector2f m_position;
};


} // namespace component

} // namespace uge