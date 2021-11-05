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
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Set font
    wxFont font(wxSize(0, 40),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    wxColour fontColor(250, 154, 127);
    graphics->SetFont(font, fontColor);

    // Draw text
    graphics->DrawText(L"Correct", -500, 100);
    graphics->DrawText(L"Missed", -100, 100);
    graphics->DrawText(L"Unfair", 300, 100);

    // Draw scores
    graphics->DrawText(wxString::Format(wxT("%i"), GetCorrect()), -470, 50);
    graphics->DrawText(wxString::Format(wxT("%i"), GetMissed()), -60, 50);
    graphics->DrawText(wxString::Format(wxT("%i"), GetUnfair()), 350, 50);

}

/**
 * Reset the scoreboard
 */
void Scoreboard::Reset()
{
    mNumCorrect = mNumMissed = mNumUnfair = 0;
}