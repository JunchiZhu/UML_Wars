/**
 * @file GameTest.cpp
 * @author Melody Buado
 *
 * Test file to make sure the visitor is working
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Game.h>
#include <Kid.h>
#include <Pen.h>
#include <Scoreboard.h>

using namespace std;

class TestVisitor : public ItemVisitor
{
public:
    int mNumKid = 0;
    virtual void VisitKid(Kid* kid) override { mNumKid++; }

    int mNumPen = 0;
    virtual void VisitPen(Pen* pen) override { mNumPen++; }

    int mNumScoreboard = 0;
    virtual void VisitScoreboard(Scoreboard* scoreboard) override { mNumScoreboard++; }
};

TEST(GameTest, Visitor)
{
    // Construct a game object
    Game game;

    // Add some harolds
    auto kid1 = make_shared<Kid>(&game);
    auto kid2 = make_shared<Kid>(&game);
    auto kid3 = make_shared<Kid>(&game);


    game.Add(kid1);
    game.Add(kid2);
    game.Add(kid3);

    TestVisitor visitor;
    game.Accept(&visitor);
    ASSERT_EQ(3, visitor.mNumKid) << L"Visitor number of harolds";

}

