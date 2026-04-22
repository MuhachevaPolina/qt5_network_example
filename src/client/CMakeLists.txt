cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)
project(qt-multithreading VERSION 1.0.0 DESCRIPTION "Знакомство с многопоточностью и сетевым обменом в Qt5")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5 REQUIRED COMPONENTS Network)

add_library(client STATIC
    BlockingClient.cpp
    ClientWorker.cpp
)

target_link_libraries(client PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)