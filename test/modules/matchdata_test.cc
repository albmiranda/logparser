#include "matchdata_test.h"

#include <string>

#include "modules/killdata.h"



MatchDataTest::MatchDataTest() {}

MatchDataTest::~MatchDataTest() {}

void MatchDataTest::SetUp() {
    match = new MatchData();
}

void MatchDataTest::TearDown() {
    delete match;
}

TEST_F(MatchDataTest, DefaultInitial) {
    EXPECT_EQ(match->id, 0);
    EXPECT_EQ(match->total_kills, 0);
    EXPECT_EQ(match->players.empty(), true);
    EXPECT_EQ(match->kills.empty(), true);
}

TEST_F(MatchDataTest, NotDefaultInitial) {
    MatchData notdefault_match(5);

    EXPECT_EQ(notdefault_match.id, 5);
    EXPECT_EQ(notdefault_match.total_kills, 0);
    EXPECT_EQ(notdefault_match.players.empty(), true);
    EXPECT_EQ(notdefault_match.kills.empty(), true);
}

TEST_F(MatchDataTest, UpdateWorldPlayer) {
    std::string line = "  5:30 Kill: 1022 6 22: <world> killed Mal by MOD_TRIGGER_HURT";
    KillData kill(line);

    match->Update(kill);
    EXPECT_EQ(match->total_kills, 1);
    EXPECT_EQ(match->players.empty(), true);
    EXPECT_EQ(match->kills.empty(), true);
}

TEST_F(MatchDataTest, UpdateMultipleWorldPlayer) {
    std::string line = "  5:30 Kill: 1022 6 22: <world> killed Mal by MOD_TRIGGER_HURT";
    KillData kill(line);

    match->Update(kill);
    match->Update(kill);
    match->Update(kill);
    EXPECT_EQ(match->total_kills, 3);
    EXPECT_EQ(match->players.empty(), true);
    EXPECT_EQ(match->kills.empty(), true);
}

TEST_F(MatchDataTest, UpdateRegularPlayer) {
    std::string line = "  5:28 Kill: 6 7 6: Mal killed Assasinu Credi by MOD_ROCKET";
    KillData kill(line);

    match->Update(kill);
    match->Update(kill);
    EXPECT_EQ(match->total_kills, 2);
    EXPECT_EQ(match->players.size(), 1);
    EXPECT_EQ(match->kills.size(), 1);
    EXPECT_EQ(match->kills["Mal"], 2);
}

TEST_F(MatchDataTest, UpdateMultipleRegularPlayer) {
    std::string PlayerMal_line           = "  5:28 Kill: 6 7 6: Mal killed Assasinu Credi by MOD_ROCKET";
    std::string PlayerOootsimo_line      = "  5:32 Kill: 2 5 6: Oootsimo killed Dono da Bola by MOD_ROCKET";
    std::string PlayerAssasinuCredi_line = "  5:38 Kill: 7 6 1: Assasinu Credi killed Mal by MOD_SHOTGUN";
    std::string PlayerZeh_line           = "  5:23 Kill: 4 7 7: Zeh killed Assasinu Credi by MOD_ROCKET_SPLASH";

    KillData PlayerMal_kill(PlayerMal_line);
    match->Update(PlayerMal_kill);
    match->Update(PlayerMal_kill);

    KillData PlayerOootsimo_kill(PlayerOootsimo_line);
    match->Update(PlayerOootsimo_kill);

    KillData PlayerAssasinuCredi_kill(PlayerAssasinuCredi_line);
    match->Update(PlayerAssasinuCredi_kill);
    match->Update(PlayerAssasinuCredi_kill);
    match->Update(PlayerAssasinuCredi_kill);
    match->Update(PlayerAssasinuCredi_kill);

    EXPECT_EQ(match->total_kills, 7);
    EXPECT_EQ(match->players.size(), 3);
    EXPECT_EQ(match->kills.size(), 3);
    EXPECT_EQ(match->kills["Mal"], 2);
    EXPECT_EQ(match->kills["Oootsimo"], 1);
    EXPECT_EQ(match->kills["Assasinu Credi"], 4);

    KillData PlayerZeh_kill(PlayerZeh_line);
    match->Update(PlayerZeh_kill);
    match->Update(PlayerZeh_kill);

    EXPECT_EQ(match->total_kills, 9);
    EXPECT_EQ(match->players.size(), 4);
    EXPECT_EQ(match->kills.size(), 4);
    EXPECT_EQ(match->kills["Mal"], 2);
    EXPECT_EQ(match->kills["Oootsimo"], 1);
    EXPECT_EQ(match->kills["Assasinu Credi"], 4);
    EXPECT_EQ(match->kills["Zeh"], 2);
}

TEST_F(MatchDataTest, UpdateMixedPlayer) {
    std::string PlayerMal_line      = "  5:28 Kill: 6 7 6: Mal killed Assasinu Credi by MOD_ROCKET";
    std::string PlayerOootsimo_line = "  5:32 Kill: 2 5 6: Oootsimo killed Dono da Bola by MOD_ROCKET";
    std::string world_line          = "  5:30 Kill: 1022 6 22: <world> killed Mal by MOD_TRIGGER_HURT";

    KillData PlayerMal_kill(PlayerMal_line);
    match->Update(PlayerMal_kill);
    match->Update(PlayerMal_kill);

    KillData PlayerOootsimo_kill(PlayerOootsimo_line);
    match->Update(PlayerOootsimo_kill);
    match->Update(PlayerOootsimo_kill);
    match->Update(PlayerOootsimo_kill);

    EXPECT_EQ(match->total_kills, 5);
    EXPECT_EQ(match->players.size(), 2);
    EXPECT_EQ(match->kills.size(), 2);
    EXPECT_EQ(match->kills["Mal"], 2);
    EXPECT_EQ(match->kills["Oootsimo"], 3);

    KillData world_kill(world_line);
    match->Update(world_kill);
    match->Update(world_kill);
    match->Update(world_kill);
    match->Update(world_kill);
    match->Update(world_kill);

    EXPECT_EQ(match->total_kills, 10);
    EXPECT_EQ(match->players.size(), 2);
    EXPECT_EQ(match->kills.size(), 2);
    EXPECT_EQ(match->kills["Mal"], 2);
    EXPECT_EQ(match->kills["Oootsimo"], 3);
}