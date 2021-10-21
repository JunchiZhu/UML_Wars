/**
 * @file UmlNode.h
 *
 * @author ybw0014
 *
 * A class represents a node read from xml
 */

#ifndef UML_WARS_UMLNODE_H
#define UML_WARS_UMLNODE_H

#include <string>
#include <memory>

/**
 * A class that contains data read from xml
 */
class UmlNode {
protected:
    std::wstring mType; ///< The type of node
    std::wstring mValue; ///< The value of node
    std::wstring mBadReason; ///< The reason why node is bad, empty when not bad
public:
    // Constructors
    UmlNode(std::wstring type, std::wstring value);
    UmlNode(std::wstring type, std::wstring value, std::wstring badReason);

    /**
     * Identify if node is bad
     * @return if this node is bad
     */
    bool IsBad() { return mBadReason.empty(); }

    /**
     * Get the type of node
     * @return the type of node
     */
    std::wstring GetType() const { return mType; }

    /**
     * Get the value of node
     * @return the value of node
     */
    std::wstring GetValue() const { return mValue; }

    /**
     * Get the bad reason of node
     * @return the bad reason of node, empty when it is not bad
     */
    std::wstring GetBadReason() const { return mBadReason; }
};

#endif //UML_WARS_UMLNODE_H
