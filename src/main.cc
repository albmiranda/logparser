#include <iostream>
#include <fstream>
#include <vector>

#include "fsm/parser.h"

int main() {

    std::cout << "Quake 3 Arena Log Parser - CloudWalk" << std::endl;

    std::string path =  __FILE__;
    path = path.substr(0, path.find_last_of("/"));
    path.append("/../data/qgames.log");

    std::ifstream logfile(path, std::ifstream::in);
    if (logfile.is_open() == false) {
        std::cout << "No log file found" << std::endl;
        return -1;
    }

    Parser parser;
    std::string line;
    while (std::getline(logfile, line)) {
        parser.SetLine(line);
        parser.Handle();
    }

    logfile.close();

    std::cout << "Done!" << std::endl;
    return 0;
}