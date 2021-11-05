/**
 * @file Pen.h
 * @author Junchi Zhu
 * @author Melody Buado
 *
 */

#ifndef UML_WARS_PEN_H
#define UML_WARS_PEN_H

#include <wx/sound.h>
#include "Item.h"
#include "ItemVisitor.h"
#include "Kid.h"

/**
 * Pen class contains methods to manipulate the pen
 */
class Pen : public Item{
private:
    /// The pen image
    std::shared_ptr<wxImage> mPenImage;

    /// The pen bitmap
    wxGraphicsBitmap mPenBitmap;

    /// Pen angle
    double mPenAngle = -1.078;

    /// hit checker
    bool mHitCheck = false;
    ///wxSound member object
    std::unique_ptr<wxSound> mSound;

public:
    /// Default constructor (disabled)
    Pen() = delete;

    /// Copy constructor (disabled)
    Pen(const Pen &) = delete;

    /// Assignment operator
    void operator=(const Pen &) = delete;

    Pen(Game *game);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPen(this); }

    /**
     * Set the angle of pen
     * @param x the angle of pen
     */
    void SetPenAngle(double x) { mPenAngle = x;}

    /**
     * Get the angle of pen
     * @return the angle of pen
     */
    double GetPenAngle() { return mPenAngle; }


    bool HitTest(double x, double y) override;

    /**
     * Setter used to check if the pen hit an item
     * @param x bool to see if the pen hit an item
     */
    void SetterCheck(bool x){mHitCheck = x;}

    /**
     * Get the angle of pen
     * @return true if Pen hit Uml
     */
    bool HitConfirm();
};

#endif //UML_WARS_PEN_H
