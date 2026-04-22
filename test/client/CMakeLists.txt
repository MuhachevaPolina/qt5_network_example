add_executable(test_qt5_network_client
    Test_ClientWorker.cpp
)

target_link_libraries(test_qt5_network_client
    GTest::gtest
    GTest::gtest_main
)

# add_test(NAME Qt5NetworkCliemtTests COMMAND test_protobuf_parser)

