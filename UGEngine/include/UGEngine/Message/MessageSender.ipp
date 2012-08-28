
#include <UGEngine/Message/MessageSenderImpl.hpp>

namespace uge {

////////////////////////////////////////////////////////////
template <typename Msg>
void MessageSender::bind (MessageHandler<Msg>& listener) {
    MessageSenderImpl<Msg>::get(*this).bind(listener);
}

////////////////////////////////////////////////////////////
template <typename Msg>
void MessageSender::unbind (MessageHandler<Msg>& listener) {
    MessageSenderImpl<Msg>::get(*this).unbind(listener);
}

////////////////////////////////////////////////////////////
template <typename Msg>
void MessageSender::broadcast (Msg& message) {
    MessageSenderImpl<Msg>::get(*this).broadcast(message);
}

}
