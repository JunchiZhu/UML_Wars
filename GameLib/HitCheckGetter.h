/**
 * @file HitCheckGetter.h
 * @author Junchi Zhu
 *
 *
 */

#ifndef UML_WARS_HITCHECKGETTER_H
#define UML_WARS_HITCHECKGETTER_H

#include "Uml.h"


class HitCheckGetter : public ItemVisitor{
private:

public:
    void VisitUml(Uml* uml)
    {
        uml->SetHit(true);
    }

};

#endif //UML_WARS_HITCHECKGETTER_H
