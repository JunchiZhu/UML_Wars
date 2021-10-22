/**
 * @file Kid.h
 * @author Melody Buado
 * @author Junchi Zhu
 *
 */

#ifndef UML_WARS_KID_H
#define UML_WARS_KID_H

#include "Item.h"
#include "Pen.h"
#include "ItemVisitor.h"
/**
 * Kid class contains methods to manipulate a
 * kid(Harold) object
 */
class Kid : public Item {
private:
    /// The item image
    std::shared_ptr<wxImage> mHaroldImage;

    /// The item bitmap
    wxGraphicsBitmap mHaroldBitmap;

    ///Harold's Pen
    std::unique_ptr<Pen>  mPen;

    /// The angle of rotation
    double mRotation = 0;

    /// X mouse coordinate
    int mXMouseCoord = 0;

    /// Y mouse coordinate
    int mYMouseCoord = 0;

    std::shared_ptr<Pen> pen;


public:
    Kid(Game *game);

    ///  Default constructor (disabled)
    Kid() = delete;

    ///  Copy constructor (disabled)
    Kid(const Kid &) = delete;

    void Draw(wxGraphicsContext *graphics) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitKid(this); }

    /**
    * Set the X mouse coordinate
    * @param x  the X mouse coordinate
    */
    void SetXMouseCoord(int x) { mXMouseCoord = x; }

    /**
     * Set the Y mouse coordinate
     * @param y the Y mouse coordinate
     */
    void SetYMouseCoord(int y) { mYMouseCoord = y; }

};

#endif //UML_WARS_KID_H
