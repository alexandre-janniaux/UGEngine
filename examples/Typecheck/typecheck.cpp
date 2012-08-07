#include <UGEngine/Core/TypeInfo.hpp>
#include <UGEngine/Core/TypeDefinition.hpp>
#include <iostream>
#include <cstdlib>

template <char... str>
class variadic_string {

};

template <char... str>
constexpr variadic_string<str...> operator"" _ch() {return variadic_string<str...>();}


class Type1 : public uge::TypeDefinition<Type1, uge::ObjectTypeDefinition, "Type1"_ch> {
public:
	//using void uge::TypeDefinition<Type1, uge::ObjectTypeDefinition, Type1 _ch>::getTypeName();
};

class Type2 : public uge::TypeDefinition<Type2, uge::ObjectTypeDefinition, Type2 _ch> {};
/*class Type3 : public Type1, public uge::TypeDefinition<"Type3", Type3, Type1> {};
class Type4 : public Type3, public uge::TypeDefinition<"Type4", Type4, Type3> {};
*/
template <typename T, typename U>
void check_equal(T& t1, U& t2) {
	if (t1.getType() == t2.getType())
		std::cout << t1.getTypeName() << " == " << t2.getTypeName() << std::endl;
	else
		std::cout << t1.getTypeName() << " != " << t2.getTypeName() << std::endl;
}

template <typename T, typename U>
void check_inherit(T& t1, U& t2) {
	if (t1.getType() < t2.getType())
		std::cout << t1.getTypeName() << " < " << t2.getTypeName() << std::endl;
	else if (t2.getType() < t1.getType())
		std::cout << t1.getTypeName() << " > " << t2.getTypeName() << std::endl;
	else 
		std::cout << t1.getTypeName() << " <!> " << t2.getTypeName() << std::endl;
}


int main (int argc, char** argv) {
	auto t1 = Type1();
	//std::cout << t1.getTypeName() << std::endl;
	auto test = uge::TypeDefinition<Type1, uge::ObjectTypeDefinition, 't', 'e'>();
	std::cout << test.getTypeName() << std::endl;
//	auto t1_2 = Type1();
//	auto t2 = Type2();
//	auto t3 = Type3();
//	auto t4 = Type4();


//	check_equal (t1, t1_2);
//	check_equal (t1, t2);
//	check_equal (t1, t3);
//	check_equal (t1, t4);
//	check_equal (t3, t4);

//	check_inherit (t1, t1_2);
//	check_inherit (t1, t2);
//	check_inherit (t1, t3);
//	check_inherit (t1, t4);
//	check_inherit (t4, t1);
//	check_inherit (t3, t4);

	return EXIT_SUCCESS;
		
}