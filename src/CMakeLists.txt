set(CMAKE_CXX_FLAGS "-std=c++1y")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -g0")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -s")
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -Wall -Wunused -Wextra")
endif()

add_executable(vpn main.c++)
