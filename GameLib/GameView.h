/**
 * @file GameView.h
 *
 * @author ybw0014
 * @author Melody Buado
 *
 * Implementation of a child window of our program
 */

#ifndef UML_WARS_GAMEVIEW_H
#define UML_WARS_GAMEVIEW_H

#include "Game.h"

/**
 * View class for our game
 */
class GameView : public wxWindow {
private:
    /// The game
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    bool mStandard = false;          ///< Playing the standard variant?
    bool mCustom = false;           ///< Playing the custom variant?

    void OnPaint(wxPaintEvent& event);

    void OnMouseMove(wxMouseEvent &event);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnTimer(wxTimerEvent& event);

    void OnVariantStandard(wxCommandEvent &event);

    void OnUpdateVariantStandard(wxUpdateUIEvent &event);

    void OnVariantCustom(wxCommandEvent &event);

    void OnUpdateVariantCustom(wxUpdateUIEvent &event);

public:
    void Initialize(wxFrame *mainFrame);

    void AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar, wxMenu* fileMenu, wxMenu* variantMenu);
};

#endif //UML_WARS_GAMEVIEW_H
