Project (UGEngine)

set(
	UGE_SOURCES
	src/EntityComponents/Component.cpp
	src/EntityComponents/Entity.cpp
	src/ExempleComponents/HealthComponent.cpp

	src/MessageComponents/DamageMessage.cpp
	src/MessageComponents/HealMessage.cpp
	src/MessageComponents/DieMessage.cpp
)

add_library(
	UGEngine
	SHARED
	${UGE_SOURCES}
)