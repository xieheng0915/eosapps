cmake_minimum_required (VERSION 3.11)
project(Tutorial)


# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
#add_library(MathFunctions mysqrt.cpp)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
#include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
#add_subdirectory (MathFunctions)



# should we use our own math functions?
option (USE_MYTH "Use tutorial provided math implementation" ON)

if (USE_MYTH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory(MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYTH)

# add the executable
add_executable(Tutorial tutorial.cpp)
target_link_libraries (Tutorial MathFunctions)

#add top installation
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
