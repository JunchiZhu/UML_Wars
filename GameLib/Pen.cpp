/**
 * @file Pen.cpp
 * @author Junchi Zhu
 */

#include "pch.h"
#include "Pen.h"
#include "Vector.h"
using namespace std;

/// Pen filename
const wstring PenImageName = L"images/redpen.png";

/// Pen's initial velocity
const cse335::Vector PenVelocity = cse335::Vector(200, -600);

/**
 * Constructor
 * @param game Pen is a member of Game
 */
Pen::Pen(Game *game) : Item(game, PenImageName)
{
    mPenImage = std::make_shared<wxImage>(PenImageName);
    mPenPosition = cse335::Vector(29,-54);
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
    graphics->Translate(29, -54);
    graphics->Rotate(mPenAngle);
    graphics->DrawBitmap(mPenBitmap, -penWid/2, -penHit/2, penWid, penHit);
    graphics->PopState();   // Restore the graphics state
}

// velocity += velocity * elapsed
// 0
// 1. adding stuff in touch event
// mPenPosition += PenVelocity * elapsed;
