/**
 * @file KidTest.cpp
 * @author Melody Buado
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Kid.h>

TEST(KidTest, Construct){
    Game game;
    Kid kid(&game);
}
