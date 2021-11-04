/**
 * @file HitCheckGetter.h
 * @author Junchi Zhu
 *
 *
 */

#ifndef UML_WARS_HITCHECKGETTER_H
#define UML_WARS_HITCHECKGETTER_H

#include "Uml.h"

/**
  *  Get HitChecker
  */
class HitCheckGetter : public ItemVisitor{
private:


/**
 * Visit a UML object
 * @param uml Uml we are visiting
 */
public:
    void VisitUml(Uml* uml)
    {
        uml->SetHit(true);
    }

};

#endif //UML_WARS_HITCHECKGETTER_H
