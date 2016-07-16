cmake_minimum_required(VERSION 2.8)
project(DisplayImage)
set(CMAKE_PREFIX_PATH "/usr/local/opt/opencv3/share/OpenCV")

# set(OpenCV_INCLUDE_DIRS "/usr/local/opt/opencv3/include")
# set(OpenCV_LIBS "/usr/local/opt/opencv3/lib")

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
add_executable(DisplayImage test.cpp)
target_link_libraries(DisplayImage ${OpenCV_LIBS})

