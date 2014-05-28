CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ENABLE_TESTING()


PROJECT(my_project)


# Compiler configuration
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS "-std=c++0x -Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_PROFILE ${CMAKE_CXX_FLAGS_RELEASE})


# Directories
INCLUDE_DIRECTORIES(include)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)


# Sources
AUX_SOURCE_DIRECTORY(src source)
AUX_SOURCE_DIRECTORY(src/my source)
ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} src/main.cc ${source})


# Libraries
#SET(libraries boost_program_options boost_regex)
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${libraries})


# Profiling configuration
IF(CMAKE_BUILD_TYPE STREQUAL "PROFILE")
  # Link libraries of Google-perftools
  # TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} /usr/lib/libprofiler.so.0)
  TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} )
ENDIF(CMAKE_BUILD_TYPE STREQUAL "PROFILE")


# Unit tests configuration
IF(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
  INCLUDE_DIRECTORIES(tests)
  # Link libraries of boost.test
  # SET(test_libraries ${libraries} boost_unit_test_framework)
  SET(test_libraries ${libraries} )

  # add_unit_test(target, test_sources...)
  #
  # Add an unit test to a build.
  #
  # target: unit test name
  # test_sources: sources
  #
  MACRO(add_unit_test args)
    SET(target ${ARGV0})

    ADD_EXECUTABLE(${ARGV})
    TARGET_LINK_LIBRARIES(${target} ${test_libraries})
    ADD_TEST(
      ${target} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}
      "--log_level=warning"
    )
  ENDMACRO (add_unit_test)

  INCLUDE(unit_tests.cmake)
ENDIF(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
