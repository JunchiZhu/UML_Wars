/**
 * @file MainFrame.h
 *
 * @author ybw0014
 * @author Melody Buado
 *
 * The top-level (main) frame of the application
 */

#ifndef UML_WARS_MAINFRAME_H
#define UML_WARS_MAINFRAME_H

#include "GameView.h"
#include "PlayingArea.h"

class MainFrame : public wxFrame {
private:
    /// View class for our game
    GameView *mGameView;

    /// A playing window for our game
    PlayingArea *mPlayingArea;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

public:
    void Initialize();

};

#endif //UML_WARS_MAINFRAME_H
