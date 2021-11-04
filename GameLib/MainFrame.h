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
#include <wx/sound.h>
#include <wx/mediactrl.h>
#include "GameView.h"
#include "pch.h"

/**
 * MainFrame controls all the functions of buttons on
 * the window
 */
class MainFrame : public wxFrame {
private:
    /// View class for our game
    GameView *mGameView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);
    void OnRestart(wxCommandEvent& event);

    std::unique_ptr<wxSound> mSound;

    std::unique_ptr<wxMediaCtrl> mMediaCtrl;

public:
    void Initialize();


protected:
    void OnMediaLoaded(wxMediaEvent& event);
    void Play(wxCommandEvent& event);


};

#endif //UML_WARS_MAINFRAME_H