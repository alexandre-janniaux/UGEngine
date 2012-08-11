
namespace uge {

template <typename T>	
ValueMessage<T>::ValueMessage(T value) : m_value (value) {
	
}

template <typename T>
T ValueMessage<T>::getValue() const {
	return m_value;
}


}