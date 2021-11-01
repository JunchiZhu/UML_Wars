/**
 * @file Uml.cpp
 *
 * @author ybw0014
 * @author Matthew Baxter
 */

#include "pch.h"
#include <random>
#include <algorithm>
#include "Game.h"
#include "Uml.h"

/// Font size
const int FontSize = 20;
/// Font weight
const int FontWeight = 10;

/// Block padding (left & right)
const double BlockPaddingX = 5.0;
/// Block padding (top & bottom)
const double BlockPaddingY = 3.0;

/// The minimum x speed
const double MinXSpeed = 5.0;
/// The maximum x speed
const double MaxXSpeed = 20.0;

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
    double locBoundary = Game::Width / 5.0 * 2.0;

    // x location
    std::uniform_real_distribution distLoc(-locBoundary, locBoundary);
    double locX = distLoc(game->GetRandom());

    SetLocation(locX, 0.0);

    // x speed
    std::uniform_real_distribution distSpeedX(MinXSpeed, MaxXSpeed);
    mSpeedX = distSpeedX(game->GetRandom());
    // if the uml is in right half, it moves left, otherwise moves right
    if (locX > 0)
    {
        mSpeedX = -mSpeedX;
    }

    // y speed
    // TODO: accelerate y speed as time elapses
    mSpeedY = 5.0;
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
    // background
    wxColour bgColor(255,255,193);
    wxBrush bgBrush(bgColor);
    graphics->SetBrush(bgBrush);

    // border
    graphics->SetPen(*wxBLACK_PEN);

    // font
    wxFont font(wxSize(0, FontSize),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxBLACK);

    // get maximum string length
    unsigned long maxLength = mName.length();
    for (auto attribute : mAttributes)
    {
        maxLength = std::max(maxLength, attribute.length());
    }
    for (auto operation : mOperations)
    {
        maxLength = std::max(maxLength, operation.length());
    }

    // Draw the overall rectangle
    double rectWidth = maxLength * 1.0 * FontWeight + 2 * BlockPaddingX;

    int num = mAttributes.size() + mOperations.size(); // the number of attributes and operations
    double rectHeight = FontSize + 2 * BlockPaddingY;
    if (num > 0)
    {
        for (auto i = 0; i < num; i++)
        {
            rectHeight += FontSize + 2 * BlockPaddingY;
        }
    }
    else
    {
        rectHeight += 2 * BlockPaddingY;
    }

    graphics->DrawRectangle(GetX(), GetY(), rectWidth, rectHeight);

    double yPos = GetY();

    // name
    double nameLocX = GetX() + rectWidth / 2 - mName.length() * 1.0 * FontWeight / 2;
    graphics->DrawText(mName, nameLocX, yPos + BlockPaddingY);
    yPos += FontSize + 2 * BlockPaddingY;

    // dividing line
    graphics->StrokeLine(GetX(), yPos, GetX() + rectWidth, yPos);

    // attributes
    for (auto attribute : mAttributes)
    {
        graphics->DrawText(attribute, GetX() + BlockPaddingX, yPos + BlockPaddingY);
        yPos += FontSize + 2 * BlockPaddingY;
    }

    // dividing line
    graphics->StrokeLine(GetX(), yPos, GetX() + rectWidth, yPos);

    // operations
    for (auto operation : mOperations)
    {
        graphics->DrawText(operation, GetX() + BlockPaddingX, yPos + BlockPaddingY);
        yPos += FontSize + 2 * BlockPaddingY;
    }
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Uml::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed, GetY() + mSpeedY * elapsed);
}
