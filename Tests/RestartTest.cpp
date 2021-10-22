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

    ASSERT_TRUE(test[2] == 0);\


    Uml goodUml1(&game, L"ClassNameOnly", {}, {}, L"");
    Uml goodUml2(&game, L"OneAttribute", {L"age: int"}, {}, L"");
    Uml goodUml3(&game, L"AndOneOperation", {L"hit: bool"}, {L"Shoot()"},L"");
    Uml badUml1(&game, L"badClass", {}, {}, L"Should capitalize");
    Uml badUml2(&game, L"badAttribute", {L"Age: int"}, {}, L"Don't capitalize");



    game.Reset();


    ASSERT_TRUE(game.IsEmpty());





}