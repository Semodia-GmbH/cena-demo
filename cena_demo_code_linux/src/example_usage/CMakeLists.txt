# Semodia Controlengine.Native standalone usage examples

cmake_minimum_required(VERSION 3.12)
project(controlEngineExternalLibraryExampleBuild LANGUAGES CXX)


# Set global compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused-parameters -Wno-unknown-pragmas -Wdelete-non-virtual-dtor ")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The ControlEngine requires knowledge about the current system it is configured for
string(TOUPPER TARGET_${CMAKE_CXX_PLATFORM_ID} SEMODIA_CXX_PLATFORM)
string(TOUPPER TARGET_${CMAKE_CXX_PLATFORM_ID} SEMODIA_C_PLATFORM)
add_definitions(-D${SEMODIA_CXX_PLATFORM} -D${SEMODIA_C_PLATFORM})


# Set the search path for the CMake targets exported by the CENA build
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/../../lib/cmake/)


# Import the exported targets
find_package(semodia_controlengine)


# Define your own targets
add_executable(example_mtp_controlengine example_mtp_controlengine.cpp)

# Link executable targets to the controlengine
target_link_libraries(example_mtp_controlengine PUBLIC semodia_controlengine::controlengine_packed_static)
