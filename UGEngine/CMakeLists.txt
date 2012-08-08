Project (UGEngine)

set(
	UGE_SOURCES
	src/Core/DestructionTrigger.cpp

	src/Entity/Core/Component.cpp
	src/Entity/Core/Entity.cpp

	src/Entity/Component/Health.cpp

	src/Entity/Message/Damage.cpp
	src/Entity/Message/Heal.cpp
	src/Entity/Message/Die.cpp
	src/Entity/Message/Update.cpp
)

add_library(
	UGEngine
	SHARED
	${UGE_SOURCES}
)