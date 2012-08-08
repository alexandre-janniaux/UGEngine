#include <UGEngine/Entity/Core/Entity.hpp>
#include <UGEngine/Entity/Core/MessageHandler.hpp>

namespace uge {

template <typename T>
std::map<Entity*, EntityImpl<T>*> EntityImpl<T>::m_instances;

template <typename T>
std::vector<MessageHandler<T>*> EntityImpl<T>::getComponents () {
	return m_messagehandler;
}


template <typename T>
template <typename U>
void EntityImpl<T>::bind(U& component) {
	m_messagehandler.push_back(dynamic_cast<MessageHandler<T>*>(&component));
}

template <typename T>
EntityImpl<T>& EntityImpl<T>::get(Entity& entity) {
	auto ptr = m_instances.find(&entity);
	if( ptr == m_instances.end())
	{
		auto instance = m_instances[&entity] = new EntityImpl<T>();
		// add auto deletion on entity deletion
		return *instance;
	}
	return *ptr->second;
}

template <typename T>
EntityImpl<T>::EntityImpl() {
}

} // namespace uge