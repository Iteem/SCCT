cmake_minimum_required( VERSION 2.8 )

# Replace SCCT with the name of your project
project( SCCT )

# SFML
set( CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH}" )
find_package( SFML 2 REQUIRED system window graphics network audio )
include_directories( ${SFML_INCLUDE} )

# Source files
file( GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*" )

# GCC
if( CMAKE_COMPILER_IS_GNUCXX )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall" )
endif()

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR} )

add_executable( ${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries( ${CMAKE_PROJECT_NAME} ${SFML_LIBRARIES} )
