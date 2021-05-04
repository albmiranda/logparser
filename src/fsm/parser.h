#ifndef MODULES_PARSER
#define MODULES_PARSER


#include <string>
#include <iostream>

#include "state.h"

class GameState;

/* It works like a Finit State Machine and has responsability to parser
 * every income log message creating an event based on the message received and
 * feed the transitions between states.
 */
class Parser {
    public:
        Parser();
        ~Parser();

        /* Feeds a state with an event */
        void Handle(void);

        /* setters and getters */
        void SetState(GameState &);
        const GameState * GetState(void);
        void SetLine(std::string &);
        const std::string * GetLine(void);

    private:
        GameState * state;
        std::string line;

        /* Relates a information caught by parser to a fsm event */
        int CheckEvent(const std::string&);

        /* Receives a line from log and identify presence of a new match information */
        int ParserNewMatch(const std::string&);
        /* Receives a line from log and identify presence of an end match information */
        int ParserEndMatch(const std::string&);
        /* Receives a line from log and identify presence of a killing information */
        int ParserKill(const std::string&);
};


#endif //MODULES_PARSER