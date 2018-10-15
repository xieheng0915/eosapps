cmake_minimum_required (VERSION 3.11)



# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
#include_directories("${PROJECT_BINARY_DIR}")

# add add_library
add_library(MathFunctions mysqrt.cpp)

# add installation
install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
