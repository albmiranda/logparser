#ifndef MODULES_PARSER
#define MODULES_PARSER


#include <string>
#include <iostream>

#include "state.h"

class GameState;

class Parser {
    public:
        Parser();
        ~Parser();
        void Handle(const std::string &);
        void SetState(GameState &);

    private:
        GameState * state;

        int CheckEvent(const std::string&);
        int ParserNewMatch(const std::string&);
        int ParserEndMatch(const std::string&);
        int ParserKill(const std::string&);
};


#endif //MODULES_PARSER