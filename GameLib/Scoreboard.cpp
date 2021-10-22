/**
 * @file Scoreboard.cpp
 *
 * @author ybw0014
 */
#include <wx/graphics.h>
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
void Scoreboard::Draw(wxGraphicsContext *graphics)
{
    // Set font
    wxFont font(wxSize(0, 40),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    wxColour fontColor(0, 64, 0);
    graphics->SetFont(font, fontColor);

    // Draw text
    graphics->DrawText(L"Correct", -500, 100);
    graphics->DrawText(L"Missed", -100, 100);
    graphics->DrawText(L"Unfair", 300, 100);

    // Draw scores
    graphics->DrawText(wxString::Format(wxT("%i"), GetCorrect()), -500, 50);
    graphics->DrawText(wxString::Format(wxT("%i"), GetMissed()), -100, 50);
    graphics->DrawText(wxString::Format(wxT("%i"), GetUnfair()), 300, 50);

}

/**
 * Reset the scoreboard
 */
void Scoreboard::Reset()
{
    mNumCorrect = mNumMissed = mNumUnfair = 0;
}