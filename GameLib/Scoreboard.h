/**
 * @file Scoreboard.h
 *
 * @author ybw0014
 *
 * The item that displays score
 */

#ifndef UML_WARS_SCOREBOARD_H
#define UML_WARS_SCOREBOARD_H

#include "Item.h"
#include <wx/graphics.h>

/**
 * The item that displays score
 */
class Scoreboard : public Item {
private:
    int mNumCorrect = 0; ///< Number of correct
    int mNumMissed = 0; ///< Number of missed
    int mNumUnfair = 0; ///< Number of unfair
public:
    Scoreboard(Game *game);

    ///  Default constructor (disabled)
    Scoreboard() = delete;

    ///  Copy constructor (disabled)
    Scoreboard(const Scoreboard &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Get the number of correct
     * @return the number of correct
     */
    int GetNumCorrect() const { return mNumCorrect; }

    /**
     * Get the number of missed
     * @return the number of missed
     */
    int GetNumMissed() const { return mNumMissed; }

    /**
     * Get the number of unfair
     * @return the number of unfair
     */
    int GetNumUnfair() const { return mNumUnfair; }

    /**
     * Add the number of correct by 1
     */
    void AddCorrect() { mNumCorrect++; }

    /**
     * Add the number of missed by 1
     */
    void AddMissed() { mNumMissed++; }

    /**
     * Add the number of unfair by 1
     */
    void AddUnfair() { mNumUnfair++; }

    void Reset();
};

#endif //UML_WARS_SCOREBOARD_H
