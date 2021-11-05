/**
 * @file SoundStuff.cpp
 * @author matt5
 */

#include "pch.h"
#include "SoundStuff.h"
#include "ids.h"

#if defined(__WXMSW__) && !defined(WXUSINGDLL)
#include "wx/link.h"
wxFORCE_LINK_MODULE(wxmediabackend_am)
wxFORCE_LINK_MODULE(wxmediabackend_qt)
wxFORCE_LINK_MODULE(wxmediabackend_wmp10)
#endif // static wxMSW build





/**
 * constructor
 * @param parent
 */
SoundStuff::SoundStuff(wxWindow *parent) {

    ///wxMediaCtrl(parent, IDM_MUSIC,  L"/audio/final-count-by-kevin-macleod-from-filmmusic-io.mp3", wxDefaultPosition, wxDefaultSize, 0);
    ///get.Load(wxGetCwd() + L"/audio/final-count-by-kevin-macleod-from-filmmusic-io.mp3");
    ///get.Bind(wxEVT_MEDIA_LOADED, &SoundStuff::OnPlay, this, IDM_MUSIC);

    ///get.Load(wxGetCwd() + L"/audio/final-count-by-kevin-macleod-from-filmmusic-io.mp3");

    mMediaCtrl = std::make_unique<wxMediaCtrl>(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxMEDIABACKEND_WMP10);


    ///Load("audio/final-count-by-kevin-macleod-from-filmmusic-io.mp3");

    Bind(wxEVT_MEDIA_LOADED, &SoundStuff::OnPlay, this);


    mMediaCtrl->Load("audio/172561__djgriffin__video-game-7.wav");

    ///Play a song on loop
    ///Sound = std::make_unique<wxSound>("audio/48543__flick3r__rezzo-3.wav");


    ///auto grab= mSound->Play(wxSOUND_ASYNC|wxSOUND_LOOP);

}


void SoundStuff::OnPlay(wxMediaEvent& event)
{
    mMediaCtrl->Play();

}
