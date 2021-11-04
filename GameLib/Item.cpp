/**
 * @file Item.cpp
 * @author Matthew Baxter
 * @author ybw0014
 */

#include "pch.h"
#include "Item.h"

using namespace std;

/**
 * Constructor
 * @param game The game this item is a member of
 * @param filename The name of the file to display for this item
 */
Item::Item(Game *game, const std::wstring &filename) : mGame(game)
{
    if (!filename.empty())
    {
        // Load image when it is not empty
        mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
        mItemBitmap = make_unique<wxBitmap>(*mItemImage);

    }
}


/**
 * Draw this item
 * @param gc Graphics context to draw on
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    gc->PushState();  // Save the graphics state
    gc->DrawBitmap(*mItemBitmap,
            double(GetX() - wid / 2),
            double(GetY() - hit / 2),
            wid,
            hit);
    gc->PopState();   // Restore the graphics state
}




/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(double x, double y)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return true;
}