include(FindBoost)
find_package(Boost 1.63.0 EXACT REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(vpn main.c++ program_options.c++)
target_link_libraries(vpn Boost::program_options)
