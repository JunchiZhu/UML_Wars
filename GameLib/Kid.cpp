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


    //mPen = make_shared<Pen>(GetGame()); update里
    //GetGame()->Add(mPen) , write delete
    SetPen();
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
//    mRotation = atan2(0 - mXMouseCoord, 900 - mYMouseCoord );

    graphics->PushState();  // Save the graphics state
    graphics->Translate(0, 900);
    graphics->Rotate(-mRotation);
    graphics->DrawBitmap(mHaroldBitmap, -haroldWid/2, -haroldHit/2, haroldWid, haroldHit);
    graphics->PopState();   // Restore the graphics state
}

void Kid::SetRoataion(double angle){
    mRotation = angle;
    SetPen();
}

void Kid::SetPen(){
    if (mPen != nullptr) {
        double handAngle = mRotation + HandAngle;
        double handX = HandDistance * cos(handAngle);
        double handY = HandDistance * sin(handAngle);
        mPen->SetPenAngle(handAngle);
        mPen->SetLocation(GetX()+handX,GetY()-handY);//(0+29,900-54)
    }
}

void Kid::DoThrowing()
{
    mChecking = true;
}
//以边界为限制，
// Pen will go back to its original location if hit something or out of boundary
void Kid::Update(double elapsed)
{
    if(mChecking){
        // start flying, pen stop rotate, don't care about rotation
        double x = mPen->GetX();
        x += mPenSpeedX * cos(mPen->GetPenAngle()) * elapsed;
        double y = mPen->GetY();
        y += mPenSpeedY * sin(-mPen->GetPenAngle()) * elapsed;
        mPen->SetLocation(x,y);
    }
}

void Kid::SetLocation(double x, double y) {
    Item::SetLocation(x, y);
    SetPen();
}

//how to specify the random seed when testing