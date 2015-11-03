cmake_minimum_required(VERSION 3.1)
project(pwAsteroids)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_definitions(-std=c++14)
# Extra warnings
add_definitions(-Wextra -Wall)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/")

file(GLOB SRC_FILES "src/*.cpp" "src/*.h" "src/help/*.cpp" "src/help/*.h" "src/PrimitiveTypes/*.cpp" "src/PrimitiveTypes/*.h"
        "src/exceptions/*.cpp" "src/exceptions/*.h" " src/ModelDrawing/*.h" "src/ModelDrawing/*.cpp" "src/Observer/*.h" "src/Observer/*.cpp"
        "src/ModelDrawing/IDrawablePrimitive.h" "src/modelInterfaces/*.cpp" "src/modelInterfaces/*.h" "src/Services/*.cpp"
        "src/Services/*.h" "src/components/*.h" "src/components/*.cpp" "src/Actors/Rocket/*.cpp" "src/Actors/Rocket/*.h"
        "src/Actors/*.h" "src/Actors/*.cpp"
  )
add_executable(pwAsteroids ${SRC_FILES}  )
TARGET_LINK_LIBRARIES( pwAsteroids ${Boost_LIBRARIES} )

# we may or may not want to build tests
option(BuildTests "BuildTests" OFF)
if(BuildTests)
    set(GMOCK_ROOT lib/gmock-1.7.0 )
    # Google Mock & Test
    ###############################################################################
    add_subdirectory(${GMOCK_ROOT})
    include_directories(${GMOCK_ROOT}/include)
    include_directories(${GMOCK_ROOT}/gtest/include)

    set(TEST_EXECUTABLE_NAME "tests")
    # Test files
    file(GLOB TEST_FILES "test/*.cpp" "test/*h"  "mock/*.cpp" "mock/*.h" "test/PrimitiveTypes/*.cpp" "test/PrimitiveTypes/*.h"
            "test/EndToEndTests/*.cpp" "test/EndToEndTests/help/*.cpp" "test/EndToEndTests/help/*.h"
            "test/EndToEndTests/expectations/*.cpp" "test/EndToEndTests/expectations/*.h" "test/EndToEndTests/when/*.h"
            "test/EndToEndTests/when/*.cpp" "test/Services/*.cpp"
            )

    # Don't include Main.cpp from src
    file(GLOB MAIN_SRC "src/main.cpp")
    list(REMOVE_ITEM SRC_FILES ${MAIN_SRC})

    add_executable("${TEST_EXECUTABLE_NAME}" ${TEST_FILES} ${SRC_FILES} )
    # Set link libraries (order matters)
    target_link_libraries("${TEST_EXECUTABLE_NAME}" gmock gtest pthread ${Boost_LIBRARIES} )

    # Include root directory
    include_directories(BEFORE ".")
    include_directories(BEFORE "src/")
endif()