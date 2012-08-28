Project (UGEngine)

set(
	UGE_SOURCES

	src/Entity/Core/Component.cpp
	src/Entity/Core/Entity.cpp
	
)

add_library(
	UGEngine
	SHARED
	${UGE_SOURCES}
)

install(
	TARGETS UGEngine
	RUNTIME DESTINATION bin
  	LIBRARY DESTINATION lib
  	ARCHIVE DESTINATION lib
)

install(
	DIRECTORY include/UGEngine
	DESTINATION include	
)
