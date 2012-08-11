
namespace uge {

namespace component {

template <typename T, typename Time>
Hunger<T,Time>::(T initialState);

void Hunger<T,Time>::setFeedState(T value, Uint32 state) {
	m_state[value] = state;
	checkState();
}

Uint32 Hunger<T,Time>::getFeedState(T value) {

}

void Hunger<T,Time>::setMaxValue(T value) {
	m_max = value;
}

T Hunger<T,Time>::getMaxValue() const {
	return m_max;
}

void Hunger<T,Time>::setMinValue(T value) {
	m_min = value;
}

T Hunger<T,Time>::getMinValue() const {
	return m_min;
}

void Hunger<T,Time>::setHungerSpeed(T value, Time time) {
	m_hungerSpeed = {value, time};
}

std::pair<T, Time> Hunger<T,Time>::getHungerSpeed() {
	return m_hungerSpeed;
}

void Hunger<T,Time>::receive(FeedMessage<T>& message, Component* component) {
	auto v = message.getValue();
	if (m_hunger - v < getMinValue())
		m_hunger = getMinValue();

	else 
		m_hunger -= v;
}

void Hunger<T,Time>::receive(UpdateMessage<Time>& message, Component* component) {
	m_hunger+= m_hungerSpeed.first / (m_hungerSpeed.second / message.getValue());

}


}


}