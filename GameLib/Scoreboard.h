/**
 * @file Scoreboard.h
 *
 * @author ybw0014
 * @author Melody Buado
 *
 * The item that displays score
 */

#ifndef UML_WARS_SCOREBOARD_H
#define UML_WARS_SCOREBOARD_H

#include "Item.h"
#include "ItemVisitor.h"

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

    void Draw(wxGraphicsContext *graphics) override;

    /**
     * Get the score of correct
     * @return the score of correct
     */
    int GetCorrect() const { return mNumCorrect; }

    /**
     * Get the score of missed
     * @return the score of missed
     */
    int GetMissed() const { return mNumMissed; }

    /**
     * Get the score of unfair
     * @return the score of unfair
     */
    int GetUnfair() const { return mNumUnfair; }

    /**
     * Add the score of correct
     * @param score the score to be added
     */
    void AddCorrect(int score) { mNumCorrect += score; }

    /**
     * Add the score of missed
     * @param score the score to be added
     */
    void AddMissed(int score) { mNumMissed += score; }

    /**
     * Add the score of unfair
     * @param score the score to be added
     */
    void AddUnfair(int score) { mNumUnfair += score; }

    /**
     * Add the score of correct by 1
     */
    void AddCorrect() { mNumCorrect++; }

    /**
     * Add the score of missed by 1
     */
    void AddMissed() { mNumMissed++; }

    /**
     * Add the score of unfair by 1
     */
    void AddUnfair() { mNumUnfair++; }

    void Reset();

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitScoreboard(this); }
};

#endif //UML_WARS_SCOREBOARD_H
