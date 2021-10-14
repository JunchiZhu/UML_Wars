/**
 * @file ItemTest.cpp
 * @author Matthew Baxter
 *
 * Test file to make sure Item is working
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>

/// Fish filename
const std::wstring HaroldImageName = L"images/harold.png";

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game) : Item(game, HaroldImageName) {}

    void Draw(wxDC *dc)  {}

};

TEST(ItemTest, Construct) {
    Game game;
    ItemMock item(&game);
}

TEST(ItemTest, GettersSetters){
    Game game;
    ItemMock item(&game);

    // Test initial values
    ASSERT_NEAR(0, item.GetX(), 0.0001);
    ASSERT_NEAR(0, item.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    item.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, item.GetX(), 0.0001);
    ASSERT_NEAR(17.2, item.GetY(), 0.0001);

    // Test a second with with different values
    item.SetLocation(-72, -107);
    ASSERT_NEAR(-72, item.GetX(), 0.0001);
    ASSERT_NEAR(-107, item.GetY(), 0.0001);
}


TEST(ItemMockTest, HitTest) {
    // Create a fish to test
    Game game;
    ItemMock kid(&game);

    // Give it a location
    // Always make the numbers different, in case they are mixed up
    kid.SetLocation(100, 200);

    // Center of the fish should be a true
    ASSERT_TRUE(kid.HitTest(100, 200));

    // Left of the fish
    ASSERT_FALSE(kid.HitTest(10, 200));

    // Right of the fish
    ASSERT_FALSE(kid.HitTest(200, 200));

    // Above the fish
    ASSERT_FALSE(kid.HitTest(100, 0));

    // Below the fish
    ASSERT_FALSE(kid.HitTest(100, 300));

    // On a fish transparent pixel
    ASSERT_FALSE(kid.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}
