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

    mScore = make_unique<Scoreboard>(this);
    mKid = make_unique<Kid>(this);
    mItems.push_back(mKid->GetterPen());


    std::vector<std::wstring> vec0;

    std::vector<std::wstring> vec1;
    vec1.push_back(L"Age: int");

    std::vector<std::wstring> vec2;
    vec2.push_back(L"Save()");
    vec2.push_back(L"Load(filename: string)");

    auto uml1 = std::make_shared<Uml>(this, L"Game", vec1, vec2, L"");
    auto uml2 = std::make_shared<Uml>(this, L"NotGame", vec0, vec0, L"");
    auto uml3 = std::make_shared<Uml>(this, L"notReallyAGame", vec0, vec0, L"should capitalize");

    Add(uml1);
    Add(uml2);
    Add(uml3);
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
    mKid->Draw(graphics);

    std::shared_ptr<Uml> t = mLoader->GenerateGoodUml();





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
 * Handle movement of the mouse over the playing area
 * @param x X location clicked on
 * @param y Y location clicked on
 * @param event wxMouseEvent event
*/
void Game::OnMouseMove(int x, int y, wxMouseEvent& event)
{
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

    mKid->SetXMouseCoord(oX);
    mKid->SetYMouseCoord(oY);
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

