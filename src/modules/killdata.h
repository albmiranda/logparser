#ifndef MODULES_KILLDATA
#define MODULES_KILLDATA


#include <string>

class KillData {
    public:
        KillData(const std::string &);
        ~KillData();

        std::string GetPlayer();
    
    private:
        std::string player;
        std::string death_cause;

        std::string FindPlayer(const std::string&);
        std::string FindDeathCause(const std::string&);
};


#endif //MODULES_KILLDATA
