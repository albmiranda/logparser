#ifndef MODULES_STATE
#define MODULES_STATE


#include <string>
#include <iostream>

#include "parser.h"
#include "modules/matchdata.h"

class Parser;

/** FSM event available
 */
enum GameEvent : int {
    UNKNOWN = -1,
    START = 0,
    FINISH,
    KILL
};

/** Interface wich represents a state of FSM.
 * Every state reads a event and take decision if transition itself
 * to another state or not.
 */
class GameState {
    public:
        virtual void TransitionTo(Parser *, int) = 0;
    protected:
        static MatchData * match;
};

/** Represents a no running game.
 * In this state only START event will trigger some action.
 */
class NoGameState : public GameState {
    public:
        void TransitionTo(Parser *, int);
        static GameState& getInstance();
    private:
        NoGameState();
};

/** Represents a running game.
 * In this state KILL and FINISH event will trigger some action.
 */
class RunningGameState : public GameState {
    public:
        void TransitionTo(Parser *, int);
        static GameState& getInstance();
    public:
        RunningGameState();
};

#endif //MODULES_STATE