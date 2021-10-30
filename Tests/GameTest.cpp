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
#include <Uml.h>
#include <vector>

using namespace std;

/** Testing class for the ItemVisitor */
class TestVisitor : public ItemVisitor
{
public:
    int mNumKid = 0;
    virtual void VisitKid(Kid* kid) override { mNumKid++; mNumVisits++; }

    int mNumPen = 0;
    virtual void VisitPen(Pen* pen) override { mNumPen++; mNumVisits++; }

    int mNumScoreboard = 0;
    virtual void VisitScoreboard(Scoreboard* scoreboard) override { mNumScoreboard++; mNumVisits++; }

    int mNumUml = 0;
    virtual void VisitUml(Uml* uml) override { mNumUml++; mNumVisits++; }

    int mNumVisits = 0;
};

TEST(GameTest, Visitor)
{
    // Construct a game object
    Game game;
    wstring name;
    vector<wstring> attributes;
    vector<wstring> operations;

    // Add some uml
    auto uml1 = make_shared<Uml>(&game, name, attributes, operations);
    auto uml2 = make_shared<Uml>(&game, name, attributes, operations);
    auto uml3 = make_shared<Uml>(&game, name, attributes, operations);

    game.Add(uml1);
    game.Add(uml2);
    game.Add(uml3);

    TestVisitor visitor;
    game.Accept(&visitor);
    ASSERT_EQ(1, visitor.mNumPen) << L"Visitor number of pens";
    ASSERT_EQ(3, visitor.mNumUml) << L"Visitor number of Uml";
    ASSERT_EQ(5, visitor.mNumVisits) << L"How many items visited";

    // Construct an empty game
    Game emptyGame;

    TestVisitor emptyVisitor;
    emptyGame.Accept(&emptyVisitor);
    ASSERT_EQ(2, emptyVisitor.mNumVisits) << L"How many items visited";
    ASSERT_EQ(1, emptyVisitor.mNumPen) << L"Visitor number of pens";
    ASSERT_EQ(0, emptyVisitor.mNumUml) << L"Visitor number of Uml";
    ASSERT_EQ(1, emptyVisitor.mNumKid) << L"Visitor number of kids";
    ASSERT_EQ(0, emptyVisitor.mNumScoreboard) << L"Visitor number of scoreboards";

}

TEST(GameTest, Update)
{
    // Construct a game object
    Game game;
    wstring name;
    vector<wstring> attributes;
    vector<wstring> operations;

    // Add some uml
    auto uml1 = make_shared<Uml>(&game, name, attributes, operations);
    auto uml2 = make_shared<Uml>(&game, name, attributes, operations);
    auto uml3 = make_shared<Uml>(&game, name, attributes, operations);

    game.Add(uml1);
    game.Add(uml2);
    game.Add(uml3);

    // Set uml to the right of the playing area
    uml1->SetLocation(1050, 200);
    game.Update(1);

    TestVisitor visitor1;
    game.Accept(&visitor1);
    ASSERT_EQ(2, visitor1.mNumUml) << L"Visitor number of Uml";

    // Set uml to the left of the playing area
    uml2->SetLocation(-1050, 200);
    game.Update(1);

    TestVisitor visitor2;
    game.Accept(&visitor2);
    ASSERT_EQ(1, visitor2.mNumUml) << L"Visitor number of Uml";

    // Set uml below the playing area
    uml3->SetLocation(500, 1350);
    game.Update(1);

    TestVisitor visitor3;
    game.Accept(&visitor3);
    ASSERT_EQ(0, visitor3.mNumUml) << L"No more uml";

    // Check that the pen and Harold weren't removed
    ASSERT_EQ(1, visitor3.mNumPen) << L"Visitor number of pens";
    ASSERT_EQ(1, visitor3.mNumKid) << L"Visitor number of kids";

}


