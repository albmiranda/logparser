#include "parser_test.h"

ParserTest::ParserTest() {}

ParserTest::~ParserTest() {}

void ParserTest::SetUp() {
    p = new Parser();
}

void ParserTest::TearDown() {
    delete p;
}

TEST_F(ParserTest, DefaultInit) {
    ASSERT_EQ(p->GetState(), &NoGameState::getInstance());
}

TEST_F(ParserTest, SetStateOk) {
    ASSERT_EQ(p->GetState(), &NoGameState::getInstance());
    p->SetState(RunningGameState::getInstance());
    ASSERT_EQ(p->GetState(), &RunningGameState::getInstance());
}

TEST_F(ParserTest, ParserNewMatchNok) {
    std::string line("  0:00 00");
    ASSERT_EQ(p->ParserNewMatch(line), -1);
}

TEST_F(ParserTest, ParserNewMatchOk) {
    std::string line("  0:00 InitGame: \\sv_floodProtect\\1\\sv_maxPing\\0\\sv_minPing\\0\\sv_maxRate\10000");
    ASSERT_EQ(p->ParserNewMatch(line), 0);
}

TEST_F(ParserTest, ParserEndMatchNok) {
    std::string line(" 54:21 asdfg:");
    ASSERT_EQ(p->ParserEndMatch(line), -1);
}

TEST_F(ParserTest, ParserEndMatchOk) {
    std::string line(" 54:21 ShutdownGame:");
    ASSERT_EQ(p->ParserEndMatch(line), 0);
}

TEST_F(ParserTest, ParserKillNok) {
    std::string line(" 15:54 5 Assasinu Credi killed Zeh by MOD_ROCKET");
    ASSERT_EQ(p->ParserKill(line), -1);
}

TEST_F(ParserTest, ParserKillOk) {
    std::string line(" 15:54 Kill: 5 2 6: Assasinu Credi killed Zeh by MOD_ROCKET");
    ASSERT_EQ(p->ParserKill(line), 0);
}

TEST_F(ParserTest, CheckEventUnknown) {
    std::string line(" bar foo tar");
    ASSERT_EQ(p->CheckEvent(line), GameEvent::UNKNOWN);
}

TEST_F(ParserTest, CheckEventStart) {
    std::string line("  0:00 InitGame: \\sv_floodProtect\\1\\sv_maxPing\\0\\sv_minPing\\0\\sv_maxRate\\10000");
    ASSERT_EQ(p->CheckEvent(line), GameEvent::START);
}

TEST_F(ParserTest, CheckEventFinish) {
    std::string line(" 54:21 ShutdownGame:");
    ASSERT_EQ(p->CheckEvent(line), GameEvent::FINISH);
}

TEST_F(ParserTest, CheckEventKill) {
    std::string line(" 15:54 Kill: 5 2 6: Assasinu Credi killed Zeh by MOD_ROCKET");
    ASSERT_EQ(p->CheckEvent(line), GameEvent::KILL);
}