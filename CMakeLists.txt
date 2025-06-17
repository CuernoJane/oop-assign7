cmake_minimum_required(VERSION 3.10)
project(oop_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include 資料夾讓所有 .h 可直接引用
include_directories(include)

# 找到所有 header 和 source file
file(GLOB_RECURSE HEADER_FILES "include/*.h" "include/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# 建立執行檔
add_executable(oop_game ${SOURCE_FILES} ${HEADER_FILES})

# macOS 用 iconv
if(APPLE)
    target_link_libraries(oop_game PRIVATE iconv)
endif()

# 編譯選項（可加上 POSIX 宏定義）
target_compile_options(oop_game PRIVATE -Wall -D_XOPEN_SOURCE=700)
