#include <iostream>
#include <fstream>

int main() {

    std::ifstream logfile("../data/qgames.log", std::ifstream::in);
    if (logfile.is_open() == false) {
        std::cout << "No file found" << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(logfile, line)) {
        std::cout << line << std::endl;
    }

    logfile.close();
    return 0;
}