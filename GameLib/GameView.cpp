/**
 * @file GameView.cpp
 *
 * @author ybw0014
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "GameView.h"
#include "Kid.h"
#include "Item.h"

/**
 * Constructor
 * @param mainFrame Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* mainFrame)
{
    Create(mainFrame, wxID_ANY);

    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    // TODO: Add these events
//    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
//    Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
//    Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDoubleClick, this);
//    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
//    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
//
//    mTimer.SetOwner(this);
//    mTimer.Start(FrameDuration);
//    mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));


}