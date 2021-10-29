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
    double mPenAngle;
    double mPenX;
    double mPenY;


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

    double GetPenX() { return mPenX; }
    double GetPenY() { return mPenY; }

    void SetPenAngle(double x) { mPenAngle = x;}
    void SetPenX(double x) {  mPenX=x; }
    void SetPenY(double y) {  mPenY=y; }
};

#endif //UML_WARS_PEN_H
