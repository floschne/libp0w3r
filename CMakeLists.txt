cmake_minimum_required(VERSION 3.4)
project(libp0w3r)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

option (ENABLE_TESTS
        "Enable the tests suite" ON)


option (BUILD_SHARED_LIBRARIES
        "Build a shared library of libp0w3r" OFF)

include_directories(/usr/local/include/ /usr/include/)
link_directories(/usr/local/lib/ /usr/lib/ /usr/lib/x86_64-linux-gnu/)

#variable that contains third party libs that will be linkt to the project
set(THIRD_PARTY_LIBS "")

#gtest
set(THIRD_PARTY_LIBS "gtest" ${THIRD_PARTY_LIBS})

set(libp0w3r_SRCS
	src/datastructures/disjoint_set/disjoint_set.cpp
)

# create library
add_library (p0w3r ${libp0w3r_SRCS})

if (BUILD_SHARED_LIBRARIES)
add_library(p0w3rShared SHARED ${libp0w3r_SRCS})
target_link_libraries(p0w3rShared ${THIRD_PARTY_LIBS})
endif (BUILD_SHARED_LIBRARIES)


################################
# Testing
################################
if (ENABLE_TESTS)

    enable_testing()

    add_subdirectory(test test)

endif()
