/**
 * @file UmlVisitor.h
 * @author Junchi Zhu
 *
 *
 */

#ifndef UML_WARS_UMLVISITOR_H
#define UML_WARS_UMLVISITOR_H

#include "Uml.h"

/**
  *  Get HitChecker
  */
class UmlVisitor : public ItemVisitor{
private:
    /// The Uml that is being visited
    Uml* mUml;

    /// Was the Uml hit by the pen?
    bool mWasHit = false;

public:
    /**
    * Visit a UML object
    * @param uml Uml we are visiting
    */
    void VisitUml(Uml* uml){ uml->SetHit(true); mUml = uml; mWasHit = uml->WasHit();}

    /**
     * Check if the Uml is bad
     * @return true if bad, false otherwise
     */
    bool Bad() { return mUml->IsBad(); }

    /**
     * Tell if the uml was hit
     * @return true if it was hit, false otherwise
     */
    bool WasHit() {return mWasHit;}

};

#endif //UML_WARS_UMLVISITOR_H
