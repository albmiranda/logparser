#include "state.h"

#include <sstream>

#include "modules/killdata.h"

// instantiate the static variable
MatchData * GameState::match = NULL;
int match_index = 0;

GameState & NoGameState::getInstance() {
    static NoGameState singleton;
    return singleton;
}

void NoGameState::TransitionTo(Parser * p, int event) {
    if (event == GameEvent::START) {
        match = new MatchData(++match_index);
        p->SetState(RunningGameState::getInstance());
    }
}

NoGameState::NoGameState() {}

GameState & RunningGameState::getInstance() {
    static RunningGameState singleton;
    return singleton;
}

void RunningGameState::TransitionTo(Parser *p, int event) {
    if (event == GameEvent::KILL) {
        KillData kill = KillData(*p->GetLine());
        match->Update(kill);

    } else if (event == GameEvent::FINISH) {
        match->Dump("../out/match.rec");
        delete GameState::match;
        GameState::match = NULL;
        p->SetState(NoGameState::getInstance());
    }
}

RunningGameState::RunningGameState() {}