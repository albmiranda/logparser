#include <iostream>
#include <fstream>
#include <vector>

#include "modules/parser.h"
#include "modules/killdata.h"
#include "modules/matchdata.h"

int main() {

    std::ifstream logfile("../data/qgames.log", std::ifstream::in);
    if (logfile.is_open() == false) {
        std::cout << "No file found" << std::endl;
        return -1;
    }

    Parser parser;
    MatchData * matchdata = NULL;
    std::vector<MatchData*> match;

    std::string line;
    while (std::getline(logfile, line)) {

        int event = parser.CheckEvent(line);
        parser.Handle(event);
        

        // if (parser.ParserNewMatch(line) == 0) {
        //     if (matchdata != NULL) {
        //         match.push_back(matchdata);
        //     }
        //     matchdata = new MatchData(match.size());

        // } else if (parser.ParserKill(line) == 0) {
        //     KillData killdata(line);
        //     matchdata->Update(killdata);
        // }
    }

    // match.at(4)->Dump();

    delete matchdata;
    logfile.close();
    return 0;
}