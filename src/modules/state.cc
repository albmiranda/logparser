#include "state.h"


GameState & NoGameState::getInstance() {
    static NoGameState singleton;
    return singleton;
}

void NoGameState::TransitionTo(Parser * p, int event) {
    if (event == GameEvent::START) {
        std::cout << "Game beginning -> start a match" << std::endl;
        p->setState(RunningGameState::getInstance());
    }
}

NoGameState::NoGameState() {};

GameState & RunningGameState::getInstance() {
    static RunningGameState singleton;
    return singleton;
}

void RunningGameState::TransitionTo(Parser *p, int event) {
    if (event == GameEvent::KILL) {
        std::cout << "add Kill" << std::endl;
    } else if (event == GameEvent::FINISH) {
        std::cout << "Game finishing -> dump" << std::endl;
        p->setState(NoGameState::getInstance());
    }
}

RunningGameState::RunningGameState() {};