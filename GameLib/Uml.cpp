/**
 * @file Uml.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include "Uml.h"

/**
 * Constructor
 * @param game the game
 * @param name the uml class name
 * @param attributes the uml class attributes
 * @param operations the uml class operations
 * @param badReason the reason why this uml is bad
 */
Uml::Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations,
        std::wstring badReason) : Item(game, L""), mName(name), mAttributes(attributes),
        mOperations(operations), mBadReason(badReason)
{
}