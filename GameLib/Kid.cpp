/**
 * @file Kid.cpp
 * @author Melody
 */

#include "pch.h"
#include "Kid.h"
#include "Pen.h"

using namespace std;

/// Variable for image representing Kid(Harold)
const std::wstring HaroldImageName = L"images/harold.png";

const double InitialPenX = 29;
const double InitialPenY = -54;

/** Constructor
* @param game The game this is a member of
*/
Kid::Kid(Game* game) : Item(game, HaroldImageName)
{
    mHaroldImage = std::make_shared<wxImage>(HaroldImageName);
    mPen = make_shared<Pen>(game);
}

/**
 * Draw the view on a graphics context
 * @param graphics Graphics context to draw on
 */
void Kid::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mHaroldBitmap.IsNull())
    {
        mHaroldBitmap = graphics->CreateBitmapFromImage(*mHaroldImage);
    }

    double haroldWid = mHaroldImage->GetWidth();
    double haroldHit = mHaroldImage->GetHeight();
    mRotation = atan2(0 - mXMouseCoord, 900 - mYMouseCoord );

    graphics->PushState();  // Save the graphics state
    graphics->Translate(0, 900);
    graphics->Rotate(-mRotation);
    mPen->Draw(graphics);
    graphics->DrawBitmap(mHaroldBitmap, -haroldWid/2, -haroldHit/2, haroldWid, haroldHit);
    graphics->PopState();   // Restore the graphics state
}


void Kid::DoThrowing()
{
    double Angle = mRotation;

    double radians = Angle*(M_PI/180)-(mHandAngle/2*3);
    mPen->ShootAngle(radians);
    mPen->StartFlying();
}

