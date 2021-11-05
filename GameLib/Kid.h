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


    std::unique_ptr<wxSound> mSound;


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
     * Get the pointer of Pen
     * @return the pointer of pen
     */
    std::shared_ptr<Pen> GetPen() { return mPen; }
    /**
     * Mark the pen as thrown
     */
    void DoThrowing();
    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    void Update(double elapsed) override;

    /**
     * Set the rotation
     * @param angle
     */
    void SetRotation(double angle);

    /**
     * Set the pen's angle and location
     */
    void SetPen();

    /**
     * Set the kid's location
     * @param x the x coordinate
     * @param y the y coordinate
     */
    void SetLocation(double x, double y) override;

    /**
     * Test to see if we hit this object with a mouse.
     * @param x X position to test
     * @param y Y position to test
     * @return true if hit.
     */
    bool HitTest(double x, double y) override;
};

#endif //UML_WARS_KID_H
