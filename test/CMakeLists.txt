
cmake_minimum_required(VERSION 3.4)
project(libp0w3r_Tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(/usr/local/include/ /usr/include/)
link_directories(/usr/local/lib/ /usr/lib/ /usr/lib/x86_64-linux-gnu/)

#variable that contains third party libs that will be linkt to the project
set(THIRD_PARTY_LIBS "")

#gtest
set(THIRD_PARTY_LIBS "gtest" "pthread" ${THIRD_PARTY_LIBS})

set(disjoint_set_TEST_FILES
        datastructures/disjoint_set/NodeTest.h
            )

set(SOURCE_FILES
        ${disjoint_set_TEST_FILES}

        main.cpp
        )

add_executable(libp0w3r_Tests ${SOURCE_FILES})

target_link_libraries(libp0w3r_Tests ${THIRD_PARTY_LIBS})

add_test(libp0w3rTestSuite libp0w3r_Tests)
