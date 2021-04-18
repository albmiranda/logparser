#include "matchdata.h"

#include <fstream>
#include <algorithm>

MatchData::MatchData(int index = 0) {
    id = index;
    total_kills = 0;
}

MatchData::~MatchData() {
    players.clear();
    kills.clear();
}

void MatchData::Update(KillData & killdata) {
    total_kills++;

    if (killdata.GetPlayer().compare("<world>") == 0) {
        return;
    }

    if (std::find(players.begin(), players.end(), killdata.GetPlayer()) == players.end()) {
        players.push_back(killdata.GetPlayer());
        kills.insert(std::pair<std::string, int>(killdata.GetPlayer(), 0));
    }

    std::map<std::string, int>::iterator it = kills.find(killdata.GetPlayer()); 
    if (it != kills.end()) {
        it->second++;
    }
}

int MatchData::Dump(const char * filename) {

    if (filename == NULL || filename == "") {
        return -1;
    }

    std::ofstream dumpfile(filename, std::ios_base::app);

    dumpfile << "\"game_" << id << "\": {";

    dumpfile << "\"total_kills\": " << total_kills << ",";

    dumpfile << "\"players\": [";
    for (std::vector<std::string>::iterator it = std::begin(players); it != std::end(players); it++) {
        dumpfile << "\"" << *it << "\"";
        if (*it != players.back()) {
            dumpfile << ", ";
        }
    }
    dumpfile << "],";

    dumpfile << "\"kills\": {";
    for (std::map<std::string, int>::iterator it = kills.begin(); it != kills.end(); it++) {
        dumpfile << "\"" << it->first << "\": " << it->second;
        if (it->first != kills.rbegin()->first) {
            dumpfile << ",";
        }
    }
    dumpfile << " }";

    dumpfile << "}" << std::endl;

    return 0;
}