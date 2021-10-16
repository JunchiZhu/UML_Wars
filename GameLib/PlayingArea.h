/**
 * @file PlayingArea.h
 * @author Melody Buado
 *
 * Creates a window for the game play to occur in
 */

#ifndef UML_WARS_PLAYINGAREA_H
#define UML_WARS_PLAYINGAREA_H

#include "Game.h"

/**
 * A class to create a window for game play
 */
class PlayingArea : public wxWindow {
private:
    /// The game
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

public:
    void Initialize(wxFrame *mainFrame);
    void OnPaint(wxPaintEvent& event);


};

#endif //UML_WARS_PLAYINGAREA_H
