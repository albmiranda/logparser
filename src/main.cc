#include <iostream>
#include <fstream>

#include "modules/killdata.h"

int main() {
    std::ifstream logfile("../data/qgames.log", std::ifstream::in);
    if (logfile.is_open() == false) {
        std::cout << "No file found" << std::endl;
        return -1;
    }

    KillData killdata;
    std::string line;
    while (std::getline(logfile, line)) {
        if (killdata.Parser(line) == 0) {
            std::cout << "add kill data into game date" << std::endl;
        }
    }

    logfile.close();
    return 0;
}