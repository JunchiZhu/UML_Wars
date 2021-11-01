/**
 * @file Kid.cpp
 * @author Melody
 */

#include "pch.h"
#include "Kid.h"
#include "Pen.h"
#include "Game.h"

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

    graphics->PushState();  // Save the graphics state
    graphics->Translate(0, 900);
    graphics->Rotate(-mRotation);
    graphics->DrawBitmap(mHaroldBitmap, -haroldWid/2, -haroldHit/2, haroldWid, haroldHit);
    graphics->PopState();   // Restore the graphics state
}

void Kid::SetRoataion(double angle){
    mRotation = angle+0.5;
    if(!mChecking){
        SetPen();
    }
}

void Kid::SetPen(){
    if (mPen != nullptr) {
        double handAngle = mRotation + HandAngle;
        double handX = HandDistance * cos(handAngle);
        double handY = HandDistance * sin(handAngle);
        mPen->SetPenAngle(-handAngle);
        mPen->SetLocation(GetX()+handX,GetY()-handY);//(0+29,900-54)
    }
}

void Kid::DoThrowing()
{
    mChecking = true;
}

void Kid::Update(double elapsed)
{
    if(mChecking){
        double x = mPen->GetX();
        x += 500 * cos(mPen->GetPenAngle()) * elapsed;
        double y = mPen->GetY();
        y += 500 * sin(mPen->GetPenAngle()) * elapsed;
        mPen->SetLocation(x,y);
        if(x<=-700 || x>=700 || y<=-1200 || y>500){
            GetGame()->Delete();
            auto newPen = make_shared<Pen>(GetGame());
            newPen = mPen;
            SetPen();
            GetGame()->Add(newPen);
            mChecking = false;
        }
    }
}

void Kid::SetLocation(double x, double y) {
    Item::SetLocation(x, y);
    SetPen();
}

/// question: 1) shooting angel is not correct? (how to make Pen to be the center instead of Kid)
/// question: 2) which Class should we write print uml message? (don't know how to connect Pen and UML)
/// hittest 函数， For (item in getgame()->mItem) -》 Item->hittest(x,y)