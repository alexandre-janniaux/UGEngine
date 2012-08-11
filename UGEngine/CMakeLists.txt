Project (UGEngine)

set(
	UGE_SOURCES
	src/Core/DestructionTrigger.cpp

	src/Entity/Core/Component.cpp
	src/Entity/Core/Entity.cpp
	
)

add_library(
	UGEngine
	SHARED
	${UGE_SOURCES}
)