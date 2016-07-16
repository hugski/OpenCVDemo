cmake_minimum_required(VERSION 2.8)
project(OpenCVProject)
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CONFIGURATION_TYPES Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
set(SRC "src/")

message(STATUS " source dir :${CMAKE_SOURCE_DIR}")

set(CMAKE_PREFIX_PATH "/usr/local/opt/opencv3/share/OpenCV")
# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)
# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

aux_source_directory(src/setup first)
message(STATUS "src dir :${SRC}")
link_libraries(${OpenCV_LIBS})
add_executable(DisplayImage ${SRC}/setup/test.cpp)
add_executable(FlipImage ${SRC}/setup/main.cpp)
# target_link_libraries(DisplayImage ${OpenCV_LIBS})

