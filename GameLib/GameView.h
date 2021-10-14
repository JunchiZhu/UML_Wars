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

    void OnVariantStandard(wxCommandEvent &event);
    void OnUpdateVariantStandard(wxUpdateUIEvent &event);

    void OnVariantCustom(wxCommandEvent &event);
    void OnUpdateVariantCustom(wxUpdateUIEvent &event);

    bool mStandard = false;          ///< Playing the standard variant?
    bool mCustom = false;           ///< Playing the custom variant?
public:
    void Initialize(wxFrame *mainFrame);

    void AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar, wxMenu* fileMenu, wxMenu* variantMenu);

};

#endif //UML_WARS_GAMEVIEW_H
