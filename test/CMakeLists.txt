# 收集所有测试源文件
file(GLOB TEST_SOURCES "*.cpp")

# 遍历每个测试文件，创建独立的测试目标
foreach(TEST_SOURCE ${TEST_SOURCES})
    # 提取文件名并去掉 .cpp 后缀
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # 创建测试可执行文件
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    # 链接 Google Test 库
    target_link_libraries(${TEST_NAME} gtest gtest_main)

    # 注册测试
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# 定义一个自定义目标 "run-tests" 来运行所有测试
add_custom_target(run-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)