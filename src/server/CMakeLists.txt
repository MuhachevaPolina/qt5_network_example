add_library(server STATIC
    FortuneServer.cpp
    ServerTask.cpp
    Dialog.cpp
)

target_include_directories(server PUBLIC
    ${CMAKE_SOURCE_DIR})

target_link_libraries(server PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)
