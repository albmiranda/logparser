#include <iostream>
#include <fstream>
#include <vector>

#include "fsm/parser.h"

int main() {

    std::cout << "Quake 3 Arena Log Parser - CloudWalk" << std::endl;

    std::ifstream logfile("../data/qgames.log", std::ifstream::in);
    if (logfile.is_open() == false) {
        std::cout << "No log file found" << std::endl;
        return -1;
    }

    Parser parser;
    std::string line;
    while (std::getline(logfile, line)) {
        parser.Handle(line);
    }

    logfile.close();

    std::cout << "Done!" << std::endl;
    return 0;
}