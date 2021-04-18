#define private public
#include "modules/killdata.h"
#undef private
#include "killdata_test.h"

#include <string>



KillDataTest::KillDataTest() {};

KillDataTest::~KillDataTest() {};

void KillDataTest::SetUp() {};

void KillDataTest::TearDown() {};

TEST_F(KillDataTest, FindPlayerEmptyLine) {
    std::string line("");
    KillData kill(line);

    EXPECT_EQ(kill.FindPlayer(line).empty(), true);
    EXPECT_EQ(kill.GetPlayer().empty(), true);
}

TEST_F(KillDataTest, FindDeathCauseEmptyLine) {
    std::string line("");
    KillData kill(line);

    EXPECT_EQ(kill.FindDeathCause(line).empty(), true);
    EXPECT_EQ(kill.GetDeathCause().empty(), true);
}

TEST_F(KillDataTest, FindPlayerUknownContentLine) {
    std::string line("asdf hjkl");
    KillData kill(line);

    EXPECT_EQ(kill.FindPlayer(line).empty(), true);
    EXPECT_EQ(kill.GetPlayer().empty(), true);
}

TEST_F(KillDataTest, FindDeathCauseUknownContentLine) {
    std::string line("asdf hjkl");
    KillData kill(line);

    EXPECT_EQ(kill.FindDeathCause(line).empty(), true);
    EXPECT_EQ(kill.GetDeathCause().empty(), true);
}

TEST_F(KillDataTest, FindPlayerOk) {
    std::string line("  5:29 Kill: 5 2 6: Dono da Bola killed Oootsimo by MOD_ROCKET");
    KillData kill(line);

    EXPECT_EQ(kill.FindPlayer(line), std::string("Dono da Bola"));
    EXPECT_EQ(kill.GetPlayer(), std::string("Dono da Bola"));
}

TEST_F(KillDataTest, FindDeathCauseOk) {
    std::string line("  5:29 Kill: 5 2 6: Dono da Bola killed Oootsimo by MOD_ROCKET");
    KillData kill(line);

    EXPECT_EQ(kill.FindDeathCause(line), std::string("MOD_ROCKET"));
    EXPECT_EQ(kill.GetDeathCause(), std::string("MOD_ROCKET"));
}
