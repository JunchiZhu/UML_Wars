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
void Pen::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mPenBitmap.IsNull())
    {
        mPenBitmap = graphics->CreateBitmapFromImage(*mPenImage);
    }

    int penWid = mPenImage->GetWidth();
    int penHit = mPenImage->GetHeight();
    graphics->DrawBitmap(mPenBitmap, 250, 100, penWid, penHit);
}


