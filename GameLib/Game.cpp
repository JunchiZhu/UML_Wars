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
#include "wx/graphics.h"

#include "Game.h"
#include "Item.h"
#include "Kid.h"
#include "Pen.h"
#include "Uml.h"


using namespace std;

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
    mItems.push_back(mKid->GetterPen());

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

    // Draw scoreboard and kid (and his pen of course)
    mScore->Draw(graphics);

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

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
 * Delet Old Pen in our game
 * @param item Pen to delete
 */
void Game::Delete()
{
    auto loc = find(begin(mItems), end(mItems), mKid->GetterPen());
    mItems.erase(loc);
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
    mKid->SetRoataion( atan2(900-pY,pX)-M_PI/2);
    //(0+29,900-54) Pen
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    std::vector<std::shared_ptr<Item>> toRemove;
    for (auto item : mItems)
    {
        if (OutOfPlayingArea(item) && item != mKid->GetterPen())
        {
            toRemove.push_back(item);
        }
    }

    for (auto item : toRemove)
    {
        std::vector<std::shared_ptr<Item>>::iterator it = std::find(mItems.begin(), mItems.end(), item);
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

bool Game:: IsEmpty()
{
    if (mItems.size()==0) {
        return true;
    }

    else {
        return false;

    }

}
void Game::ThrowPen(){
    mKid->DoThrowing();
}

bool Game::OutOfPlayingArea(std::shared_ptr<Item> item)
{
    double itemTop = item->GetY();
    double itemSide = item->GetX();
    if (itemSide > 1000 || itemSide < -1000 || itemTop > 1300)
    {
        return true;
    }
    return false;
}

