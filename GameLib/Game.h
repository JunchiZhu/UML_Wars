/**
 * @file Game.h
 *
 * @author ybw0014
 *
 * The class that implements our game
 */

#ifndef UML_WARS_GAME_H
#define UML_WARS_GAME_H

class Game {
private:

public:
    Game(); ///< Constructor
    ~Game(); ///< Destructor

    void OnDraw(wxDC *dc);
};

#endif //UML_WARS_GAME_H
