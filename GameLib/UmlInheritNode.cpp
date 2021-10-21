/**
 * @file UmlInheritNode.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include "UmlInheritNode.h"

/**
 * Basic constructor
 * @param type the node type (always "inherit")
 * @param value the node value (base class name)
 * @param derived the derived class name
 */
UmlInheritNode::UmlInheritNode(std::wstring type, std::wstring value, std::wstring derived)
    : UmlNode(type, value), mDerived(derived)
{
}


/**
 * Bad node constructor
 * @param type the node type (always "inherit")
 * @param value the node value (base class name)
 * @param derived the derived class name
 * @param badReason the reason why this node is bad
 */
UmlInheritNode::UmlInheritNode(std::wstring type, std::wstring value, std::wstring derived, std::wstring badReason)
    : UmlNode(type, value, badReason), mDerived(derived)
{
}

/**
 * A bad node constructor with direction
 * @param type the node type (always "inherit")
 * @param value the node value (base class name)
 * @param derived the derived class name
 * @param direction the direction of the relationship
 * @param badReason the reason why this node is bad
 */
UmlInheritNode::UmlInheritNode(std::wstring type, std::wstring value, std::wstring derived, std::wstring direction,
        std::wstring badReason) : UmlNode(type, value, badReason),
        mDerived(derived), mDirection(direction)
{
}
