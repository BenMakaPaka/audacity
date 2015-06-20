/**********************************************************************

  Audacity: A Digital Audio Editor

  SpectrumPrefs.h

  Dominic Mazzoni
  James Crook

**********************************************************************/
/*
  Salvo Ventura
  November 2006

  Added selection box for windowType

  All params are saved in config file.
*/


#ifndef __AUDACITY_SPECTRUM_PREFS__
#define __AUDACITY_SPECTRUM_PREFS__

#include <wx/defs.h>
#include <wx/string.h>
#include <wx/window.h>

#include "../Experimental.h"

#include "PrefsPanel.h"
#include "SpectrogramSettings.h"

class wxTextCtrl;
struct FFTParam;
class ShuttleGui;

class SpectrumPrefs:public PrefsPanel
{
 public:
   SpectrumPrefs(wxWindow * parent);
   virtual ~SpectrumPrefs();
   virtual bool Apply();
   virtual bool Validate();

 private:
   void Populate(int windowSize);
   void PopulatePaddingChoices(int windowSize);
   void PopulateOrExchange(ShuttleGui & S);

   void OnWindowSize(wxCommandEvent &event);
   DECLARE_EVENT_TABLE()

   wxTextCtrl *mMinFreq;
   wxTextCtrl *mMaxFreq;
   wxTextCtrl *mGain;
   wxTextCtrl *mRange;
   wxTextCtrl *mFrequencyGain;

   wxArrayString mSizeChoices;
   wxArrayInt mSizeCodes;

#ifdef EXPERIMENTAL_ZERO_PADDED_SPECTROGRAMS
   int mZeroPaddingChoice;
   wxArrayString mZeroPaddingChoices;
   wxArrayInt mZeroPaddingCodes;
#endif

   wxArrayString mTypeChoices;
   wxArrayInt mTypeCodes;


#ifdef EXPERIMENTAL_FIND_NOTES
   wxTextCtrl *mFindNotesMinA;
   wxTextCtrl *mFindNotesN;
#endif
};

class SpectrumPrefsFactory : public PrefsPanelFactory
{
public:
   virtual PrefsPanel *Create(wxWindow *parent);
};

#endif
