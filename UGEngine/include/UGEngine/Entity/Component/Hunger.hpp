#pragma once

#include <UGEngine/Core/Type.hpp>

#include <UGEngine/Entity/Message/Feed.hpp>
#include <UGEngine/Entity/Message/Update.hpp>

#include <map>
#include <pair>

namespace uge {

namespace component{

template <typename T, typename Time>
class Hunger :
	public Component,
	public MessageHandler<FeedMessage<T>>,
	public MessageHandler<UpdateMessage<Time>>
{
public:
	Hunger(T initialState);

	void setFeedState(T value, Uint32 state);
	Uint32 getFeedState(T value);

	void setMaxValue(T value);
	T getMaxValue() const;

	void setMinValue(T value);
	T getMinValue() const;

	void setHungerSpeed(T value, Time time);
	std::pair<T, Time> getHungerSpeed();

	virtual void receive(FeedMessage<T>& message, Component* component);
	virtual void receive(UpdateMessage<Time>& message, Component* component);

private:
	T 	m_max,
		m_min,
		m_hunger;

	std::pair<T, Time> m_hungerSpeed;
	std::map<T, Uint32>	m_states;
	Uint32 m_currentState;

};


} // namespace component

} // namespace uge
