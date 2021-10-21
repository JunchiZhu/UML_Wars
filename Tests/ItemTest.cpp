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
#include <ItemVisitor.h>

/// ItemMock filename
const std::wstring HaroldImageName = L"images/harold.png";

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game) : Item(game, HaroldImageName) {}

    void Draw(wxDC *dc)  {}

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    * */
    virtual void Accept(ItemVisitor* visitor) override { }

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

    // Test a second with different values
    item.SetLocation(-72, -107);
    ASSERT_NEAR(-72, item.GetX(), 0.0001);
    ASSERT_NEAR(-107, item.GetY(), 0.0001);
}

TEST(ItemTest, HitTest) {
    // Create an item to test
    Game game;
    ItemMock item(&game);

    // Give it a location
    // Always make the numbers different, in case they are mixed up
    item.SetLocation(100, 200);

    // Center of the item should be a true
    ASSERT_TRUE(item.HitTest(100, 200));

    // Left of the item
    ASSERT_FALSE(item.HitTest(10, 200));

    // Right of the item
    ASSERT_FALSE(item.HitTest(200, 200));

    // Above the item
    ASSERT_FALSE(item.HitTest(100, 0));

    // Below the item
    ASSERT_FALSE(item.HitTest(100, 300));

    // On a transparent pixel
    ASSERT_FALSE(item.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}
