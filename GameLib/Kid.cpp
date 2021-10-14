/**
 * @file Kid.cpp
 * @author Melody
 */

#include "pch.h"
#include "Kid.h"

/** Constructor
* @param game The game this is a member of
*/
Kid::Kid(Game* game) : Item(game)
{
    mHaroldImage = std::make_shared<wxImage>(L"images/harold.png");
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

    int haroldWid = mHaroldImage->GetWidth();
    int haroldHit = mHaroldImage->GetHeight();
    graphics->DrawBitmap(mHaroldBitmap, 220, 130, haroldWid, haroldHit);

}