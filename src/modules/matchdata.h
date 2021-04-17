#ifndef MODULES_MATCHDATA
#define MODULES_MATCHDATA

#include <vector>
#include <map>

#include "killdata.h"

class MatchData {
    public:
        MatchData(int);
        ~MatchData();
        void Update(KillData &);
        void Dump();

    private:
        int id;
        int total_kills;
        std::vector<std::string> players;
        std::map<std::string, int> kills;
};

#endif //MODULES_MATCHDATA