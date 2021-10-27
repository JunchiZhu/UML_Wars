/**
 * @file Pen.cpp
 * @author Junchi Zhu
 */

#include "pch.h"
#include "Pen.h"
using namespace std;

/// Pen filename
const wstring PenImageName = L"images/redpen.png";

const double InitialPenX = 29;
const double InitialPenY = -54;

/**
 * Constructor
 * @param game Pen is a member of Game
 */
Pen::Pen(Game *game) : Item(game, PenImageName)
{
    mPenImage = std::make_shared<wxImage>(PenImageName);
    mPenX = InitialPenX;
    mPenY = InitialPenY;
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
    graphics->Translate(mPenX, mPenY);
    graphics->Rotate(mPenAngle);
    graphics->DrawBitmap(mPenBitmap, -penWid/2, -penHit/2, penWid, penHit);
    graphics->PopState();   // Restore the graphics state
}
void Pen::StartFlying(){
    mChecking = true;
}

void Pen::Update(double elapsed)
{
    if(mChecking){
        mPenX += mSpeedX * cos(mShootAngle) * elapsed;
        mPenY -= (mSpeedY * (sin(mShootAngle))) * elapsed;
        SetLocation(mPenX,mPenY);
    }
}
