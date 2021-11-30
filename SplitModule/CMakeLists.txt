cmake_minimum_required(VERSION 3.5)
# Enable C++11

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# yi xia zhi chi dbg tiao shi 
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Define project name
project(FallObj)

#设置可执行文件与链接库的保存路径
set(EXECUTABLE_OUTPUT_PATH${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH${PROJECT_SOURCE_DIR}/lib)

 
# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI


find_package(OpenCV REQUIRED)
include_directories( 
    ${OpenCV_INCLUDE_DIRS} 
    ${PROJECT_SOURCE_DIR}/include/
    )

message(STATUS "OpenCV dir: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_libs:${OpenCV_LIBS}")


aux_source_directory(src SRC_LIST)

add_executable(FallObj ${SRC_LIST})

# tianjia opencv lib path
target_link_libraries(FallObj ${OpenCV_LIBS})
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

 

