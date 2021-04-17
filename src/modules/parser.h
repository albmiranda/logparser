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
        int CheckEvent(std::string&);
        void Handle(int);
        void setState(GameState &);

    private:
        GameState * state;

        int ParserNewMatch(std::string&);
        int ParserEndMatch(std::string&);
        int ParserKill(std::string&);
};


#endif //MODULES_PARSER