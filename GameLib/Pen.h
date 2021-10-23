/**
 * @file Pen.h
 * @author Junchi Zhu
 * @author Melody Buado
 *
 */

#ifndef UML_WARS_PEN_H
#define UML_WARS_PEN_H

#include <wx/graphics.h>
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
    double mPenAngle = 1.078;

    /// pen Location
    cse335::Vector mPenPosition;

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
     * Set angle of the pen
     *
     */
    void SetAngle() { mPenAngle = 1.078; }

};

#endif //UML_WARS_PEN_H
