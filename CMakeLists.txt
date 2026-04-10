cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

project(qt-multithreading VERSION 1.0.0 DESCRIPTION "Знакомство с многопоточностью и сетевым обменом в Qt5")

include_directories(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src/server)
add_subdirectory(src/client)

# enable_testing()
add_subdirectory(test/server)
add_subdirectory(test/client)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5 REQUIRED COMPONENTS Network)


# include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(main
    src/main.cpp
)

target_link_libraries(main PRIVATE
    server
    client
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)
