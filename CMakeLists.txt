cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_MODULE_PATH "$CMAKE_SOURCE_DIR/cmake")

set(CMAKE_CXX_FLAGS "-std=c++1z")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -g0")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -s")
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -Wall -Wunused -Wextra")
endif()

include(CMakeDependentOption)


project(vpn)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
