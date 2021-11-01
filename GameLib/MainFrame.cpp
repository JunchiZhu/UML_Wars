/**
 * @file MainFrame.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include "Scoreboard.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UML Wars", wxDefaultPosition,  wxSize( 1000,800 ));

    auto sizer = new wxBoxSizer( wxVERTICAL );
    mGameView = new GameView();
    mGameView->Initialize(this);

    sizer->Add(mGameView, 1, wxEXPAND | wxALL );
    SetSizer( sizer );
    Layout();

    CreateStatusBar();

    auto menuBar = new wxMenuBar();

    auto fileMenu = new wxMenu();
    auto variantMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto restartMenu = new wxMenu();


    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    restartMenu->Append(IDM_RESTART, "&Restart\tF1", "Restart the game");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnRestart, this, IDM_RESTART);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(variantMenu, L"&Variant");
    mGameView->AddMenus(this, menuBar, fileMenu, variantMenu);
    menuBar->Append(helpMenu, L"&Help");
    menuBar->Append(restartMenu, L"&Restart");

    SetMenuBar( menuBar );
}



/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * Application about box menu handler
 */
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(L"Welcome to UML Wars!",
            L"About UML Wars",
            wxOK,
            this);
}


/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    // mGameView->Stop();
    Destroy();
}


/**
 * Handle a restart-class event. DeletePen all items except harold and redpen.
 * Reset score
 * @param event The Restart event
 */
void MainFrame::OnRestart(wxCommandEvent& event)
{

    mGameView->ClearGame();


    mGameView->ClearBoard();



}

