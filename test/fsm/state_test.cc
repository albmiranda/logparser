#define private public
#include "modules/matchdata.h"
#undef private

#define protected public
#include "fsm/state.h"
#undef protected

#include "state_test.h"

#include <string>


NoGameStateTest::NoGameStateTest() {
    p = new Parser();
}

NoGameStateTest::~NoGameStateTest() {
    delete p;
}

void NoGameStateTest::SetUp() {}

void NoGameStateTest::TearDown() {}

TEST_F(NoGameStateTest, TransitionToNotHandledEvent) {
    ASSERT_TRUE(GameState::match == NULL);
    NoGameState::getInstance().TransitionTo(p, GameEvent::UNKNOWN, std::string(""));
    NoGameState::getInstance().TransitionTo(p, GameEvent::FINISH, std::string(""));
    NoGameState::getInstance().TransitionTo(p, GameEvent::KILL, std::string(""));
    ASSERT_TRUE(GameState::match == NULL);

    ASSERT_TRUE(p->GetState() == &NoGameState::getInstance());
}

TEST_F(NoGameStateTest, TransitionToStartEvent) {
    ASSERT_TRUE(GameState::match == NULL);

    NoGameState::getInstance().TransitionTo(p, GameEvent::START, std::string(""));

    ASSERT_TRUE(GameState::match != NULL);
    ASSERT_TRUE(p->GetState() == &RunningGameState::getInstance());

    delete GameState::match;
}



// RunningGameStateTest

RunningGameStateTest::RunningGameStateTest() {
    p = new Parser();
}

RunningGameStateTest::~RunningGameStateTest() {
    delete p;
}

void RunningGameStateTest::SetUp() {
    NoGameState::getInstance().TransitionTo(p, GameEvent::START, std::string(""));
}

void RunningGameStateTest::TearDown() {}

TEST_F(RunningGameStateTest, TransitionToNotHandledEvent) {

    RunningGameState::getInstance().TransitionTo(p, GameEvent::UNKNOWN, std::string(""));
    RunningGameState::getInstance().TransitionTo(p, GameEvent::START, std::string(""));

    ASSERT_EQ(GameState::match->total_kills, 0);
    ASSERT_TRUE(p->GetState() == &RunningGameState::getInstance());

    delete GameState::match;
}

TEST_F(RunningGameStateTest, TransitionToKillEvent) {
    std::string line("  5:29 Kill: 5 2 6: Dono da Bola killed Oootsimo by MOD_ROCKET");
    RunningGameState::getInstance().TransitionTo(p, GameEvent::KILL, line);

    ASSERT_EQ(GameState::match->total_kills, 1);
    ASSERT_TRUE(p->GetState() == &RunningGameState::getInstance());

    delete GameState::match;
}

TEST_F(RunningGameStateTest, TransitionToFinishEvent) {
    RunningGameState::getInstance().TransitionTo(p, GameEvent::FINISH, std::string(""));

    ASSERT_TRUE(GameState::match == NULL);
    ASSERT_TRUE(p->GetState() == &NoGameState::getInstance());
}