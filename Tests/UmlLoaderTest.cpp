/**
 * @file UmlLoaderTest.cpp
 * @author ybw0014
 *
 * Test UmlLoader
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <UmlLoader.h>

TEST(UmlLoaderTest, Constructer) {
    Game game;
    UmlLoader loader(&game);
}

TEST(UmlLoaderTest, Loader) {
    Game game;
    UmlLoader loader(&game);
    loader.Load();

    // test if loader loads correct number of nodes
    ASSERT_EQ(loader.GetNumNames(), 8);
    ASSERT_EQ(loader.GetNumAttributes(), 16);
    ASSERT_EQ(loader.GetNumOperations(), 10);
    ASSERT_EQ(loader.GetNumInheritances(), 7);
}
