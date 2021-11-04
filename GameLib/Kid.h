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

    /// The angle of rotation
    double mRotation = 0;

    /// X mouse coordinate
    int mXMouseCoord = 0;

    /// Y mouse coordinate
    int mYMouseCoord = 0;

    /// The pen
    std::shared_ptr<Pen> mPen;

    /// If the pen is thrown
    bool mChecking = false;

    /// The pen's horizontal speed
    double mPenSpeedX = 300;
    /// The pen's vertical speed
    double mPenSpeedY = 600;

    /// The length of hand
    const double HandDistance = 61.3;
    /// The angle of hand
    const double HandAngle = 1.078;

public:
    Kid(Game *game);

    ///  Default constructor (disabled)
    Kid() = delete;

    ///  Copy constructor (disabled)
    Kid(const Kid &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitKid(this); }

    /**
    * Set the X mouse coordinate
    * @param x  the X mouse coordinate
    */
    void SetXMouseCoord(double x) { mXMouseCoord = x; }

    /**
     * Set the Y mouse coordinate
     * @param y the Y mouse coordinate
     */
    void SetYMouseCoord(double y) { mYMouseCoord = y; }

    /**
     * Get the pointer of Pen
     * @return the pointer of pen
     */
    std::shared_ptr<Pen> GetPen() { return mPen; }

    void DoThrowing();

    void Update(double elapsed) override;

    void SetRoataion(double angle);

    void SetPen();

    void SetLocation(double x, double y) override;

    bool HitTest(double x, double y) override;
};

#endif //UML_WARS_KID_H
