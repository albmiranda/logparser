#include <gtest/gtest.h>

#include "fsm/parser.h"

class NoGameStateTest : public ::testing::Test {
    protected:
        NoGameStateTest();
        virtual ~NoGameStateTest();
        virtual void SetUp();
        virtual void TearDown();

        Parser * p;
};

class RunningGameStateTest : public ::testing::Test {
    protected:
        RunningGameStateTest();
        virtual ~RunningGameStateTest();
        virtual void SetUp();
        virtual void TearDown();

        Parser * p;
};