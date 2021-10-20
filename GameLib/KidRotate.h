/**
 * @file KidRotate.h
 * @author Melody Buado
 *
 * A visitor for rotating Harold
 */

#ifndef UML_WARS_KIDROTATE_H
#define UML_WARS_KIDROTATE_H

#include "ItemVisitor.h"

/**
 * A visitor for rotating Harold
 */
class KidRotate : public ItemVisitor {
private:
    /// X mouse coordinate
    int mXCoord = 0;

    /// Y mouse coordinate
    int mYCoord = 0;

public:
    /**
     * Set the X mouse coordinate
     * @param x the new x coordinate
     */
    void SetX(int x) { mXCoord = x;}

    /**
     * Set the Y mouse coordinate
     * @param y the new y coordinate
     */
    void SetY(int y) { mYCoord = y; }

    void VisitKid(Kid* kid);

};


#endif //UML_WARS_KIDROTATE_H
