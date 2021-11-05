/**
 * @file SoundStuff.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef UML_WARS_SOUNDSTUFF_H
#define UML_WARS_SOUNDSTUFF_H

#include <wx/sound.h>
#include <wx/mediactrl.h>
#include <wx/window.h>
#include "pch.h"


/**
 *
 * Handle wxMediaCtrl ops for the project
 */
class SoundStuff : public wxMediaCtrl{


public:
    /**
     * constructor
     * @param parent the parent window
     */
    SoundStuff(wxWindow *parent);

private:
    /**
     * The event to catch when the media plays
     * @param event the event to catch
     */
    void OnPlay(wxMediaEvent& event);
    ///wxMediaCtrl member object
    std::unique_ptr<wxMediaCtrl> mMediaCtrl;
    ///wxSound member obeject
    std::unique_ptr<wxSound> mSound;




};

#endif //UML_WARS_SOUNDSTUFF_H
