#ifndef MODULES_KILLDATA
#define MODULES_KILLDATA


#include <string>

class KillData {
    public:
        KillData();
        ~KillData();
        int Parser(std::string&);
    
    private:
        std::string player;
        std::string death_cause;

        void FindPlayer(std::string&);
        void FindDeathCause(std::string&);
};


#endif //MODULES_KILLDATA