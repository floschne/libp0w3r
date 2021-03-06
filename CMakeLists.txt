cmake_minimum_required(VERSION 3.4)
project(libp0w3r)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
 
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

option (ENABLE_TESTS
        "Enable the tests suite" ON)


option (ENABLE_COVERAGE
        "Enable CoverageTests" OFF)

if(ENABLE_COVERAGE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") # debug, no optimisation
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage") # enabling coverage
endif()

include_directories(/usr/local/include/ /usr/include/)
link_directories(/usr/local/lib/ /usr/lib/ /usr/lib/x86_64-linux-gnu/)

#variable that contains third party libs that will be linkt to the project
set(THIRD_PARTY_LIBS "")

set(THIRD_PARTY_LIBS ${THIRD_PARTY_LIBS} "stdc++")

set(libp0w3rException_SRCS
    src/exceptions/Libp0w3rException.h
)

set(libp0w3r_SRCS
    ${libp0w3rException_SRCS}
        src/datastructures/disjoint_set/DisjointSet.cpp
)

# create library
add_library (p0w3r ${libp0w3r_SRCS})

################################
# Testing
################################
if(ENABLE_TESTS)
	enable_testing()

	##gtest repo
	set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")
	
	include_directories(
	    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
	    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

	set(GOOGLETEST_SOURCES
	    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
	    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

	foreach(_source ${GOOGLETEST_SOURCES})
	    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
	endforeach()

	add_library(googletest ${GOOGLETEST_SOURCES}) #create gtest lib

	#add gtest lib
	set(THIRD_PARTY_LIBS "googletest" "pthread" ${THIRD_PARTY_LIBS})
	###

    set(exception_TEST_FILES
        test/exceptions/ExceptionTest.h
    )

	set(disjoint_set_TEST_FILES
	    test/datastructures/disjoint_set/NodeTest.h
	)

	set(TEST_SOURCE_FILES
	    ${disjoint_set_TEST_FILES}
        ${exception_TEST_FILES}
	    test/main.cpp
	)


	add_executable(libp0w3r_Tests ${TEST_SOURCE_FILES})

	add_dependencies(libp0w3r_Tests googletest)
	
	target_link_libraries(libp0w3r_Tests ${THIRD_PARTY_LIBS})

	add_test(libp0w3r_TestSuite libp0w3r_Tests)
endif()
