#pragma once

#include <string>

namespace uge {

class ObjectBase {
public:
	template <typename T>
	bool operator== (const T& other) {
		return false;
	}

	bool operator== (const ObjectBase& other ) {
		return true;
	}

	template <typename T>
	bool operator< (const T& other) {
		return this->operator==(other);
	}

	template <typename T>
	bool operator<= (const T& other) {
		return this->operator==(other);
	}

	typedef ObjectBase ClassType;
	typedef ObjectBase ParentType;
};

ObjectBase ObjectBaseInstance;

////////////////////////////////////////////////////////////
/// Type checking class
////////////////////////////////////////////////////////////
template <typename Type, typename BaseType=ObjectBase>
class TypeInfo {
public:	

	////////////////////////////////////////////////////////////
	/// Operator== to test type, always return false for other type than same type of this
	//////////////////////////////////////r//////////////////////
	template <typename T>
	bool operator== (const T& other) {
		return false;
	}

	////////////////////////////////////////////////////////////
	/// Specialisation of operator== to test type, always return true 
	////////////////////////////////////////////////////////////
	bool operator== (const TypeInfo<Type, BaseType>& other) {
		return true;
	}

	////////////////////////////////////////////////////////////
	/// Operator< to test type inheritence
	////////////////////////////////////////////////////////////
	template <typename T>
	bool operator< (const T& other) {
		return BaseType() <= other;
	}

	template <typename T>
	bool operator<= (const T& other) {
		return (*this)==other || (*this)<other;
	}

	////////////////////////////////////////////////////////////
	/// Instance of 
	////////////////////////////////////////////////////////////
	typedef Type ClassType;
	typedef BaseType ParentType;
};


} // namespace uge




