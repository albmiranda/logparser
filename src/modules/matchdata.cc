#include "matchdata.h"

#include <fstream>
#include <algorithm>
#include <cstring>

MatchData::MatchData(int index) {
    id = index;
    total_kills = 0;
}

MatchData::~MatchData() {
    id = 0;
    total_kills = 0;
    players.clear();
    kills.clear();
    deaths.clear();
}

void MatchData::Update(KillData & killdata) {
    total_kills++;

    if (killdata.GetPlayer().compare("<world>") != 0) {
        // if player doesn't exist on match game data yet, so a new one is created
        if (std::find(players.begin(), players.end(), killdata.GetPlayer()) == players.end()) {
            players.push_back(killdata.GetPlayer());
            kills.insert(std::pair<std::string, int>(killdata.GetPlayer(), 0));
        }

        // updates kills information
        std::map<std::string, int>::iterator it_kills = kills.find(killdata.GetPlayer());
        it_kills->second++;
    }

    auto deathcause_index = deaths.find(killdata.GetDeathCause());
    if (deathcause_index == deaths.end()) {
        deaths.insert(std::pair<std::string, int>(killdata.GetDeathCause(), 0));
    }

    std::map<std::string, int>::iterator it_deathcause = deaths.find(killdata.GetDeathCause());
    it_deathcause->second++;
}

int MatchData::Dump(const char * filename) {

    if (filename == NULL || strcmp(filename, "") == 0) {
        return -1;
    }

    char deathcause_filename[100] = {0};
    strcat(deathcause_filename, filename);
    strcat(deathcause_filename, "_deathcause");

    std::ofstream dumpfile(filename, std::ios_base::app);
    std::ofstream dumpfile_deathcause(deathcause_filename, std::ios_base::app);

    if (id != 1) {
        dumpfile << "," << std::endl;
        dumpfile_deathcause << "," << std::endl;
    }

    // game match report
    dumpfile << "{\"game\": \"game_" << id << "\",";
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
    dumpfile << " }}";

    // deaths cause report
    dumpfile_deathcause << "{\"game\": \"game_" << id << "\",";

    dumpfile_deathcause << "\"kills_by_means\": {";
    for (std::map<std::string, int>::iterator it = deaths.begin(); it != deaths.end(); it++) {
        dumpfile_deathcause << "\"" << it->first << "\": " << it->second;
        if (it->first != deaths.rbegin()->first) {
            dumpfile_deathcause << ",";
        }
    }
    dumpfile_deathcause << " }}";

    return 0;
}