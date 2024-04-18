cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(r-type)

set(CLIENT r-type-client)
set(SERVER r-type-server)

add_compile_options(-g3 -lfoo -I /usr/lib64/ -lsfml-graphics -lsfml-window
        -lsfml-system
        -lboost_serialization -lpthread -lboost_system -lboost_system
        -lboost_thread -pthread  -lboost_system-mt -lboost_thread-mt -lboost_chrono-mt)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies needed for the project
set(CMAKE_MODULE_PATH ";${CMAKE_SOURCE_DIR}/cmake")
find_package(X11 REQUIRED)
find_package(boost REQUIRED)
find_package(sfml REQUIRED)
find_package(vorbis REQUIRED)

# Server files of the project
set(SERVER_SOURCE_FILES
        #components/enemy
        ./ServerRtype/Components/Enemy/Enemy.cpp
        #components/fire
        ./ServerRtype/Components/Fire/Fire.cpp
        #components/Lobby
        ./ServerRtype/Components/Lobby/Lobby.cpp
        #components/Player
        ./ServerRtype/Components/Player/Player.cpp
        #Errors
        ./ServerRtype/Error/error.cpp
        #GameEntity - Enemy - Fire - Lobby - Player
        ./ServerRtype/GameEntity/Enemy/EnemyEntity.cpp
        ./ServerRtype/GameEntity/Fire/FireEntity.cpp
        ./ServerRtype/GameEntity/Lobby/LobbyEntity.cpp
        ./ServerRtype/GameEntity/Player/PlayerEntity.cpp
        #server
        ./ServerRtype/Server/server.cpp
        #server/ToolsServer
        ./ServerRtype/Server/ToolsServer/tools.cpp
        #src
        ./ServerRtype/main.cpp)

# Client files of the project
set(CLIENT_SOURCE_FILES
        #components
        ./ClientRtype/src/components/animation.cpp
        ./ClientRtype/src/components/collision.cpp
        ./ClientRtype/src/components/enemy.cpp
        ./ClientRtype/src/components/movement.cpp
        ./ClientRtype/src/components/music.cpp
        ./ClientRtype/src/components/position.cpp
        ./ClientRtype/src/components/shoot.cpp
        ./ClientRtype/src/components/sprite.cpp
        ./ClientRtype/src/components/text.cpp
        #factory
        ./ClientRtype/src/factory/factory.cpp
        #system
        ./ClientRtype/src/system/draw.cpp
        ./ClientRtype/src/system/InitScenes.cpp
        ./ClientRtype/src/system/magicsystem.cpp
        #src
        ./ClientRtype/src/Event.cpp
        ./ClientRtype/src/main.cpp
        ./ClientRtype/src/Network.cpp)

add_executable(${CLIENT})
add_executable(${SERVER})

target_compile_features(${CLIENT} PRIVATE cxx_std_20)
target_compile_features(${SERVER} PRIVATE cxx_std_20)

target_sources(${CLIENT} PRIVATE ${CLIENT_MAIN_FILE} ${CLIENT_SOURCE_FILES})
target_sources(${SERVER} PRIVATE ${SERVER_MAIN_FILE} ${SERVER_SOURCE_FILES})

target_include_directories(${CLIENT} PRIVATE src include Client/include)

target_include_directories(
        ${SERVER}
        PRIVATE
        src
        include
        Server/include
)

target_sources(${CLIENT} PRIVATE ${CLIENT_MAIN_FILE} ${CLIENT_SOURCE_FILES})

target_sources(${SERVER} PRIVATE ${SERVER_MAIN_FILE} ${SERVER_SOURCE_FILES})

target_link_libraries(${CLIENT} Boost::predef Boost::thread Boost::asio
        Boost::coroutine
        Boost::bind Boost::serialization Boost::lambda X11 UDev sfml-graphics
        sfml-window sfml-system sfml-audio)
target_link_libraries(${SERVER} Boost::predef Boost::thread Boost::asio
        Boost::asio
        Boost::coroutine Boost::bind Boost::serialization X11 UDev sfml-graphics)
