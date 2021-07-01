
project(TestApp)
cmake_minimum_required(VERSION 3.4.1)
set( CMAKE_CXX_STANDARD 17 )

set( IOCPP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../.." )
set( DATACPP_ROOT "${IOCPP_ROOT}/../data-cpp" )
set( ASYNCCPP_ROOT "${IOCPP_ROOT}/../async-cpp" )

add_subdirectory("${DATACPP_ROOT}/projects/android-studio/libdatacpp/src/main/cpp" DataCpp)
add_subdirectory("${ASYNCCPP_ROOT}/projects/android-studio/libasynccpp/src/main/cpp" AsyncCpp)
add_subdirectory("${IOCPP_ROOT}/projects/android-studio/libiocpp/src/main/cpp" IOCpp)

add_library( TestApp SHARED native-lib.cpp "${IOCPP_ROOT}/src/test/IOCppTests.cpp" )

find_library(log-lib log)

target_link_libraries(
		TestApp

		DataCpp
		AsyncCpp
		IOCpp
		${log-lib})
