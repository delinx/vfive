cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME template)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address,undefined -Wall -Wextra -fno-omit-frame-pointer -fcolor-diagnostics")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fcolor-diagnostics")

# Adding Raylib
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_MakeAvailable(raylib)

project(
  ${PROJECT_NAME}
  VERSION 0.0.1
  LANGUAGES C)

file(GLOB_RECURSE SRC_FILES src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if(UNIT_TEST)
  add_definitions(-DUNIT_TEST)
endif()
