#include "parser.h"

Parser::Parser() {
    state = &NoGameState::getInstance();
}

Parser::~Parser() {}

void Parser::setState(GameState & s) {
    state = &s;
}

int Parser::CheckEvent(std::string & line) {
    if (ParserKill(line) == 0) {
        return GameEvent::KILL;

    } else if (ParserNewMatch(line) == 0) {
        return GameEvent::START;

    } else if (ParserEndMatch(line) == 0) {
        return GameEvent::FINISH;
    }

    return GameEvent::UNKNOWN;
}

void Parser::Handle(int event) {
    state->TransitionTo(this, event);
}

int Parser::ParserNewMatch(std::string& line) {
    return (line.find("InitGame:") == std::string::npos) ? -1 : 0;
}

int Parser::ParserEndMatch(std::string& line) {
    return (line.find("ShutdownGame:") == std::string::npos) ? -1 : 0;
}

int Parser::ParserKill(std::string& line) {
    return (line.find("Kill:") == std::string::npos) ? -1 : 0;
}