
add_executable (
    component
    component.cpp
)

target_link_libraries (
    component
    UGEngine
    ${SFML_GRAPHICS_LIBRARY}
    ${SFML_WINDOW_LIBRARY}
    ${SFML_SYSTEM_LIBRARY}
)
