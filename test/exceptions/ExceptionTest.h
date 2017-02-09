#ifndef LIBP0W3R_EXCEPTIONTEST_H
#define LIBP0W3R_EXCEPTIONTEST_H

#include <gtest/gtest.h>

#include "../../src/exceptions/Libp0w3rException.h"

using namespace libp0w3r;

TEST(ExceptionTests, Libp0w3rExceptionTest) {

    try {
        throw Libp0w3rException();
    } catch (Libp0w3rException& e) {
        std::string msg{e.what()};

        ASSERT_EQ(msg, "libp0w3r Exception thrown!\n");
    }
}

TEST(ExceptionTests, IllegalNullptrAssignmentExceptionTest) {
    try {
        throw IllegalNullptrAssignmentException("Test");
    } catch (Libp0w3rException& e) {
        std::string msg{e.what()};

        ASSERT_EQ(msg, "libp0w3r Exception thrown!\n=> IllegalNullptrAssignmentException\nTest");
    }
}

#endif //LIBP0W3R_EXCEPTIONTEST_H
