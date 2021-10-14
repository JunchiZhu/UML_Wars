/**
 * @file Game.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"

using namespace std;

/**
 * Constructor
 */
Game::Game()
{
    // Seed the random number generator
    random_device rd;
    mRandom.seed(rd());
}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(wxDC *dc)
{
    // TODO: draw custom background
    // Draw the background
//    dc->DrawBitmap(*mBackground, 0, 0);
//
//    // Draw the text description
//    wxFont font(wxSize(0, 20),
//            wxFONTFAMILY_SWISS,
//            wxFONTSTYLE_NORMAL,
//            wxFONTWEIGHT_NORMAL);
//    dc->SetFont(font);
//    dc->SetTextForeground(wxColour(0, 64, 0));
//    dc->DrawText(L"Under the Sea!", 10, 10);

    for (auto item : mItems)
    {
        item->Draw(dc);
    }
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
 * Test an x,y click location to see if it clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return nullptr;
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
}
