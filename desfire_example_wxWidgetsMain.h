/***************************************************************
 * Name:      desfire_example_wxWidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Bojan Rajkovic (bojan.rajkovic@d-logic.rs)
 * Created:   2019-02-04
 * Copyright: Bojan Rajkovic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef DESFIRE_EXAMPLE_WXWIDGETSMAIN_H
#define DESFIRE_EXAMPLE_WXWIDGETSMAIN_H

//(*Headers(desfire_example_wxWidgetsFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

#include <string>

class desfire_example_wxWidgetsFrame: public wxFrame
{
    public:

        desfire_example_wxWidgetsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~desfire_example_wxWidgetsFrame();

    private:

        std::string as;

        void port_open();
        bool prepare_key(unsigned char aes_key[16]);
        bool prepare_new_key(unsigned char aes_key[16]);
        bool prepare_old_key(unsigned char aes_key[16]);
        bool prepare_int_key(unsigned char aes_key[16]);

        void PRN()
        {
            txtPrintOut->AppendText(as);
            txtPrintOut->AppendText("\n");

        }


        //(*Handlers(desfire_example_wxWidgetsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton13Click(wxCommandEvent& event);
        void OnButton18Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnbtnChangeAESkeyClick(wxCommandEvent& event);
        void OnbtnInternalKeyLockClick(wxCommandEvent& event);
        void OnbtnInternalKeyUnlockClick(wxCommandEvent& event);
        void OnbtnStoreAESKeyIntoReaderClick(wxCommandEvent& event);
        void OnbtnGetCardUIDClick(wxCommandEvent& event);
        void OnbtnMakeApplicationClick(wxCommandEvent& event);
        void OnbtnMakeFileClick(wxCommandEvent& event);
        void OnbtnDeleteApplicationClick(wxCommandEvent& event);
        void OnbtnDeleteFileClick(wxCommandEvent& event);
        void OnbtnGetKeySettingsClick(wxCommandEvent& event);
        void OnbtnChangeKeySettingsClick(wxCommandEvent& event);
        void OnbtnReadValueClick(wxCommandEvent& event);
        void OnbtnIncreaseValueClick(wxCommandEvent& event);
        void OnbtnDecreaseValueClick(wxCommandEvent& event);
        void OnradioSTDSelect(wxCommandEvent& event);
        void OnradioValueSelect(wxCommandEvent& event);
        void OnButton17Click(wxCommandEvent& event);
        void OnbtnGetFreeMemoryClick(wxCommandEvent& event);
        void OnbtnDEStoAESClick(wxCommandEvent& event);
        void OnbtnSetRandomIDClick(wxCommandEvent& event);
        void OnbtnGetBaudRateClick(wxCommandEvent& event);
        void OnbtnSetBaudRateClick(wxCommandEvent& event);
        void OnbtnFileWritingClick(wxCommandEvent& event);
        void OnbtnFileReadingClick(wxCommandEvent& event);
        void OntxtFileSizeOfFileText(wxCommandEvent& event);
        void OnbtnAEStoDESClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(desfire_example_wxWidgetsFrame)
        static const long ID_STATICBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT5;
        static const long ID_CHECKBOX2;
        static const long ID_COMBOBOX2;
        static const long ID_COMBOBOX3;
        static const long ID_STATICBOX2;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT7;
        static const long ID_COMBOBOX4;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_STATICBOX3;
        static const long ID_STATICTEXT9;
        static const long ID_COMBOBOX5;
        static const long ID_STATICTEXT10;
        static const long ID_COMBOBOX6;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT11;
        static const long ID_STATICBOX4;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT14;
        static const long ID_COMBOBOX7;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX5;
        static const long ID_BUTTON8;
        static const long ID_STATICBOX5;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_COMBOBOX8;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON9;
        static const long ID_BUTTON10;
        static const long ID_STATICTEXT17;
        static const long ID_CHECKBOX6;
        static const long ID_CHECKBOX7;
        static const long ID_CHECKBOX8;
        static const long ID_STATICBOX6;
        static const long ID_STATICTEXT18;
        static const long ID_COMBOBOX9;
        static const long ID_STATICTEXT19;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICBOX7;
        static const long ID_STATICTEXT20;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_STATICBOX8;
        static const long ID_STATICTEXT21;
        static const long ID_COMBOBOX10;
        static const long ID_BUTTON13;
        static const long ID_BUTTON14;
        static const long ID_BUTTON15;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT22;
        static const long ID_STATICBOX9;
        static const long ID_BUTTON16;
        static const long ID_BUTTON17;
        static const long ID_BUTTON18;
        static const long ID_BUTTON19;
        static const long ID_BUTTON20;
        static const long ID_COMBOBOX11;
        static const long ID_STATICBOX10;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_BUTTON21;
        static const long ID_BUTTON22;
        static const long ID_STATICTEXT23;
        static const long ID_COMBOBOX12;
        static const long ID_STATICTEXT24;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT25;
        static const long ID_TEXTCTRL11;
        static const long ID_STATICTEXT26;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL13;
        static const long ID_STATICTEXT27;
        static const long ID_COMBOBOX13;
        static const long ID_COMBOBOX14;
        static const long ID_COMBOBOX15;
        static const long ID_COMBOBOX16;
        static const long ID_STATICTEXT28;
        static const long ID_STATICTEXT29;
        static const long ID_STATICTEXT30;
        static const long ID_STATICTEXT31;
        static const long ID_TEXTCTRL14;
        static const long ID_STATICTEXT32;
        static const long ID_TEXTCTRL15;
        static const long ID_CHECKBOX9;
        static const long ID_CHECKBOX10;
        static const long ID_BUTTON23;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(desfire_example_wxWidgetsFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText22;
        wxStaticText* StaticText9;
        wxStaticText* StaticText20;
        wxCheckBox* chkApplicationCreateDeleteWithMasterKey;
        wxTextCtrl* txtKeyOpsOldKey;
        wxButton* btnSetBaudRate;
        wxTextCtrl* txtCardAutAIDBytes;
        wxStaticBox* StaticBox8;
        wxStaticBox* StaticBox5;
        wxButton* btnDecreaseValue;
        wxStaticText* StaticText29;
        wxButton* btnStoreAESKeyIntoReader;
        wxCheckBox* chkApplicationMasterNotChangeable;
        wxButton* btnGetFreeMemory;
        wxButton* btnDeleteFile;
        wxTextCtrl* txtCardAutAESKey;
        wxStaticBox* StaticBox7;
        wxStaticBox* btnFormatCard;
        wxComboBox* cmbFileReadWrite;
        wxStaticText* StaticText13;
        wxComboBox* chkStdFileReadWriteCommMode;
        wxStaticText* StaticText2;
        wxStaticText* StaticText30;
        wxStaticText* StaticText14;
        wxCheckBox* chkLimitedCredit;
        wxButton* btnGetCardUID;
        wxComboBox* cmbCardAutInternalKeyNr;
        wxTextCtrl* txtValueFileOpsValue;
        wxButton* btnDeleteApplication;
        wxCheckBox* chkKeysOpsCreateDeleteWithMasterKeyAuth;
        wxStaticText* StaticText26;
        wxStaticText* StaticText6;
        wxComboBox* cmbFileWriteKey;
        wxComboBox* cmbApplicationMaxKeyNr;
        wxButton* btnGetKeySettings;
        wxCheckBox* chkKeyOpsSettingsNotChangeable;
        wxCheckBox* chkKeysOpsMasterNotChangeable;
        wxStaticText* StaticText19;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxStaticText* StaticText18;
        wxTextCtrl* txtFileLowerLimit;
        wxComboBox* cmbFileChangeKey;
        wxStaticText* StaticText31;
        wxStaticBox* StaticBox6;
        wxStaticText* StaticText1;
        wxTextCtrl* txtStatus;
        wxStaticText* StaticText27;
        wxTextCtrl* txtFileUpperLimit;
        wxStaticText* StaticText3;
        wxStaticBox* StaticBox1;
        wxButton* btnFileWriting;
        wxCheckBox* chkCardAutMasterKeyAuthenticationReq;
        wxButton* btnSetRandomID;
        wxStaticText* StaticText21;
        wxButton* btnInternalKeyUnlock;
        wxStaticText* static_ctrl_status;
        wxButton* btnDEStoAES;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText23;
        wxRadioButton* radioValue;
        wxStaticText* StaticText24;
        wxTextCtrl* txtInternKeysPassword;
        wxButton* btnFileReading;
        wxButton* btnChangeKeySettings;
        wxTextCtrl* txtApplicationAIDBytes;
        wxCheckBox* chkFreeGetValue;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxComboBox* cmbRxSpeed;
        wxComboBox* cmbValueFileOpsCommMode;
        wxStatusBar* StatusBar1;
        wxButton* btnChangeAESkey;
        wxCheckBox* chkInternalKeyUsed;
        wxComboBox* cmbCardAutFileID;
        wxRadioButton* radioSTD;
        wxStaticBox* StaticBox3;
        wxComboBox* cmbKeysOpsAidKeyNr;
        wxStaticText* StaticText28;
        wxComboBox* cmbInternKeysOpsIntKeyNr;
        wxButton* btnReadValue;
        wxButton* btnMakeFile;
        wxButton* Button17;
        wxStaticText* StaticText15;
        wxButton* btnInternalKeyLock;
        wxStaticText* StaticText12;
        wxButton* btnMakeApplication;
        wxButton* btnAEStoDES;
        wxComboBox* cmbFileReadKey;
        wxTextCtrl* txtStdFileReadWriteSizeOfFile;
        wxFileDialog* stdFileWriteDialog;
        wxStaticText* StaticText25;
        wxButton* btnIncreaseValue;
        wxComboBox* cmbFileFileID;
        wxStaticText* StaticText17;
        wxComboBox* cmbCardAutAidKeyNrAuth;
        wxStaticText* StaticText4;
        wxStaticBox* StaticBox10;
        wxTextCtrl* txtFileSizeOfFile;
        wxComboBox* cmbFileCommMode;
        wxCheckBox* chkApplicationSettingsNotChangeable;
        wxTextCtrl* txtInternKeysOpsAESKey;
        wxStaticText* StaticText16;
        wxTimer Timer1;
        wxTextCtrl* txtPrintOut;
        wxButton* btnGetBaudRate;
        wxStaticBox* StaticBox4;
        wxTextCtrl* txtFileValue;
        wxTextCtrl* txtKeyOpsNewKey;
        wxComboBox* cmbTxSpeed;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DESFIRE_EXAMPLE_WXWIDGETSMAIN_H
