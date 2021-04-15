#include "killdata.h"

#include <iostream>

KillData::KillData() {}

KillData::~KillData() {}

int KillData::Parser(std::string & line) {
    if (line.find("Kill:") == std::string::npos) {
        return -1;
    }

    FindPlayer(line);
    FindDeathCause(line);    

    return 0;
}

void KillData::FindPlayer(std::string & line) {
    std::string str = line.substr(line.find_last_of(":")+1);

    player = str.substr(1, str.find("killed")-2);
}

void KillData::FindDeathCause(std::string & line) {
    std::size_t pos = line.find_last_of("by ");

    death_cause = line.substr(pos+1);
}