include(GoogleTest)
# 收集所有测试源文件
file(GLOB TEST_SOURCES "*.cpp")

# 遍历每个测试文件，创建独立的测试目标
foreach(TEST_SOURCE ${TEST_SOURCES})
    # 提取文件名并去掉 .cpp 后缀
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # 创建测试可执行文件
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    # 链接 Google Test 库
    target_link_libraries(${TEST_NAME} gtest gmock_main )

    # 注册测试
    gtest_discover_tests(${TEST_NAME}
            EXTRA_ARGS
            --gtest_output=xml:${CMAKE_BINARY_DIR}/test/${TEST_NAME}.xml
            DISCOVERY_TIMEOUT 120
    )
endforeach()

# 定义一个自定义目标 "run-tests" 来运行所有测试
add_custom_target(run-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)