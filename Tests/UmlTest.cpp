/**
 * @file UmlTest.cpp
 * @author ybw0014
 *
 * Test Uml
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Uml.h>

TEST(UmlTest, Constructer) {
    Game game;

    Uml goodUml1(&game, L"ClassNameOnly", {}, {});
    Uml goodUml2(&game, L"OneAttribute", {L"age: int"}, {});
    Uml goodUml3(&game, L"AndOneOperation", {L"hit: bool"}, {L"Shoot()"});
    Uml badUml1(&game, L"badClass", {}, {}, L"Should capitalize");
    Uml badUml2(&game, L"badAttribute", {L"Age: int"}, {}, L"Don't capitalize");
}

TEST(UmlTest, IsBad) {
    Game game;

    Uml goodUml1(&game, L"ClassNameOnly", {}, {});
    Uml goodUml2(&game, L"OneAttribute", {L"age: int"}, {});
    Uml goodUml3(&game, L"AndOneOperation", {L"hit: bool"}, {L"Shoot()"});
    Uml badUml1(&game, L"badClass", {}, {}, L"Should capitalize");
    Uml badUml2(&game, L"badAttribute", {L"Age: int"}, {}, L"Don't capitalize");

    ASSERT_FALSE(goodUml1.IsBad());
    ASSERT_FALSE(goodUml2.IsBad());
    ASSERT_FALSE(goodUml3.IsBad());
    ASSERT_TRUE(badUml1.IsBad());
    ASSERT_TRUE(badUml2.IsBad());
}