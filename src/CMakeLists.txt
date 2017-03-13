set(CMAKE_CXX_FLAGS "-std=c++1y")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -g0")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -s")
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -Wall -Wunused -Wextra")
endif()

find_package(Boost 1.63.0 EXACT REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(vpn main.c++ program_options.c++)
target_link_libraries(vpn Boost::program_options)
