#include "killdata.h"


KillData::KillData(std::string & line) {
    player = FindPlayer(line);
    death_cause = FindDeathCause(line);
}

KillData::~KillData() {}

std::string KillData::GetPlayer() {
    return player;
}

std::string KillData::FindPlayer(std::string & line) {
    std::string str = line.substr(line.find_last_of(":")+1);
    return str.substr(1, str.find("killed") - 2);
}

std::string KillData::FindDeathCause(std::string & line) {
    std::size_t pos = line.find_last_of("by ");
    return line.substr(pos+1);
}