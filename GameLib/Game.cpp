/**
 * @file Game.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"


/**  Add a tile to the city
* @param tile New tile to add
*/
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}