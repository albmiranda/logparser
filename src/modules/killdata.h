#ifndef MODULES_KILLDATA
#define MODULES_KILLDATA


#include <string>

class KillData {
    public:
        KillData(std::string &);
        ~KillData();

        std::string GetPlayer();
    
    private:
        std::string player;
        std::string death_cause;

        std::string FindPlayer(std::string&);
        std::string FindDeathCause(std::string&);
};


#endif //MODULES_KILLDATA
