#ifndef MODULES_KILLDATA
#define MODULES_KILLDATA


#include <string>

/** Represents a line of log message with killing information.
 * Besides of storing the data (player and death causes) it also knows
 * how to identify each data from the log message line.
 */
class KillData {
    public:
        KillData(const std::string &);
        ~KillData();

        /* getters and setters */
        std::string GetPlayer();
        std::string GetDeathCause();
    
    private:
        std::string player;
        std::string death_cause;

        std::string FindPlayer(const std::string&);
        std::string FindDeathCause(const std::string&);
};


#endif //MODULES_KILLDATA
