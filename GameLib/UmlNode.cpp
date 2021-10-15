/**
 * @file UmlNode.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include "UmlNode.h"

/**
 * Basic constructor
 * @param type the node type
 * @param value the node value
 */
UmlNode::UmlNode(std::wstring type, std::wstring value) : UmlNode(type, value, L"")
{
}

/**
 * Constructor with bad reason
 * @param type the node type
 * @param value the node value
 * @param badReason the bad reason for node
 */
UmlNode::UmlNode(std::wstring type, std::wstring value, std::wstring badReason)
    : mType(type), mValue(value), mBadReason(badReason)
{
}
