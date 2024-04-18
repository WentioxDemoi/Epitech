# Usage :
# mkdir build && cd build/
# cmake ..
# make
# cd .. && ./Indie_Studio -h

#set l'executable et la version
project(bomberman)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.16)

if (NOT raylib_FOUND)
        INCLUDE(FetchContent)
        FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
        FetchContent_GetProperties(raylib)
        if (NOT raylib_POPULATED)
                SET(FETCHCONTENT_QUIET N)
                FetchContent_Populate(raylib)
                SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
                ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
                SET(raylib_FOUND TRUE)
        endif()
endif()

# Adding our source files
include_directories(Include/)
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/Include/") # Define PROJECT_INCLUDE to be the path to the include directory of the project


# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Post Build
if (EXISTS ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
        add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
                ${CMAKE_SOURCE_DIR})
endif()

## condition to check if target exists post build in build/Debug/ to CMAKE_SOURCE_DIR
if (EXISTS ${CMAKE_BINARY_DIR}/Debug/${PROJECT_NAME})
        add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/Debug/${PROJECT_NAME}
                ${CMAKE_SOURCE_DIR})
endif()

# Setting ASSETS_PATH
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
