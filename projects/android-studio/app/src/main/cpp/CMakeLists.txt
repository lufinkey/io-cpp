
cmake_minimum_required(VERSION 3.4.1)
set( CMAKE_CXX_STANDARD 17 )

set( IOCPP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../.." )

add_subdirectory("${IOCPP_ROOT}/../data-cpp/projects/android-studio/libdatacpp/src/main/cpp" "${CMAKE_BINARY_DIR}/data-cpp")
add_subdirectory("${IOCPP_ROOT}/../async-cpp/projects/android-studio/libasynccpp/src/main/cpp" "${CMAKE_BINARY_DIR}/async-cpp")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../../../libiocpp/src/main/cpp" "${CMAKE_BINARY_DIR}/io-cpp")

add_library( native-lib SHARED native-lib.cpp )

find_library(log-lib log)

target_link_libraries(
		native-lib

		DataCpp
		AsyncCpp
		IOCpp
		${log-lib})
