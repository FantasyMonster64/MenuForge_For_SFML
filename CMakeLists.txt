# because new msvc
cmake_minimum_required(VERSION 4.2)

# Define the project name and language
project(MenuForge_for_SFML LANGUAGES CXX)

# Enforce the C++ standard 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)	

# 1. Dynamically find all .h files in the current directory
file(GLOB HEADER_FILES CONFIGURE_DEPENDS "*.h")

# 2. Find your source files
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

# Create a static library
add_library(MenuForge_for_SFML STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Specify include directories for the target
target_include_directories(MenuForge_for_SFML PUBLIC ${PROJECT_SOURCE_DIR}/include)