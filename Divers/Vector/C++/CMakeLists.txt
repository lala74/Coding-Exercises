cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Coding-Exercise)

add_compile_options(${CMAKE_CXX_FLAGS} -Wno-unused-result -Werror=reorder -Wall -Wextra)

# Add policy
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

# Settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

# Constant name
set(BASE_TARGET main)
set(TEST_TARGET main-test)
# set(HLT_USER "MinhDuc")

# Define variable for source file
# add_definitions("-DHLT_USER=\"${HLT_USER}\"")

# Add dynamic library
# find_package(PkgConfig REQUIRED)
# pkg_search_module(GLIB REQUIRED glib-2.0)
# pkg_search_module(GIO REQUIRED gio-unix-2.0)

# Bring header file into project
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../../../Common/C++
    # ${GLIB_INCLUDE_DIRS}
    # ${GIO_INCLUDE_DIRS}
)

# Create sources variable which contains all source files
set(SOURCES  
    main.cpp 
    include/Vector.h
)

add_executable(${BASE_TARGET} ${SOURCES})
add_custom_target(run
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/${BASE_TARGET}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR/build}
)
# target_link_libraries(${BASE_TARGET}
    # ${GLIB_LIBRARIES}
    # ${GIO_LIBRARIES}
# )

#############
# TESTING
include(FetchContent)
FetchContent_Declare(
    googletest
# Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)
set(TEST_SOURCES
    main_test.cpp 
    include/Vector.h
    test/VectorTest.cpp
)

add_executable(${TEST_TARGET} ${TEST_SOURCES})
target_link_libraries(${TEST_TARGET} gtest gtest_main)
gtest_discover_tests(${TEST_TARGET})
