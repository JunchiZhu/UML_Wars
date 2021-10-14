/**
 * @file GameView.h
 *
 * @author ybw0014
 *
 * Implementation of a child window of our program
 */

#ifndef UML_WARS_GAMEVIEW_H
#define UML_WARS_GAMEVIEW_H

#include "Game.h"

/**
 * View class for our game
 */
class GameView : public wxWindow{
private:
    /// The game
    Game mGame;

    void OnPaint(wxPaintEvent& event);
public:
    void Initialize(wxFrame *mainFrame);
};

#endif //UML_WARS_GAMEVIEW_H
