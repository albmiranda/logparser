#include "parser.h"

Parser::Parser() {
    state = &NoGameState::getInstance();
}

Parser::~Parser() {}

void Parser::SetState(GameState & s) {
    state = &s;
}

const GameState * Parser::GetState() {
    return state;
}

void Parser::Handle(const std::string & line) {
    state->TransitionTo(this, CheckEvent(line), line);
}

int Parser::CheckEvent(const std::string & line) {
    if (ParserKill(line) == 0) {
        return GameEvent::KILL;

    } else if (ParserNewMatch(line) == 0) {
        return GameEvent::START;

    } else if (ParserEndMatch(line) == 0) {
        return GameEvent::FINISH;
    }

    return GameEvent::UNKNOWN;
}

int Parser::ParserNewMatch(const std::string& line) {
    return (line.find("InitGame:") == std::string::npos) ? -1 : 0;
}

int Parser::ParserEndMatch(const std::string& line) {
    return (line.find("ShutdownGame:") == std::string::npos) ? -1 : 0;
}

int Parser::ParserKill(const std::string& line) {
    return (line.find("Kill:") == std::string::npos) ? -1 : 0;
}