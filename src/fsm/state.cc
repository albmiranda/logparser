#include "state.h"

#include <sstream>
#include <cstdlib>

#include "modules/killdata.h"

// instantiate the static variable
MatchData * GameState::match = NULL;
int match_index = 0;

GameState & NoGameState::getInstance() {
    static NoGameState singleton;
    return singleton;
}

/** A combination NO RUNNING GAME state and START event makes a new Match
 */
void NoGameState::TransitionTo(Parser * p, int event) {
    if (event == GameEvent::START) {
        match = new MatchData(++match_index);
        p->SetState(RunningGameState::getInstance());
    }
}

NoGameState::NoGameState() {}

GameState & RunningGameState::getInstance() {
    static RunningGameState singleton;
    return singleton;
}

/** A combination of RUNNING GAME state and KILL will uptade the match information while
 * a RUNNING GAME state and FINISH event trigger a dump of match information into a file.
 */
void RunningGameState::TransitionTo(Parser *p, int event) {
    if (event == GameEvent::KILL) {
        KillData kill = KillData(*p->GetLine());
        match->Update(kill);

    } else if (event == GameEvent::FINISH) {
        std::string path =  __FILE__;
        path = path.substr(0, path.find_last_of("/"));
        path.append("/../../out/match.rec");

        match->Dump(path.c_str());
        delete GameState::match;
        GameState::match = NULL;
        p->SetState(NoGameState::getInstance());
    }
}

RunningGameState::RunningGameState() {}