/**
 * @file Game.h
 *
 * @author ybw0014
 * @author Melody Buado
 *
 * The class that implements our game
 */

#ifndef UML_WARS_GAME_H
#define UML_WARS_GAME_H

#include <memory>
#include <random>
#include "Item.h"

/**
 * The class that representing our game
 */
class Game {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Random number generator
    std::mt19937 mRandom;
public:
    Game(); ///< Constructor

    void OnDraw(wxDC *dc);

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void Update(double elapsed);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}
};

#endif //UML_WARS_GAME_H
