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
#include "Scoreboard.h"
#include "Kid.h"
#include "Pen.h"
#include "ItemVisitor.h"
/**
 * Game class that encapsulates everything the game is able to do.
 */
class Game {
private:
    std::shared_ptr<wxImage> mBackground; ///< Background image to use

    /// The background bitmap
    wxGraphicsBitmap mBackgroundBitmap;

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    ///Our Scoreboard
    std::unique_ptr<Scoreboard>  mScore;

    /// Random number generator
    std::mt19937 mRandom;
    ///Offset Value for horizontal direction
    double mXOffset = 0.0;
    ///Offset Value for vertical direction
    double mYOffset = 0.0;
    ///Scale value
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
     * Reset will clear the mItems vector
     */
    void Reset(){mItems.clear();}
    /**
     * Wipe will Reset the Scoreboard to Zero.
     */
    void Wipe(){mScore->Reset();}
    /**
     * GetScore returns a vector container of Correct, Missed, and Unfair
     * @return std::vector<int> vect container with data
     */
    std::vector<int> GetScore(){std::vector<int> vect {mScore->GetCorrect(),mScore->GetMissed(),mScore->GetUnfair()};
    return vect;}

    /**
     * Method to increase the Correct score; for testing
     */
    void IncrementCorrect(){mScore->AddCorrect();}
    /**
     * Method to increase the Missed score; for testing
     */
    void IncrementMissed(){mScore->AddMissed();}
    /**
     * Method to increase the Unfair score; for testing
     */
    void IncrementUnfair(){mScore->AddUnfair();}

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    void Accept(ItemVisitor* visitor);

    void Shooting();
};

#endif //UML_WARS_GAME_H

