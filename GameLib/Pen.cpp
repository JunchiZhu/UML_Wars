/**
 * @file Pen.cpp
 * @author Junchi Zhu
 */

#include "Pen.h"
#include "pch.h"
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
void Pen::Draw(wxGraphicsContext *graphics)
{
    if(mPenBitmap.IsNull())
    {
        mPenBitmap = graphics->CreateBitmapFromImage(*mPenImage);
    }
    double penWid = mPenImage->GetWidth();
    double penHit = mPenImage->GetHeight();

    graphics->PushState();  // Save the graphics state
    graphics->Translate(29, 846);
    graphics->Rotate(mPenAngle);
    graphics->DrawBitmap(mPenBitmap, -penWid/2, -penHit/2, penWid, penHit);
    graphics->PopState();   // Restore the graphics state
}
