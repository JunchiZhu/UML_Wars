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

class MainFrame : public wxFrame {
private:
    /// View class for our game
    GameView *mGameView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

public:
    void Initialize();

};

#endif //UML_WARS_MAINFRAME_H
