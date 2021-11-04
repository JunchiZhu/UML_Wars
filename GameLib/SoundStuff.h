/**
 * @file SoundStuff.h
 * @author matt5
 *
 *
 */

#ifndef UML_WARS_SOUNDSTUFF_H
#define UML_WARS_SOUNDSTUFF_H

#include <wx/sound.h>
#include <wx/mediactrl.h>
#include <wx/window.h>
#include "pch.h"



class SoundStuff : public wxMediaCtrl{


public:

    SoundStuff(wxWindow *parent);






private:
    void OnPlay(wxMediaEvent& event);
    std::unique_ptr<wxMediaCtrl> mMediaCtrl;
    std::unique_ptr<wxSound> mSound;




};

#endif //UML_WARS_SOUNDSTUFF_H
