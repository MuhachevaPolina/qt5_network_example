
add_library(client STATIC
    BlockingClient.cpp
    ClientWorker.cpp
)

target_include_directories(client PUBLIC
    ${CMAKE_SOURCE_DIR})

target_link_libraries(client PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
)