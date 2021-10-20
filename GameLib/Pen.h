/**
 * @file Pen.h
 * @author Junchi Zhu
 * @author Melody Buado
 *
 */

#ifndef UML_WARS_PEN_H
#define UML_WARS_PEN_H
#include "Item.h"
#include <wx/graphics.h>
#include "ItemVisitor.h"

class Pen : public Item{
private:
    /// The pen image
    std::shared_ptr<wxImage> mPenImage;

    /// The pen bitmap
    wxGraphicsBitmap mPenBitmap;

    /// Pen angle
    double mPenAngle = 1.078;
public:
/// Default constructor (disabled)
    Pen() = delete;

    /// Copy constructor (disabled)
    Pen(const Pen &) = delete;

    /// Assignment operator
    void operator=(const Pen &) = delete;

    Pen(Game *game);

    void Draw(wxGraphicsContext *graphics) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitPen(this); }

};

#endif //UML_WARS_PEN_H
