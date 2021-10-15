/**
 * @file Game.h
 *
 * @author ybw0014
 * @author Melody Buado
 * @author Matthew Baxter
 *
 * The class that implements our game
 */

#ifndef UML_WARS_GAME_H
#define UML_WARS_GAME_H

#include <memory>
#include <random>
#include "Item.h"

class Game {
private:
    std::unique_ptr<wxBitmap> mBackground; ///< Background image to use

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Random number generator
    std::mt19937 mRandom;

    double mXOffset = 0.0;
    double mYOffset = 0.0;
    double mScale = 0.0;
public:
    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;

    Game(); ///< Constructor

    void OnDraw(wxGraphicsContext *graphics, int width, int height);

    void Add(std::shared_ptr<Item> item);

    void OnMouseMove(int x, int y, wxMouseEvent& event);

    void Update(double elapsed);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}
};

#endif //UML_WARS_GAME_H
