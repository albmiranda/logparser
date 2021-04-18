#include <gtest/gtest.h>

class KillDataTest : public ::testing::Test {
    protected:
        KillDataTest();
        virtual ~KillDataTest();
        virtual void SetUp();
        virtual void TearDown();
};