#ifndef MODULES_STATE
#define MODULES_STATE


#include <string>
#include <iostream>

#include "parser.h"
#include "modules/matchdata.h"

class Parser;

enum GameEvent : int {
    UNKNOWN = -1,
    START = 0,
    FINISH,
    KILL
};

class GameState {
    public:
        virtual void TransitionTo(Parser *, int, const std::string &) = 0;
    protected:
        static MatchData * match;
};

class NoGameState : public GameState {
    public:
        void TransitionTo(Parser *, int, const std::string &);
        static GameState& getInstance();
    private:
        NoGameState();
};

class RunningGameState : public GameState {
    public:
        void TransitionTo(Parser *, int, const std::string &);
        static GameState& getInstance();
    public:
        RunningGameState();
};

#endif //MODULES_STATE