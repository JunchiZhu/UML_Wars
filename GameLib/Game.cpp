/**
 * @file Game.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"

/**  Draw the game
* @param graphics The GDI+ graphics context to draw on
*/
void Game::OnDraw(wxDC* graphics)
{
    for (auto item : mItems)
    {
        item->Draw(graphics);
    }
}

/**  Add a tile to the city
* @param tile New tile to add
*/
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}