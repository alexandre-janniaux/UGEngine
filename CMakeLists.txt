cmake_minimum_required(VERSION 2.8)

project(UGEngine)

include_directories(
	UGEngine/include/
)

add_definitions( -std=c++11 )

add_subdirectory (UGEngine)
add_subdirectory (examples)
#add_subdirectory (plugins)

