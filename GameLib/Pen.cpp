/**
 * @file Pen.cpp
 * @author Junchi Zhu
 */

#include "pch.h"
#include "Pen.h"
#include "Game.h"

using namespace std;

/// Pen filename
const wstring PenImageName = L"images/redpen.png";

/**
 * Constructor
 * @param game Pen is a member of Game
 */
Pen::Pen(Game *game) : Item(game, PenImageName)
{
    mPenImage = std::make_shared<wxImage>(PenImageName);
}

/**
 * Draw the view on a graphics context
 * @param graphics Graphics context to draw on
 */
void Pen::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mPenBitmap.IsNull())
    {
        mPenBitmap = graphics->CreateBitmapFromImage(*mPenImage);
    }
    double penWid = mPenImage->GetWidth();
    double penHit = mPenImage->GetHeight();

    graphics->PushState();  // Save the graphics state
    graphics->Translate(GetX(), GetY()+900);
    graphics->Rotate((2*1.078));
    graphics->Rotate((mPenAngle));
    graphics->DrawBitmap(mPenBitmap, -penWid/2, -penHit/2, penWid, penHit);
    graphics->PopState();   // Restore the graphics state
}

bool Pen::HitTest(int x, int y)
{
    double wid = mPenImage->GetWidth();
    double hit = mPenImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mPenImage->IsTransparent((int)testX, (int)testY);
}

void Pen::SetLocation(double x, double y) {
    Item::SetLocation(x, y);
    GetGame()->DisplayMessage(this);
}