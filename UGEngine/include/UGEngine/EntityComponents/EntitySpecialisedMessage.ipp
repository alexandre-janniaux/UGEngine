#include <UGEngine/EntityComponents/Entity.hpp>
#include <UGEngine/EntityComponents/MessageHandler.hpp>

namespace uge {

template <typename T>
std::map<Entity*, EntitySpecialisedMessage<T>*> EntitySpecialisedMessage<T>::m_instances;

template <typename T>
std::vector<MessageHandler<T>*> EntitySpecialisedMessage<T>::getComponents () {
	return m_messagehandler;
}


template <typename T>
template <typename U>
void EntitySpecialisedMessage<T>::addComponent(U& component) {
	m_messagehandler.push_back(dynamic_cast<MessageHandler<T>*>(&component));
}

template <typename T>
EntitySpecialisedMessage<T>& EntitySpecialisedMessage<T>::get(Entity& entity) {
	auto ptr = m_instances.find(&entity);
	if( ptr == m_instances.end())
	{
		auto instance = m_instances[&entity] = new EntitySpecialisedMessage<T>();
		// add auto deletion on entity deletion
		return *instance;
	}
	return *ptr->second;
}

template <typename T>
EntitySpecialisedMessage<T>::EntitySpecialisedMessage() {
}

} // namespace uge