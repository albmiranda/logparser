#ifndef MODULES_STATE
#define MODULES_STATE


#include <string>
#include <iostream>

#include "parser.h"

class Parser;

enum GameEvent : int {
    UNKNOWN = -1,
    START = 0,
    FINISH,
    KILL
};

class GameState {
    public:
        virtual void TransitionTo(Parser *, int) = 0;
};

class NoGameState : public GameState {
    public:
        void TransitionTo(Parser *, int);
        static GameState& getInstance();
    private:
        NoGameState();
};

class RunningGameState : public GameState {
    public:
        void TransitionTo(Parser *, int);
        static GameState& getInstance();
    public:
        RunningGameState();
};

#endif //MODULES_STATE