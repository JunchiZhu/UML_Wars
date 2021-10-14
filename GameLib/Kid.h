/**
 * @file Kid.h
 * @author Melody Buado
 *
 *
 */

#ifndef UML_WARS_KID_H
#define UML_WARS_KID_H

#include "Item.h"
#include <wx/graphics.h>

class Kid : public Item {
private:
    /// The item image
    std::shared_ptr<wxImage> mHaroldImage;

    /// The item bitmap
    wxGraphicsBitmap mHaroldBitmap;

public:
    Kid(Game *game);

    ///  Default constructor (disabled)
    Kid() = delete;

    ///  Copy constructor (disabled)
    Kid(const Kid &) = delete;

    ~Kid();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

};

#endif //UML_WARS_KID_H
