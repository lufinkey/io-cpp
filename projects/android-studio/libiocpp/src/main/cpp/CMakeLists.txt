
cmake_minimum_required(VERSION 3.18.1)
project(IOCpp)
set( CMAKE_CXX_STANDARD 20 )

set( IOCPP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../.." )
set( ASYNCCPP_ROOT "${IOCPP_ROOT}/../async-cpp" )
set( ASYNCCPP_LIB_DIR "${ASYNCCPP_ROOT}/projects/android-studio/libasynccpp/build/intermediates/cmake/${CMAKE_BUILD_TYPE}/obj/${ANDROID_ABI}" )
set( DATACPP_ROOT "${IOCPP_ROOT}/../data-cpp" )
set( DATACPP_LIB_DIR "${DATACPP_ROOT}/projects/android-studio/libdatacpp/build/intermediates/cmake/${CMAKE_BUILD_TYPE}/obj/${ANDROID_ABI}" )

execute_process(COMMAND "${IOCPP_ROOT}/tools/fetch_android_dependencies.sh")

file(GLOB_RECURSE IOCPP_SOURCES "${IOCPP_ROOT}/src/fgl/*.cpp")

add_library(IOCpp SHARED
		IOCpp_android.cpp
		${IOCPP_SOURCES})

target_include_directories(
		IOCpp
		PUBLIC
		"${IOCPP_ROOT}/src")

target_include_directories(
		IOCpp
		PRIVATE
		"${IOCPP_ROOT}/../data-cpp/src"
		"${IOCPP_ROOT}/../async-cpp/src"
		"${IOCPP_ROOT}/../dtl"
		"${IOCPP_ROOT}/external/filesystem/include")

find_library(log-lib log)

target_link_libraries(
		IOCpp
		"${DATACPP_LIB_DIR}/libDataCpp.so"
		"${ASYNCCPP_LIB_DIR}/libAsyncCpp.so"
		${log-lib})
