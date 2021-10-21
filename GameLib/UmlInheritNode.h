/**
 * @file UmlInheritNode.h
 *
 * @author ybw0014
 *
 * A class that inherits from the UmlNode, representing a inherit node
 */

#ifndef UML_WARS_UMLINHERITNODE_H
#define UML_WARS_UMLINHERITNODE_H

#include <string>
#include "UmlNode.h"

/**
 * An inherit uml node
 */
class UmlInheritNode : public UmlNode {
private:
    std::wstring mDerived; ///< The derived class name
    std::wstring mDirection; ///< The direction
public:
    // Constructors
    UmlInheritNode(std::wstring type, std::wstring value, std::wstring derived);
    UmlInheritNode(std::wstring type, std::wstring value, std::wstring derived, std::wstring badReason);
    UmlInheritNode(std::wstring type, std::wstring value, std::wstring derived, std::wstring direction, std::wstring badReason);

    /**
     * Get the derived class name
     * @return the derived class name
     */
    std::wstring GetDerived() const { return mDerived; }

    /**
     * Get the direction of inheritance relationship
     * @return the direction of inheritance
     */
    std::wstring GetDirection() const { return mDirection; }
};

#endif //UML_WARS_UMLINHERITNODE_H
