/**
 * @file Game.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 * @author Matthew Baxter
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"
#include "wx/graphics.h"
#include <algorithm>


using namespace std;



/**  Add a tile to the city
* @param tile New tile to add
*/
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
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
    // INSERT YOUR DRAWING CODE HERE

    graphics->SetPen( *wxRED_PEN );
    //graphics->SetFont("Comic Sans", "Blue");
    //graphics->DrawText("Test", 100, 100);
    graphics->DrawEllipse(100, 100, 100, 100);

    graphics->PopState();
}


/**
* Handle movement of the mosue over the playing area
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnMouseMove(int x, int y, wxMouseEvent& event)
{
    double oX = (x-mXOffset)/mScale;
    double oY = (y-mYOffset)/mScale;

}