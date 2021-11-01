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
#include <random>

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


    double mUmlY;

    double mSpeedY = -100.0;

    double mUmlTY;


public:
    // Constructors
    Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations);
    Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations,
            std::wstring badReason);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Identify if uml is bad
     * @return if this uml is bad
     */
    bool IsBad() { return !mBadReason.empty(); }

    /**
     * Get the class name
     * @return the class name
     */
    std::wstring GetName() { return mName; }

    /**
     * Get the class attributes
     * @return the class attributes
     */
    std::vector<std::wstring> GetAttributes() { return mAttributes; }

    /**
     * Get the class operations
     * @return the class operations
     */
    std::vector<std::wstring> GetOperations() { return mOperations; }

    /**
     * Get the bad reason
     * @return the bad reason
     */
    std::wstring GetBadReason() { return mBadReason; }

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitUml(this); }

    void Update(double elapsed) override;

};

#endif //UML_WARS_UML_H
