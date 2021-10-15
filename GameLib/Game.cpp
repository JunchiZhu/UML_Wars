/**
 * @file Game.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 * @author Matthew Baxter
 */

#include "pch.h"

#include <algorithm>
#include <memory>
#include "wx/graphics.h"

#include "Game.h"
#include "Item.h"
#include "Scoreboard.h"

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
 * Draw the game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(wxGraphicsContext *graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
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
    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

    graphics->SetPen( *wxRED_PEN );
    //graphics->SetFont("Comic Sans", "Blue");
    //graphics->DrawText("Test", 100, 100);
    graphics->DrawEllipse(100, 100, 100, 100);

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
* Handle movement of the mouse over the playing area
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnMouseMove(int x, int y, wxMouseEvent& event)
{
    double oX = (x-mXOffset)/mScale;
    double oY = (y-mYOffset)/mScale;
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
