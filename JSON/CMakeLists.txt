cmake_minimum_required(VERSION 3.16)
project(JsonTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 使用 Homebrew 的 LLVM clang（保证和 jsoncpp ABI 匹配）
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# 自动生成 compile_commands.json，方便 clangd 补全
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 找 jsoncpp
find_package(jsoncpp CONFIG REQUIRED)

# 可执行文件
add_executable(JsonTest json.cpp)

# 链接 jsoncpp 库
target_link_libraries(JsonTest PRIVATE jsoncpp_lib)

# Include 路径（包含 Homebrew）
target_include_directories(JsonTest PRIVATE
    /opt/homebrew/include
)
