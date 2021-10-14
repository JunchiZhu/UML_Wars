/**
 * @file Item.h
 * @author Matthew Baxter
 *
 *Base class for item in the project
 */
#include <wx/xml/xml.h>
#ifndef UML_WARS_ITEM_H
#define UML_WARS_ITEM_H

class Game;

class Item {
private:

    /// The game this item is contained in
    Game  *mGame;

    double mWidth = 0.0;
    double mHeight = 0.0;

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap;



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
    double GetX() const { return mWidth; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mHeight; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mWidth = x; mHeight = y; }
    virtual ~Item();

    /**
 * Draw this item
 * @param dc Device context to draw on
 */
   virtual void Draw(wxDC *dc);

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
    bool HitTest(int x, int y);


    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    virtual void XmlLoad(wxXmlNode *node);


/**
 * Get the width of the Item
 * @return Item width in pixels
 */
    int GetWidthItem() const { return mItemBitmap->GetWidth(); }


    /**
 * Get the height of the item
 * @return item height in pixels
 */
    int GetHeightItem() const { return mItemBitmap->GetHeight(); }




protected:
    /**
 * Protected Game item
 *
 */
    Item(Game *game);

};

#endif //UML_WARS_ITEM_H
