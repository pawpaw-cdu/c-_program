cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MyProject)

# 设置可执行文件和库文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/RunFile)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# 确保输出目录存在
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# 添加可执行文件
add_executable(second BasicProgram/second.cpp)

# 确保源文件存在
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/BasicProgram/second.cpp")
    message(FATAL_ERROR "Source file BasicProgram/second.cpp does not exist.")
endif()

# 设置可执行文件的输出目录（如果需要特定于目标的输出目录）
set_target_properties(second PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/RunFile"
)

# 如果不需要特定于目标的输出目录，可以简化为：
# add_executable(first BasicProgram/first.cpp)
# set_target_properties(first PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../RunFile"
# )

# 确保输出目录一致，避免冲突
# 选择一种方式设置输出目录，这里选择全局设置
set_target_properties(second PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/RunFile"
)
# 如果使用的是全局设置，可以去掉特定目标的输出目录设置
# set_target_properties(first PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../RunFile"
# 