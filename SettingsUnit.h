//---------------------------------------------------------------------------

#ifndef SettingsUnitH
#define SettingsUnitH

//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>

#include "Storage.h"

//---------------------------------------------------------------------------

class TSettingsForm : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *IgnoreAfterExtensionCheckBox;
	TCheckBox *IgnoreAfterNewCheckBox;
	TCheckBox *IgnoreFadeCheckBox;
	TCheckBox *SuppressFramesCheckBox;
	TCheckBox *CombineSimilarCheckBox;
	TCheckBox *IgnoreShorterThanCheckBox;
	TUpDown *IgnoreShorterThanUpDown;
	TBitBtn *BitBtn1;
	void __fastcall IgnoreShorterThanUpDownClick(TObject *Sender,
		  TUDBtnType Button);
	void __fastcall BitBtn1Click(TObject *Sender);

private:	// User declarations
	TStorage* FStorage;
	void UpdateSeconds(const short Seconds);

public:		// User declarations
	__fastcall TSettingsForm(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TSettingsForm *SettingsForm;

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
