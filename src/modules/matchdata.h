#ifndef MODULES_MATCHDATA
#define MODULES_MATCHDATA

#include <vector>
#include <map>

#include "killdata.h"

/** Represents a game match.
 * It stores the number of kills happened during the match
 * and those players responsible for the kills.
 */
class MatchData {
    public:
        MatchData(int index = 0);
        ~MatchData();

        /* From a killing details updates player kills information */
        void Update(KillData &);

        /* From a killing details updates player kills information */
        int Dump(const char *);

    private:
        int id;
        int total_kills;
        std::vector<std::string> players;
        std::map<std::string, int> kills;
};

#endif //MODULES_MATCHDATA