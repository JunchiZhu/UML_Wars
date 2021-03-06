/**
 * @file GameView.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 * @author Matthew Baxter
 * @author Junchi Zhu
 */

#include "pch.h"
#include <wx/sound.h>
#include <wx/mediactrl.h>
#include <wx/dcbuffer.h>
#include "GameView.h"
#include "Game.h"
#include "Item.h"
#include "ids.h"

#if defined(__WXMSW__) && !defined(WXUSINGDLL)
#include "wx/link.h"
wxFORCE_LINK_MODULE(wxmediabackend_am)
wxFORCE_LINK_MODULE(wxmediabackend_qt)
wxFORCE_LINK_MODULE(wxmediabackend_wmp10)
#endif // static wxMSW build

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Constructor
 * @param mainFrame Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* mainFrame)
{
    Create(mainFrame, wxID_ANY,
            wxDefaultPosition, wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE);


    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    // TODO: Add these events
    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
//    Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
//    Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDoubleClick, this);
    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);


    Bind(wxEVT_MEDIA_LOADED, &GameView::OnMediaLoaded, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
    mMediaCtrl = std::make_unique<wxMediaCtrl>(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxMEDIABACKEND_WMP10);
    ///mMediaCtrl->Load("audio/Final Count.wav");
}

/**
 * Add menus specific to the view
 * @param mainFrame The main frame that owns the menu bar
 * @param menuBar The menu bar to add menus to
 * @param fileMenu The file menu, so we can add to it if we wish
 * @param variantMenu The variant menu, so we can add to it if we wish
 */
void GameView::AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar, wxMenu* fileMenu, wxMenu* variantMenu)
{
    // Options added to the view menu
    variantMenu->Append(IDM_VARIANT_STANDARD, L"&Standard", L"Enable to play standard version", wxITEM_CHECK);
    variantMenu->Append(IDM_VARIANT_CUSTOM, L"&Custom", L"Enable to play custom version", wxITEM_CHECK);

    // Bind events
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnVariantStandard, this, IDM_VARIANT_STANDARD);
    mainFrame->Bind(wxEVT_UPDATE_UI, &GameView::OnUpdateVariantStandard, this, IDM_VARIANT_STANDARD);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnVariantCustom, this, IDM_VARIANT_CUSTOM);
    mainFrame->Bind(wxEVT_UPDATE_UI, &GameView::OnUpdateVariantCustom, this, IDM_VARIANT_CUSTOM);
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Draw
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    // Tell the game class to draw
    wxRect rect = GetRect();

    mGame.Update(elapsed);
    gc->PushState();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
    gc->PopState();
}

/**
 * Menu event handler Variant>Standard menu option
 * @param event Menu event
 */
void GameView::OnVariantStandard(wxCommandEvent& event)
{
    mGame.SetStandardVariant(event.GetId() == IDM_VARIANT_STANDARD);
}

/**
 * Update handler for Variant>Standard menu option
 * @param event Update event
 */
void GameView::OnUpdateVariantStandard(wxUpdateUIEvent& event)
{
    event.Check(event.GetId() == IDM_VARIANT_CUSTOM ? mGame.IsStandardVariant() : !mGame.IsCustomVariant());

}

/**
 * Menu event handler Variant>Custom menu option
 * @param event Menu event
 */
void GameView::OnVariantCustom(wxCommandEvent& event)
{
    mGame.SetStandardVariant(event.GetId() == IDM_VARIANT_STANDARD);

    mMediaCtrl->Load("audio/Final Count.wav");
}

/**
 * Update handler for Variant>Standard menu option
 * @param event Update event
 */
void GameView::OnUpdateVariantCustom(wxUpdateUIEvent& event)
{
    event.Check(event.GetId() == IDM_VARIANT_CUSTOM ? mGame.IsCustomVariant() : ! mGame.IsCustomVariant());

}

/**
 * Handle the left mouse button down event
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
    mGame.ThrowPen();
}

/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event The Mouse event
*/
void GameView::OnMouseMove(wxMouseEvent &event)
{
    mGame.OnMouseMove(event.GetX(), event.GetY(), event);
    Refresh();
}

/**
 * Handle timer events
 * @param event timer event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}


void GameView::OnMediaLoaded(wxMediaEvent &event)
{
    mMediaCtrl->Play();
}