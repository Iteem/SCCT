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
	${SRC_DIR}/NonCopyable.hpp
	${SRC_DIR}/Resources.hpp
	${SRC_DIR}/Resources/Loaders.hpp
	${SRC_DIR}/Resources/ResourceKey.hpp
	${SRC_DIR}/Resources/ResourceKey.inl
	${SRC_DIR}/Resources/ResourceManager.hpp
	${SRC_DIR}/Resources/ResourceManager.inl
)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

add_executable( ${PROJECT_NAME} ${SOURCES})
target_link_libraries( ${PROJECT_NAME} ${SFML_NETWORK_LIBRARY} ${SFML_AUDIO_LIBRARY} ${SFML_GRAPHICS_LIBRARY} ${SFML_WINDOW_LIBRARY} ${SFML_SYSTEM_LIBRARY} )
