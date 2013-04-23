cmake_minimum_required( VERSION 2.8 )

# Replace SCCT with the name of your project
set( PROJECT_NAME "SCCT" )

project( ${PROJECT_NAME} )

find_package( SFML 2.0 QUIET COMPONENTS GRAPHICS WINDOW SYSTEM )

set( SRC_DIR "${PROJECT_SOURCE_DIR}/src/" )

# Add sources here
set(
	SOURCES
	${SRC_DIR}/main.cpp
)

add_executable( ${PROJECT_NAME} ${SOURCES})
target_link_libraries( ${PROJECT_NAME} ${SFML_NETWORK_LIBRARY} ${SFML_AUDIO_LIBRARY} ${SFML_GRAPHICS_LIBRARY} ${SFML_WINDOW_LIBRARY} ${SFML_SYSTEM_LIBRARY} )
