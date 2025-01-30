cmake_minimum_required(VERSION 3.25)
project(GlowEditor)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
else()

endif()

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "include")

target_link_libraries(${PROJECT_NAME} PRIVATE GlowEngine)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PUBLIC "-static-libgcc")
    target_link_libraries(${PROJECT_NAME} PUBLIC "-static-libstdc++")
    target_link_libraries(${PROJECT_NAME} PUBLIC "-Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
endif()

