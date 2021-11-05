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

/**
 * Constructor
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
    graphics->DrawBitmap(mHaroldBitmap, -haroldWid / 2, -haroldHit / 2, haroldWid, haroldHit);
    graphics->PopState();   // Restore the graphics state
}

/**
 * Set the rotation
 * @param angle
 */
void Kid::SetRotation(double angle){
    mRotation = angle + 0.5;
    if(!mChecking){
        SetPen();
    }
}

/**
 * Set the pen's angle and location
 */
void Kid::SetPen(){
    if (mPen != nullptr) {
        double handAngle = mRotation + HandAngle;
        double handX = HandDistance * cos(handAngle);
        double handY = HandDistance * sin(handAngle);
        mPen->SetPenAngle(-handAngle);
        mPen->SetLocation(GetX() + handX, GetY() - handY); //(0+29,900-54)
    }
}

/**
 * Mark the pen as thrown
 */
void Kid::DoThrowing()
{
    mChecking = true;

    if(mChecking)
    {

        mSound = std::make_unique<wxSound>("audio/195937__michimuc2__short-wind-noise.wav");

        auto grab= mSound->Play(wxSOUND_ASYNC);
    }
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Kid::Update(double elapsed)
{
    if(mChecking){

        double x = mPen->GetX();
        x += 800 * cos(mPen->GetPenAngle()) * elapsed;
        double y = mPen->GetY();
        y += 800 * sin(mPen->GetPenAngle()) * elapsed;
        mPen->SetLocation(x,y);

        if (x <= -700 || x >= 700 || y <= -1200 || y >= 500)
        {
            GetGame()->DeletePen();
            auto newPen = make_shared<Pen>(GetGame());
            newPen = mPen;
            SetPen();
            GetGame()->Add(newPen);
            mChecking = false;
        }

        if (mPen->HitConfirm())
        {
            GetGame()->DeletePen();
            auto newPen = make_shared<Pen>(GetGame());
            newPen = mPen;
            SetPen();
            GetGame()->Add(newPen);
            mPen->SetterCheck(false);
            mChecking = false;
        }
    }

}
/**
 * Set the kid's location
 * @param x the x coordinate
 * @param y the y coordinate
 */
void Kid::SetLocation(double x, double y) {
    Item::SetLocation(x, y);
    SetPen();
}

/// question: 1) shooting angel is not correct? (how to make Pen to be the center instead of Kid)
/// question: 2) which Class should we write print uml message? (don't know how to connect Pen and UML)
/// hittest 函数， For (item in getgame()->mItem) -》 Item->hittest(x,y)

bool Kid::HitTest(double x, double y)
{
    double wid = mHaroldImage->GetWidth();
    double hit = mHaroldImage->GetHeight();

    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        return false;
    }
    return !mHaroldImage->IsTransparent((int)testX, (int)testY);
}