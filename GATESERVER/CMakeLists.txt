cmake_minimum_required(VERSION 3.16)
project(GateServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件路径
include_directories(
    ${PROJECT_SOURCE_DIR}/header
    /opt/homebrew/include
)

# 自动扫描 src 下所有 .cpp
file(GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(GateServer ${SRC_FILES})

# 目前只用到 header-only 的 Asio/Beast，不需要额外链接 boost 库
# 如果未来真的要用 filesystem，建议改用 std::filesystem 而不是 boost::filesystem
