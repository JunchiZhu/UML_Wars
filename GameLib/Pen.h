/**
 * @file Pen.h
 * @author Junchi Zhu
 * @author Melody Buado
 *
 */

#ifndef UML_WARS_PEN_H
#define UML_WARS_PEN_H

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
    double GetPenAngle() const { return mPenAngle; }
};

#endif //UML_WARS_PEN_H
