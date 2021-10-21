/**
 * @file ItemVisitor.h
 * @author Melody Buado
 *
 * Item visitor base class
 */

#ifndef UML_WARS_ITEMVISITOR_H
#define UML_WARS_ITEMVISITOR_H

class Kid;
class Pen;
class Scoreboard;

class ItemVisitor {
private:

public:
    virtual ~ItemVisitor() {}

    /** Visit a Kid object
     * @param kid  kid we are visiting */
    virtual void VisitKid(Kid* kid) {}

    /** Visit a Pen object
     * @param pen  pen we are visiting */
    virtual void VisitPen(Pen* pen) {}

    /** Visit a Scoreboard object
     * @param pen  pen we are visiting */
    virtual void VisitScoreboard(Scoreboard* scoreboard) {}


};

#endif //UML_WARS_ITEMVISITOR_H
