add_executable(test_qt5_network_server
    Test_ServerTask.cpp
)

target_link_libraries(test_qt5_network_server
    GTest::gtest
    GTest::gtest_main
)

# add_test(NAME Qt5NetworkCliemtTests COMMAND test_protobuf_parser)
