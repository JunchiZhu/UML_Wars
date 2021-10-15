/**
 * @file Scoreboard.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include "Scoreboard.h"

/**
 * Constructor
 * @param game The game this is a member of
 */
Scoreboard::Scoreboard(Game* game) : Item(game, L"")
{
}

/**
 * Draw the view on a graphics context
 * @param graphics Graphics context to draw on
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
    wxFont font(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    wxColour fontColor(0, 64, 0);
    gc->SetFont(font, fontColor);

    // TODO: Draw scores
}

/**
 * Reset the scoreboard
 */
void Scoreboard::Reset()
{
    mNumCorrect = mNumMissed = mNumUnfair = 0;
}