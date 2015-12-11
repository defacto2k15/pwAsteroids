cmake_minimum_required(VERSION 2.6)
project(pwAsteroids)

add_definitions(-std=c++14)
# Extra warnings
# add_definitions(-Wall)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/")

file(GLOB SRC_FILES "src/*.cpp" "src/*.h" "src/Model/help/*.cpp" "src/Model/help/*.h" "src/Model/PrimitiveTypes/*.cpp" "src/Model/PrimitiveTypes/*.h"
        "src/Model/exceptions/*.cpp" "src/Model/exceptions/*.h" "src/Model/ModelDrawing/*.h" "src/Model/ModelDrawing/*.cpp" "src/Model/Observer/*.h" "src/Model/Observer/*.cpp"
        "src/Model/ModelDrawing/IDrawablePrimitive.h" "src/Model/modelInterfaces/*.cpp" "src/Model/modelInterfaces/*.h" "src/Model/Services/*.cpp"
        "src/Model/Services/*.h" "src/Model/components/*.h" "src/Model/components/*.cpp" "src/Model/Actors/Rocket/*.cpp" "src/Model/Actors/Rocket/*.h"
        "src/Model/Actors/*.h" "src/Model/Actors/*.cpp" "src/Model/box2d/*.cpp" "src/Model/box2d/*.h"
        "src/View/*.cpp" "src/View/*.h" "src/Model/configuration/*.cpp" "src/Model/configuration/*.h"
        "src/Model/Actors/RocketTail/*.cpp" "src/Model/Actors/RocketTail/*.h" "src/Model/python/*.cpp" "src/Model/python/*.h"
  )

add_executable(pwAsteroids ${SRC_FILES}  )

# Including python things...
INCLUDE_DIRECTORIES( "/usr/include/python3.4")
TARGET_LINK_LIBRARIES(pwAsteroids /usr/lib/x86_64-linux-gnu/libpython2.7.so )

if(UNIX)
    FIND_PACKAGE( Boost 1.48 REQUIRED COMPONENTS python system thread )
    INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
    TARGET_LINK_LIBRARIES( pwAsteroids ${Boost_LIBRARIES} )
    TARGET_LINK_LIBRARIES( pwAsteroids boost_system )
    TARGET_LINK_LIBRARIES( pwAsteroids boost_thread )
    TARGET_LINK_LIBRARIES( pwAsteroids boost_python )

else()
    SET_TARGET_PROPERTIES(pwAsteroids PROPERTIES ENVIRONMENT_DEBUG "PATH=${allegropath}/bin;%PATH%")
    INCLUDE_DIRECTORIES( ${boostpath} )
    INCLUDE_DIRECTORIES( ${allegropath}/include )
    INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR} )

    TARGET_LINK_LIBRARIES( pwAsteroids ${CMAKE_CURRENT_SOURCE_DIR}/lib/Windows/Box2D.lib )
    TARGET_LINK_LIBRARIES( pwAsteroids ${boostpath}/stage/lib/boost_program_options-vc140-mt-gd-1_59.lib )
    TARGET_LINK_LIBRARIES( pwAsteroids ${boostpath}/stage/lib/libboost_thread-vc140-mt-gd-1_59.lib )
    TARGET_LINK_LIBRARIES( pwAsteroids ${boostpath}/stage/lib/libboost_date_time-vc140-mt-gd-1_59.lib )
    TARGET_LINK_LIBRARIES( pwAsteroids ${boostpath}/stage/lib/libboost_system-vc140-mt-gd-1_59.lib )
    TARGET_LINK_LIBRARIES( pwAsteroids ${boostpath}/stage/lib/libboost_chrono-vc140-mt-gd-1_59.lib )
    TARGET_LINK_LIBRARIES( pwAsteroids ${allegropath}/lib/allegro-5.0.10-monolith-mt.lib )

    SET(BOOST_ROOT ${boostpath} )
    SET(BOOST_LIBRARYDIR ${boostpath}/stage/lib )
    FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
    #INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
endif()

set(BOX2D_VERSION 2.3.0)
add_subdirectory(lib/Box2D)
include_directories(${Box2D_SOURCE_DIR})
if(UNIX)
    TARGET_LINK_LIBRARIES( pwAsteroids Box2D)
endif()

include_directories(src)

# allegro - works on linux and only if allegro is installed- need to be changed
if(UNIX)
    include_directories(/usr/include/x86_64-linux-gnu)
    TARGET_LINK_LIBRARIES( pwAsteroids allegro_image allegro)
else()
    # TARGET_LINK_LIBRARIES(pwAsteroids ${CMAKE_CURRENT_SOURCE_DIR}/lib/Windows/Box2D.lib )
endif()

# security level
# if(MSVC)
#  # Force to always compile with W4
#   if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
#     string(REGEX REPLACE "/W[0-4]" "/W0" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
#   else()
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W0")
#   endif()
# elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
#   # Update if necessary
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long ")
# endif()

include_directories(pwAsteroids ${CMAKE_CURRENT_SOURCE_DIR}/lib)

message( $ENV{PYTHONNAME} $ENV{PYTHONPATH} WARNING)

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
    TARGET_LINK_LIBRARIES( "${TEST_EXECUTABLE_NAME}" Box2D)
    TARGET_LINK_LIBRARIES( "${TEST_EXECUTABLE_NAME}" ${Boost_LIBRARIES} )
    TARGET_LINK_LIBRARIES( "${TEST_EXECUTABLE_NAME}" boost_system )
    TARGET_LINK_LIBRARIES( "${TEST_EXECUTABLE_NAME}" boost_thread)
    TARGET_LINK_LIBRARIES( "${TEST_EXECUTABLE_NAME}" allegro_image allegro)
    # Include root directory
    include_directories(BEFORE ".")
    include_directories(BEFORE "src/")

    # python
    TARGET_LINK_LIBRARIES("${TEST_EXECUTABLE_NAME}" /usr/lib/x86_64-linux-gnu/libpython2.7.so )
    TARGET_LINK_LIBRARIES( "${TEST_EXECUTABLE_NAME}" boost_python)
endif()