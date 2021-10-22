/**
 * @file Uml.h
 *
 * @author ybw0014
 *
 * The item class that represents an UML in-game
 */

#ifndef UML_WARS_UML_H
#define UML_WARS_UML_H

#include <string>
#include <vector>
#include "Item.h"

/**
 * The Uml item class in-game
 */
class Uml : public Item {
private:
    std::wstring mName; ///< The class name
    std::vector<std::wstring> mAttributes; ///< The class attributes
    std::vector<std::wstring> mOperations; ///< The class operations

    /// The reason why uml is bad, empty if the uml is good
    std::wstring mBadReason;
public:
    /// Constructor
    Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations,
            std::wstring badReason);

    void Draw(wxGraphicsContext *graphics) override;

    void Accept(ItemVisitor* visitor) override { visitor->VisitUml(this); }
};

#endif //UML_WARS_UML_H
