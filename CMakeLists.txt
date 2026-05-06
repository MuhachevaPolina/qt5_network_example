cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

project(qt-multithreading VERSION 1.0.0 DESCRIPTION "Знакомство с многопоточностью и сетевым обменом в Qt5")

# include_directories(${CMAKE_SOURCE_DIR}/src)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5 REQUIRED COMPONENTS Network)

find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(src/server)
add_subdirectory(src/client)
add_subdirectory(test/server)
add_subdirectory(test/client)

enable_testing()

add_library(server_test_utils STATIC
    test/server/utilities.cpp
)

target_include_directories(server_test_utils PUBLIC
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(server_test_utils PUBLIC
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)

add_executable(tests
    test/server/Test_ServerTask.cpp
    test/server/Test_FortuneServer.cpp
    test/client/Test_ClientWorker.cpp
)

add_executable(app
    src/main.cpp
)

target_include_directories(tests PUBLIC
    ${CMAKE_SOURCE_DIR}
)

# add_executable(main
#     src/main.cpp
# )

target_link_libraries(tests PRIVATE
    server
    client
    server_test_utils
    GTest::gtest_main 
    GTest::gtest
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)

target_link_libraries(app PRIVATE
    server
    client
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)


include(GoogleTest)
gtest_discover_tests(tests)

# add_test(NAME Qt5NetworkTests COMMAND test)
