include(FindGTest)
#find_package(GTest REQUIRED)
find_package(Boost 1.63.0 EXACT REQUIRED COMPONENTS program_options unit_test_framework)

add_definitions(-DBOOST_TEST_DYN_LINK)

file(GLOB TESTFILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c++")
foreach(TEST ${TESTFILES})
	get_filename_component(SUITE "${TEST}" NAME_WE)
	add_executable(test_${SUITE} ${TEST})
	target_compile_definitions("test_${SUITE}" PUBLIC "-DBOOST_TEST_MODULE=${SUITE}")
	target_link_libraries("test_${SUITE}" Boost::boost Boost::unit_test_framework)
	add_test("test_${SUITE}" "test_${SUITE}")
endforeach()
