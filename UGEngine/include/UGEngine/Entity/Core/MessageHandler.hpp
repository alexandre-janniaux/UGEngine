#pragma once

namespace uge {

class Component;

template <typename T>
class MessageHandler  {
public:
	////////////////////////////////////////////////////////////
	/// Receive a message : you need to override this function in order to get message 
	////////////////////////////////////////////////////////////
	virtual void receive(T& message, Component* source=nullptr)=0;

private:
};

} // namespace uge
