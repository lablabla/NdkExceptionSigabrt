cmake_minimum_required(VERSION 3.4.1)
project(nativelib)

add_library(${PROJECT_NAME} SHARED
        src/main/cpp/MyException.cpp
        src/main/cpp/TestAPI.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        src/main/cpp
        )

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)
target_compile_definitions(${PROJECT_NAME} PUBLIC EXPORT_DEFAULT_VISIBILITY)

