/**
 * @file Game.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 * @author Matthew Baxter
 * @author Junchi Zhu
 */

#include "pch.h"
#include <algorithm>
#include <cmath>
#include "Game.h"
#include "Item.h"
#include "Kid.h"
#include "Uml.h"
#include "UmlVisitor.h"

using namespace std;

/// The interval for umls to generate (in seconds)
const int UmlGenerateInterval = 3;

/**
 * Constructor
 */
Game::Game()
{
    mBackground = std::make_shared<wxImage>(
            L"images/background.png", wxBITMAP_TYPE_ANY);

    // Seed the random number generator
    random_device rd;
    mRandom.seed(rd());

    // load the umls
    mLoader = make_unique<UmlLoader>(this);
    mLoader->Load();

    // load the scoreboard
    mScore = make_unique<Scoreboard>(this);

    // load Harold
    mKid = make_shared<Kid>(this);
    mItems.push_back(mKid);
    mItems.push_back(mKid->GetPen());

}

/**
 * Draw the game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = min(scaleX, scaleY);

    mXOffset = width / 2;
    mYOffset = 0;
    if (height > Height * mScale) {
        mYOffset = (float)((height - Height * mScale) / 2);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //

    if (!mPlayingStandard)
    {
        if(mBackgroundBitmap.IsNull())
        {
            mBackgroundBitmap = graphics->CreateBitmapFromImage(*mBackground);
        }
        graphics->DrawBitmap(mBackgroundBitmap, -700, 0, 1400, 1000);

    }

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

    // Draw scoreboard and kid (and his pen of course)
    mScore->Draw(graphics);

    //
    // Draw filled rectangles
    wxBrush rectBrush(*wxBLACK);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(wxNullGraphicsPen);
    graphics->DrawRectangle(700, 0, 200000, 1000);
    graphics->DrawRectangle(-200700, 0, 200000, 1000);
    graphics->DrawRectangle(-1000, -199999, 20000, 200000);
    graphics->DrawRectangle(-1000, 999, 2000, 200000);

    graphics->PopState();
}

/**
 * Add an item to our game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Delete the old Pen in our game
 *
 */
void Game::DeletePen()
{
    auto loc = find(mItems.begin(), mItems.end(), mKid->GetPen());
    if (loc != mItems.end())
    {
        mItems.erase(loc);
    }
}

/**
 * Handle movement of the mouse over the playing area
 * @param x X location clicked on
 * @param y Y location clicked on
 * @param event wxMouseEvent event
*/
void Game::OnMouseMove(double x, double y, wxMouseEvent& event)
{
    double pX = (x - mXOffset) / mScale;
    double pY = (y - mYOffset) / mScale;

    //atan2(oY-(900 - 54),oX-(0 + 29))
    mKid->SetRoataion(atan2(900 - pY, pX) - M_PI / 2);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    mDuration += elapsed;
    mTime += elapsed;

    // generate uml with specific interval
    if(mDuration >= UmlGenerateInterval)
    {
        uniform_int_distribution goodOrBad(0, 1);
        shared_ptr<Uml> uml;
        if (goodOrBad(GetRandom()) == 1)
        {
            uml = mLoader->GenerateGoodUml();
        }
        else
        {
            uml = mLoader->GenerateBadUml();
        }
        Add(uml);
        mDuration = 0;
    }

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    // Check if the uml went out of the playing area
    std::vector<std::shared_ptr<Item>> toRemove;
    for (auto item : mItems)
    {
        if (OutOfPlayingArea(item) && item !=mKid->GetPen())
        {
            toRemove.push_back(item);
            UmlVisitor visitor;
            item->Accept(&visitor);

            // Add to the missed score
            if (visitor.Bad() && !visitor.WasHit())
            {
                mScore->AddMissed();
            }

        }
    }

    // Remove all uml that went out of the playing area
    for (auto item : toRemove)
    {
        auto it = std::find(mItems.begin(), mItems.end(), item);
        mItems.erase(it);
    }

}

/**
* Accept a visitor for the collection
* @param visitor The visitor for the collection
*/
void Game::Accept(ItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

/**
 * Function to check if the game items is empty or not.
 * @return boolean true if empty; false otherwise
 */
bool Game::IsEmpty()
{
    return mItems.size() == 2;
}

/**
 * Throw the pen
 */
void Game::ThrowPen(){
    mKid->DoThrowing();
}

/**
 * Check if an item is out of playing area
 * @param item The item to be checked
 * @return if the item is out of playing area
 */
bool Game::OutOfPlayingArea(std::shared_ptr<Item> item)
{
    double itemTop = item->GetY();
    double itemSide = item->GetX();
    return itemSide > 700 || itemSide < -700 || itemTop > 1000;
}

/**
 * Ask Kid to throw the Pen, like a trigger
 *  @param pen the pen that is doing the hitting
 *  @return true if Pen Hit Uml otherwise false
 */
bool Game::PenHitUml(Item *pen){
    for(auto item:mItems){
        if (item.get() == pen)
        {
            continue;
        }
        if (item->HitTest((double)pen->GetX(), (double)pen->GetY()+900))
        {
            UmlVisitor visitor;
            item->Accept(&visitor);
            if (visitor.Bad())
            {
                mScore->AddCorrect();
            }
            else
            {
                mScore->AddUnfair();
            }
            return true;
        }
    }
    return false;
}

/**
 * A test function which is used to check HitTest function is work or not
 * @param x the item's x coordinate
 * @param y the item's y coordinate
 * @return the hit Item
 */
std::shared_ptr<Item> Game::HitCheck(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }
    return  nullptr;
}


