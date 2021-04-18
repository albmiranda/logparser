#include "killdata.h"

#include <iostream>

KillData::KillData(const std::string & line) {
    player = FindPlayer(line);
    death_cause = FindDeathCause(line);
}

KillData::~KillData() {}

std::string KillData::GetPlayer() {
    return player;
}

std::string KillData::GetDeathCause() {
    return death_cause;
}

std::string KillData::FindPlayer(const std::string & line) {
    std::string str;

    size_t pos = line.find_last_of(":");
    if (pos == std::string::npos) {
        return std::string("");
    }
    str = line.substr(pos + 1);

    pos = str.find("killed");
    if (pos == std::string::npos) {
        return std::string("");
    }

    return str.substr(1, pos - 2);
}

std::string KillData::FindDeathCause(const std::string & line) {
    std::size_t pos = line.find_last_of("by");
    if (pos == std::string::npos) {
        return std::string("");
    }

    return line.substr(pos+2);
}