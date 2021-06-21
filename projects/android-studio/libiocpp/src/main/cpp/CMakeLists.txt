
cmake_minimum_required(VERSION 3.4.1)
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )

set( IOCPP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../.." )

execute_process(COMMAND "${IOCPP_ROOT}/tools/fetch_android_dependencies.sh")

file(GLOB_RECURSE IOCPP_SOURCES "${IOCPP_ROOT}/src/fgl/*.cpp")

add_library(IOCpp SHARED
		IOCpp_android.cpp
		${IOCPP_SOURCES})

target_include_directories(
		IOCpp
		PUBLIC
		"${IOCPP_ROOT}/src"
		"${IOCPP_ROOT}/../data-cpp/src"
		"${IOCPP_ROOT}/../async-cpp/src"
		"${IOCPP_ROOT}/../dtl")

target_include_directories(
		IOCpp
		PRIVATE
		"${IOCPP_ROOT}/external/filesystem/include")

find_library(log-lib log)

target_link_libraries(
		IOCpp
		DataCpp
		AsyncCpp
		${log-lib})
