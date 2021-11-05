/**
 * @file RestartTest.cpp
 * @author Matthew Baxter
 *
 * Test class for Restart Feature
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>
#include <Uml.h>
#include <UmlLoader.h>



TEST(RestartTest, Construct) {
    // Create a game to test
    Game game;

    game.IncrementCorrect();

    game.IncrementMissed();

    game.IncrementUnfair();

    game.Wipe();



    std::vector<int> test = game.GetScore();

    ASSERT_TRUE(test[0] == 0);

    ASSERT_TRUE(test[1] == 0);

    ASSERT_TRUE(test[2] == 0);

    std::shared_ptr<Uml> uml;

    game.Add(uml);

    ASSERT_FALSE(game.IsEmpty());



    game.Reset();

    game.noTime();

    game.noDuration();


    ASSERT_TRUE(game.noTimeNoDuration());













}