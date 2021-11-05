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

    bool mWasHit = false;

public:
    /**
    * Visit a UML object
    * @param uml Uml we are visiting
    */
    void VisitUml(Uml* uml){ uml->SetHit(true); mUml = uml; mWasHit = uml->GetHit();}

    /**
     * Check if the Uml is bad
     * @return true if bad, false otherwise
     */
    bool Bad() { return mUml->IsBad(); }

    bool WasHit() {return mWasHit;}

};

#endif //UML_WARS_UMLVISITOR_H
