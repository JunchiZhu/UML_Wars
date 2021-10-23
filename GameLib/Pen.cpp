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
    graphics->Translate(mPenX, mPenY);
    graphics->Rotate(mPenAngle);
    graphics->DrawBitmap(mPenBitmap, -penWid/2, -penHit/2, penWid, penHit);
    graphics->PopState();   // Restore the graphics state
}

void Pen::StartFlying(){

     penflag = true;

    //return flag;
//    SetLocation(mPenX,mPenY);
//    cse335::Vector Destination(mFinalX, mFinalY);
//    cse335::Vector Pre_Step(mPenX, mPenY);
//    cse335::Vector Path(Destination.X()-Pre_Step.X(), Destination.Y()-Pre_Step.Y());
//
//    Path.Normalize();
//    SetLocation(Path.X(),Path.Y());

}

//void Pen::Moving(double x, double y){




void Pen::Update(double elapsed)
{
    if (penflag)
    {
        SetLocation(200,200);

//        SetLocation(GetX()+mSpeedX * cos(mShootAngle) * elapsed,
//                GetY() + mSpeedY * (-sin(mShootAngle)) * elapsed);
    }
    penflag = false;

}