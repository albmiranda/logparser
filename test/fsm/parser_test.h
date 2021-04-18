#include <gtest/gtest.h>

#define private public
#include "fsm/parser.h"
#undef private

class ParserTest : public ::testing::Test {
    protected:
        ParserTest();
        virtual ~ParserTest();
        virtual void SetUp();
        virtual void TearDown();

        Parser * p;
};
