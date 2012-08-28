
#include <UGEngine/Message/MessageHandler.hpp>
#include <UGEngine/Message/MessageSender.hpp>

namespace uge {

////////////////////////////////////////////////////////////
template <typename Msg>
std::map<MessageSender*, MessageSenderImpl<Msg>*> 
MessageSenderImpl<Msg>::m_instances;

////////////////////////////////////////////////////////////
template <typename Msg>
MessageSenderImpl<Msg>::~MessageSenderImpl() {
}

////////////////////////////////////////////////////////////
template <typename Msg>
void MessageSenderImpl<Msg>::bind (MessageHandler<Msg>& listener) {
    m_listeners.push_back(&listener);
}

////////////////////////////////////////////////////////////
template <typename Msg>
void MessageSenderImpl<Msg>::unbind (MessageHandler<Msg>& listener) {
    auto ptr = m_listeners.find(&listener);
    if (ptr != m_listeners.end())
        m_listeners.erase(ptr);
}

////////////////////////////////////////////////////////////
template <typename Msg>
void MessageSenderImpl<Msg>::broadcast (Msg& message) {
    for (auto ptr : m_listeners)
        ptr->receive(message);
}

////////////////////////////////////////////////////////////
template <typename Msg>
MessageSenderImpl<Msg>& MessageSenderImpl<Msg>::get(MessageSender& instance) {
    auto ptr = m_instances.find(&instance);
    if ( ptr != m_instances.end() && ptr->second)
        return *ptr->second;
    
    auto impl = new MessageSenderImpl<Msg>;
    m_instances[&instance] = impl;
    instance.subscribe(*impl);
    return *impl;
    
}

template <typename Msg>
void MessageSenderImpl<Msg>::onTriggerDestruction (MessageSender* instance) {
    m_instances[instance] = nullptr;
    delete this;
}

}
