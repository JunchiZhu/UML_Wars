/**
 * @file ScoreboardTest.cpp
 * @author Matthew Baxter
 *
 * Test file to make sure Item is working
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Scoreboard.h>
#include <Game.h>

TEST(ScoreboardTest, Construct) {
    Game game;
    Scoreboard scoreboard(&game);
}

TEST(ScoreboardTest, GettersSetters1){
    Game game;
    Scoreboard scoreboard(&game);

    // Test initial values
    ASSERT_NEAR(0, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetUnfair(), 0.0001);

    // Test simple setters
    scoreboard.AddCorrect();
    scoreboard.AddUnfair();
    scoreboard.AddUnfair();
    ASSERT_NEAR(1, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(2, scoreboard.GetUnfair(), 0.0001);

    // Add more scores
    for (auto i = 0; i < 9; i++)
    {
        scoreboard.AddMissed();
    }
    ASSERT_NEAR(1, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(9, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(2, scoreboard.GetUnfair(), 0.0001);
}

TEST(ScoreboardTest, GettersSetters2){
    Game game;
    Scoreboard scoreboard(&game);

    // Test initial values
    ASSERT_NEAR(0, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetUnfair(), 0.0001);

    // Test setter with params
    scoreboard.AddCorrect(1);
    scoreboard.AddMissed(6);
    scoreboard.AddUnfair(8);
    ASSERT_NEAR(1, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(6, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(8, scoreboard.GetUnfair(), 0.0001);

    // Continue to add scores
    scoreboard.AddCorrect(6);
    scoreboard.AddMissed(5);
    scoreboard.AddUnfair(4);
    ASSERT_NEAR(7, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(11, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(12, scoreboard.GetUnfair(), 0.0001);
}

TEST(ScoreboardTest, Reset) {
    Game game;
    Scoreboard scoreboard(&game);

    scoreboard.AddCorrect(3);
    scoreboard.AddMissed(6);
    scoreboard.AddUnfair(9);

    scoreboard.Reset();

    // Test scores after reset
    ASSERT_NEAR(0, scoreboard.GetCorrect(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetMissed(), 0.0001);
    ASSERT_NEAR(0, scoreboard.GetUnfair(), 0.0001);
}
