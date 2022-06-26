cmake_minimum_required(VERSION 3.4.1)
project(nativelib)


if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1z -fPIC")
endif()

add_subdirectory(../3rdparty/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_compile_options(spdlog PRIVATE -fvisibility=hidden)

add_library(${PROJECT_NAME} SHARED
        src/MyException.cpp
        src/TestAPI.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        spdlog::spdlog
        )

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)
target_compile_definitions(${PROJECT_NAME} PUBLIC EXPORT_DEFAULT_VISIBILITY)

