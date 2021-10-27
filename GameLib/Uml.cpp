/**
 * @file Uml.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include "Uml.h"

/**
 * Basic constructor
 * @param game the game
 * @param name the uml class name
 * @param attributes the uml class attributes
 * @param operations the uml class operations
 */
Uml::Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations)
        : Item(game, L""), mName(name), mAttributes(attributes), mOperations(operations)
{
}

/**
 * Bad uml constructor
 * @param game the game
 * @param name the uml class name
 * @param attributes the uml class attributes
 * @param operations the uml class operations
 * @param badReason the reason why this uml is bad
 */
Uml::Uml(Game *game, std::wstring name, std::vector<std::wstring> attributes, std::vector<std::wstring> operations,
        std::wstring badReason) : Uml(game, name, attributes, operations)
{
    mBadReason = badReason;
}

/**
 * Draw the view on a graphics context
 * @param graphics Graphics context to draw on
 */
void Uml::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
        wxColour backyelColor(255,255,193);
        wxBrush rectBrush(backyelColor);
        wxPen pB(*wxBLACK);
        graphics->SetPen(pB);
        graphics->SetBrush(rectBrush);

        //graphics->DrawRectangle(0.0,200.0, 250.0,250.0);

        if(mAttributes.size()!=0)
        {
            graphics->DrawRectangle(0.0,200.0, 250.0,250.0);
            graphics->DrawText(mAttributes[0], 0.0, 200.0);

        }

}
