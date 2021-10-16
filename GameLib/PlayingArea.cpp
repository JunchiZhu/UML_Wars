/**
 * @file PlayingArea.cpp
 * @author Melody Buado
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "PlayingArea.h"
#include "Game.h"

/**
* Constructor
* @param mainFrame Pointer to wxFrame object, the main frame for the application
*/
void PlayingArea::Initialize(wxFrame* mainFrame)
{
    Create(mainFrame, wxID_ANY,
            wxDefaultPosition, wxSize(Game::Width, Game::Height),
            wxFULL_REPAINT_ON_RESIZE);


    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &PlayingArea::OnPaint, this);

}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void PlayingArea::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double) (newTime-mTime)*0.001;
    mTime = newTime;

    mGame.Update(elapsed);

    // Draw
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc.get(), rect.GetWidth(), rect.GetHeight());

}