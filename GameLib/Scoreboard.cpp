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
    // TODO: Draw
}

/**
 * Reset the scoreboard
 */
void Scoreboard::Reset()
{
    mNumCorrect = mNumMissed = mNumUnfair = 0;
}