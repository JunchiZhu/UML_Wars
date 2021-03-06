/**
 * @file Item.h
 * @author Matthew Baxter
 * @author ybw0014
 *
 * Base class for item in the project
 */

#ifndef UML_WARS_ITEM_H
#define UML_WARS_ITEM_H

#include <memory>
#include "ItemVisitor.h"
#include "Vector.h"

class Game;
/**
 * Item class that is able to manipulate all items in the Game
 */
class Item {
private:
    /// The game this item is contained in
    Game *mGame;

    double mX = 0.0; ///< The x location of item
    double mY = 0.0; ///< The y location of item

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// Has the item been hit by the pen?
    bool mHitCheck = false;

protected:
    /// Constructor
    Item(Game *game, const std::wstring &filename);

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /**
     * Draw this item
     * @param gc Graphics context to draw on
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> gc);

    /**
     * Test to see if we hit this object with a mouse.
     * @param x X position to test
     * @param y Y position to test
     * @return true if hit.
     */
    virtual bool HitTest(double x, double y) ;

    /**
     * Get the width of the Item
     * @return Item width in pixels
     */
    virtual double GetWidth() const { return mItemBitmap->GetWidth(); }

    /**
     * Get the height of the item
     * @return item height in pixels
     */
    virtual double GetHeight() const { return mItemBitmap->GetHeight(); }

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed){};

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(ItemVisitor* visitor) = 0;

    /**
     * Get the game instance
     * @return the game
     */
    Game *GetGame() { return mGame; }

};

#endif //UML_WARS_ITEM_H
