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
        void Handle(void);
        void SetState(GameState &);
        const GameState * GetState(void);
        void SetLine(std::string &);
        const std::string * GetLine(void);

    private:
        GameState * state;
        std::string line;

        int CheckEvent(const std::string&);
        int ParserNewMatch(const std::string&);
        int ParserEndMatch(const std::string&);
        int ParserKill(const std::string&);
};


#endif //MODULES_PARSER