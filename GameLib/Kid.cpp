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
    graphics->DrawBitmap(mHaroldBitmap, -haroldWid/2, -haroldHit/2, haroldWid, haroldHit);
    graphics->PopState();   // Restore the graphics state
}


void Kid::DoThrowing()
{
    mChecking = true;
}
// Pen will go back to its original location if hit something or out of boundary
void Kid::Update(double elapsed)
{
    double handAngle = mRotation*(M_PI/180) + HandAngle;
    double handX = HandDistance * cos(handAngle);
    double handY = HandDistance * sin(handAngle);
    mPen->SetPenAngle(handAngle);
    if(mChecking){//
        double shootingAngle = handAngle;
        mPen->SetPenAngle(shootingAngle);
        // start flying, pen stop rotate, don't care about rotation
        double x = mPen->GetPenX();
        x += mPenSpeedX * cos(handAngle) * elapsed;
        double y = mPen->GetPenY();
        y += (mPenSpeedY * (-sin(handAngle))) * elapsed;
        mPen->SetPenX(x);
        mPen->SetPenY(y);
    }
    else{
        // pen still rotate
        mPen->SetPenX(handX);
        mPen->SetPenY(900-handY);
    }
}