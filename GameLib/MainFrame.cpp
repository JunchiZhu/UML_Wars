/**
 * @file MainFrame.cpp
 *
 * @author ybw0014
 * @author Melody Buado
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include "PlayingArea.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UML Wars", wxDefaultPosition,  wxSize( 1000,800 ));

    auto sizer = new wxBoxSizer( wxVERTICAL );
    mGameView = new GameView();
    mGameView->Initialize(this);

    //mPlayingArea = new PlayingArea();
    //mPlayingArea->Initialize(this);

    sizer->Add(mGameView, 1, wxEXPAND | wxALL );
    SetSizer( sizer );
    Layout();

    CreateStatusBar();

    auto menuBar = new wxMenuBar();

    auto fileMenu = new wxMenu();
    auto variantMenu = new wxMenu();
    auto helpMenu = new wxMenu();


    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(variantMenu, L"&Variant");
    mGameView->AddMenus(this, menuBar, fileMenu, variantMenu);
    menuBar->Append(helpMenu, L"&Help");

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

