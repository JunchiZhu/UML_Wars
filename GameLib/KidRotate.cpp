/**
 * @file KidRotate.cpp
 * @author Melody Buado
 */

#include "pch.h"
#include "KidRotate.h"
#include "Kid.h"

/** Visit a Kid object
 * @param kid  kid we are visiting
 * */
void KidRotate::VisitKid(Kid* kid)
{
    kid->SetXMouseCoord(mXCoord);
    kid->SetYMouseCoord(mYCoord);
}


