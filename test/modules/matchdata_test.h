#include <gtest/gtest.h>

#define private public
#include "modules/matchdata.h"
#undef private

class MatchDataTest : public ::testing::Test {
    protected:
        MatchDataTest();
        virtual ~MatchDataTest();
        virtual void SetUp();
        virtual void TearDown();

        MatchData * match;
};