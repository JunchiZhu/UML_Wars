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

bool Pen::HitTest(double x, double y)
{
    double wid = mPenImage->GetWidth();
    double hit = mPenImage->GetHeight();

    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        return false;
    }
    return !mPenImage->IsTransparent((int)testX, (int)testY);
}

bool Pen::HitConfirm(){

    mHitCheck = GetGame()->PenHitUml(this);
    return mHitCheck;
}