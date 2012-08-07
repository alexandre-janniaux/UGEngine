#pragma once

#include <string>
#include <UGEngine/Core/TypeInfo.hpp>

namespace uge {



class ObjectTypeDefinition {
public:
	using Type = TypeInfo<ObjectTypeDefinition, ObjectBase>;
	//typedef TypeInfo<ObjectTypeDefinition, ObjectBase> Type; 
	constexpr const char* getTypeName() { return "uge::ObjectTypeDefinition"; }
	Type getType() { return Type(); }
	
};

template <typename T, typename BaseType=ObjectTypeDefinition,char... name>
class TypeDefinition {
public:
	using Type = TypeInfo<T, typename BaseType::Type>;
	constexpr std::string getTypeName() { return std::string({name...}); }
	Type getType() { return Type(); }
};



} // namespace uge


