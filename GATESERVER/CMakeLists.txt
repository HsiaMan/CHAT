cmake_minimum_required(VERSION 3.16)
project(GateServer)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 使用 Homebrew LLVM（防止自动回退到 AppleClang）
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# Boost 头文件路径
include_directories(/opt/homebrew/include)

# Boost 文件系统库路径
link_directories(/opt/homebrew/lib)

# 可执行文件
add_executable(GateServer main.cpp)

# Boost.Filesystem + header-only System
target_link_libraries(GateServer
    /opt/homebrew/lib/libboost_filesystem.dylib
)
