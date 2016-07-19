cmake_minimum_required(VERSION 2.8)
project(OpenCVProject)
set(CMAKE_BUILD_TYPE "Release")
option(CMAKE_BUILD_TYPE "build type1" "Debug")
# set(CMAKE_CONFIGURATION_TYPES Debug)
message("ccc:${CMAKE_BUILD_TYPE}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

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
aux_source_directory(src/OpenCV_with_QT cvQT)
message(STATUS "src dir :${SRC}")
#all the executable depend on the opencv lib
link_libraries(${OpenCV_LIBS})
add_executable(DisplayImage ${SRC}/setup/test.cpp)
add_executable(FlipImage ${SRC}/setup/main.cpp)
add_executable(ShowImage_QT ${cvQT})
#copy the res files to the executable file
add_custom_command(TARGET FlipImage DisplayImage POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        $<TARGET_FILE_DIR:FlipImage>/images)